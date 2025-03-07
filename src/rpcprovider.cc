#include "rpcprovider.h"
#include "rpcapplication.h"
#include "protocol.pb.h"
#include "rpcserverlog.h"
#include "rpczookeeperutil.h"
#include "rpcredisutil.h" 
#include "rpckeepalive.h"
#include <vector>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/stubs/callback.h>
    
void RpcProvider::RegisterService(::google::protobuf::Service* service ) {
    ServiceInfo info ; 
    const ::google::protobuf::ServiceDescriptor* servicedsc = service->GetDescriptor() ; 
    info.servicePtr = service ; 
    std::string serviceName = servicedsc->name() ; 
    int method_count = servicedsc->method_count() ; 
    LOG_INFO("register service: %s" , INFO , serviceName.c_str() ) ; 

    for(int i = 0 ; i < method_count ; i ++ ) {
        const ::google::protobuf::MethodDescriptor* methoddsc = servicedsc->method(i) ; 
        std::string MethodName = methoddsc->name() ; 
        info.MethodMap[MethodName] = methoddsc ;

        LOG_INFO("  service's method: %s" , INFO , MethodName.c_str() ) ;  
    }
    
    ServiceMap[serviceName] = info ; 
}   


// 启动muduo网络库的事件监听和日志系统
void RpcProvider::Run() {

    std::pair<std::string , int> rpcServerInfo = RpcApplication::GetInstance().GetRpcServerInfo() ; 
    std::string ip = rpcServerInfo.first ; 
    int port = rpcServerInfo.second ; 

    // 向 zookeeper注册服务
    // ZkClient zkclient ; 
    // zkclient.Start() ; // 连接客户端
    // std::string data = ip + ":" + std::to_string(port) ; 

    // for(auto &sp : ServiceMap ) {
    //     std::string servicename = sp.first ; 
    //     std::string path = "/" ; 
    //     path += servicename ; 
    //     zkclient.Create(path.c_str() , nullptr , 0 ) ;  // 创建服务节点
    //     for(auto &ssp : sp.second.MethodMap ) {
    //         std::string methodname = ssp.first ; 
    //         std::string methodpath = path + "/" + methodname ; 
    //         zkclient.Create(methodpath.c_str() , data.c_str() , data.size()  , ZOO_EPHEMERAL ) ;  // 表示创建的是临时性节点。
    //     }
    // }

    // 向redis 注册服务
    Redis redis ; 
    // 连接 redis服务器
    redis.Connect() ; 

    // 注册服务地址
    std::string address = ip + ":" + std::to_string(port) ; 
    std::vector<std::string> service_container ; 
    for(auto &sp : ServiceMap ) {
        std::string servicename = sp.first ; 
        service_container.push_back(servicename) ; 
        for(auto &ssp : sp.second.MethodMap ) {
            std::string methodname = ssp.first ; 
            redis.RegisterRpcAddress(servicename , methodname , address ) ; 
        }
    }

    //开启心跳机制
    std::string key = RpcApplication::GetInstance().GetKeepAliveKey() ; 
    // 将当前rpc节点所注册的服务名字都 给到子进程
    KeepAlive alive(key , service_container ) ;   
    alive.start() ; 


    muduo::net::EventLoop loop ; 
    muduo::net::InetAddress addr(ip , port ) ; 
    muduo::net::TcpServer Server(&loop , addr , "RpcServer") ; 
     
    // 设置事件回调函数
    Server.setConnectionCallback(std::bind(&RpcProvider::onConnection , this , std::placeholders::_1 ) ) ;  
    Server.setMessageCallback(std::bind(&RpcProvider::onMessage , this , std::placeholders::_1 , 
    std::placeholders::_2 , std::placeholders::_3)) ;  

    Server.setThreadNum(8) ; // 设置线程的个数

    // 开启muduo网络库的监听
    LOG_INFO("begin event loop........" , INFO) ; 
    Server.start() ; 
    loop.loop() ; 
}


void RpcProvider::onConnection(const muduo::net::TcpConnectionPtr& conn )  {
    if(conn->connected() ) {
        LOG_INFO("accepted new connection: %s" , INFO , conn->peerAddress().toIpPort().c_str() ) ; 
    }else {
        LOG_INFO("close connection: %s" , INFO , conn->peerAddress().toIpPort().c_str() ) ;    
    }
}

// 接受到的二进制的数据就在这里
void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr& conn , muduo::net::Buffer* buffer , muduo::Timestamp ) {
    std::string message = buffer->retrieveAllAsString() ; // 取出接受到的数据
    
    std::string headsize_str = message.substr(0 , 4 ) ; 
    int headsize = *( (int*)headsize_str.c_str() ) ; //获取头部的大小

    std::string headerstr = message.substr(4 , headsize) ; 

    RpcProtocol::RequestHeader header ; 
    if(header.ParseFromString(headerstr) ) {
        std::cout << "parse request header sucess!" << std::endl ;  
    } else {
        std::cout << "parse request header error" << std::endl ; 
        exit(EXIT_FAILURE) ; 
    }
    std::string serviceName , methodName ; 
    int argsSize = 0 ;

    serviceName = header.servicename() ; 
    methodName = header.methodname() ; 
    argsSize = header.argsize() ; 

    std::cout << "Service Name: " << serviceName << std::endl ; 
    std::cout << "Method Name: " << methodName << std::endl ; 
    std::cout << "args Size: " << argsSize << std::endl ; 
    
    // 参数的序列化值。
    std::string args = message.substr(4 + headsize , message.size() - 4 - headsize ) ; 

    std::cout << "search Service and method" << std::endl ;  
    // 在这里调用对应的方法
    if(ServiceMap.find(serviceName ) == ServiceMap.end() ) {
        std::cout << "not found service: " << serviceName << std::endl ; 
        return ; 
    } 
    
    ServiceInfo info = ServiceMap[serviceName] ; 
    google::protobuf::Service* service ;  
    service = ServiceMap[serviceName].servicePtr ; 

    if(info.MethodMap.find(methodName) == info.MethodMap.end() ) {
        std::cout << "not found service: " << serviceName << std::endl ; 
        return ;
    }
    const google::protobuf::MethodDescriptor* methodDescriptor = info.MethodMap[methodName] ; 


    // 创建指定方法的参数类型
    google::protobuf::Message* request = service->GetRequestPrototype(methodDescriptor).New() ; 
    google::protobuf::Message* response = service->GetResponsePrototype(methodDescriptor).New() ; 

    if( !request->ParseFromString(args) )  {
        std::cout << "args error" << std::endl ; 
        return ; 
    }

    google::protobuf::Closure* done = google::protobuf::NewCallback<RpcProvider ,
    const muduo::net::TcpConnectionPtr& , google::protobuf::Message*>(
        this, &RpcProvider::SendRpcRepsonse , conn , response) ; 

    // 调用服务的函数接口获取返回值; 

    std::cout << "begin call method" << std::endl ; 
    service->CallMethod(methodDescriptor , nullptr , request , response , done ) ; 

    // 日志中输出是哪个客户端对哪个服务进行的调用
    LOG_INFO("client:%s call service %s method %s" , INFO , conn->peerAddress().toIpPort().c_str() , 
        service->GetDescriptor()->name().c_str() , methodDescriptor->name().c_str() 
    ) ; 

}

void RpcProvider::SendRpcRepsonse(const muduo::net::TcpConnectionPtr& conn , google::protobuf::Message* message ) {
    
    std::string messagestr ; 
    if(message->SerializeToString(&messagestr) ) {
        std::cout << "serialize sucess!....." << std::endl ; 
    }else {
        std::cout << "serialize failed....." << std::endl ; 
        exit(EXIT_FAILURE) ; 
    }
    
    // 通过 TcpConnectionPtr指针对其进行发送
    conn->send(messagestr) ; 
    LOG_INFO("send called data to client:%s " , INFO , conn->peerAddress().toIpPort().c_str() ) ;  

    conn->shutdown() ;  // 服务器主动关闭这条Tcp连接

}