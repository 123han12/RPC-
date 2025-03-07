// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protocol.proto

#include "protocol.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace RpcProtocol {
class RequestHeaderDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<RequestHeader> _instance;
} _RequestHeader_default_instance_;
}  // namespace RpcProtocol
static void InitDefaultsscc_info_RequestHeader_protocol_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::RpcProtocol::_RequestHeader_default_instance_;
    new (ptr) ::RpcProtocol::RequestHeader();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::RpcProtocol::RequestHeader::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_RequestHeader_protocol_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_RequestHeader_protocol_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_protocol_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_protocol_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_protocol_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_protocol_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::RpcProtocol::RequestHeader, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::RpcProtocol::RequestHeader, servicename_),
  PROTOBUF_FIELD_OFFSET(::RpcProtocol::RequestHeader, methodname_),
  PROTOBUF_FIELD_OFFSET(::RpcProtocol::RequestHeader, argsize_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::RpcProtocol::RequestHeader)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::RpcProtocol::_RequestHeader_default_instance_),
};

const char descriptor_table_protodef_protocol_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016protocol.proto\022\013RpcProtocol\"I\n\rRequest"
  "Header\022\023\n\013servicename\030\001 \001(\014\022\022\n\nmethodnam"
  "e\030\002 \001(\014\022\017\n\007argsize\030\003 \001(\005b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_protocol_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_protocol_2eproto_sccs[1] = {
  &scc_info_RequestHeader_protocol_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_protocol_2eproto_once;
static bool descriptor_table_protocol_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_protocol_2eproto = {
  &descriptor_table_protocol_2eproto_initialized, descriptor_table_protodef_protocol_2eproto, "protocol.proto", 112,
  &descriptor_table_protocol_2eproto_once, descriptor_table_protocol_2eproto_sccs, descriptor_table_protocol_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_protocol_2eproto::offsets,
  file_level_metadata_protocol_2eproto, 1, file_level_enum_descriptors_protocol_2eproto, file_level_service_descriptors_protocol_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_protocol_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_protocol_2eproto), true);
namespace RpcProtocol {

// ===================================================================

void RequestHeader::InitAsDefaultInstance() {
}
class RequestHeader::_Internal {
 public:
};

RequestHeader::RequestHeader()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:RpcProtocol.RequestHeader)
}
RequestHeader::RequestHeader(const RequestHeader& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  servicename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_servicename().empty()) {
    servicename_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.servicename_);
  }
  methodname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_methodname().empty()) {
    methodname_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.methodname_);
  }
  argsize_ = from.argsize_;
  // @@protoc_insertion_point(copy_constructor:RpcProtocol.RequestHeader)
}

void RequestHeader::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_RequestHeader_protocol_2eproto.base);
  servicename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  methodname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  argsize_ = 0;
}

RequestHeader::~RequestHeader() {
  // @@protoc_insertion_point(destructor:RpcProtocol.RequestHeader)
  SharedDtor();
}

void RequestHeader::SharedDtor() {
  servicename_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  methodname_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void RequestHeader::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const RequestHeader& RequestHeader::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_RequestHeader_protocol_2eproto.base);
  return *internal_default_instance();
}


void RequestHeader::Clear() {
// @@protoc_insertion_point(message_clear_start:RpcProtocol.RequestHeader)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  servicename_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  methodname_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  argsize_ = 0;
  _internal_metadata_.Clear();
}

const char* RequestHeader::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bytes servicename = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_servicename();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes methodname = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_methodname();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 argsize = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          argsize_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RequestHeader::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:RpcProtocol.RequestHeader)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes servicename = 1;
  if (this->servicename().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_servicename(), target);
  }

  // bytes methodname = 2;
  if (this->methodname().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_methodname(), target);
  }

  // int32 argsize = 3;
  if (this->argsize() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_argsize(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:RpcProtocol.RequestHeader)
  return target;
}

size_t RequestHeader::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:RpcProtocol.RequestHeader)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes servicename = 1;
  if (this->servicename().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_servicename());
  }

  // bytes methodname = 2;
  if (this->methodname().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_methodname());
  }

  // int32 argsize = 3;
  if (this->argsize() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_argsize());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RequestHeader::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:RpcProtocol.RequestHeader)
  GOOGLE_DCHECK_NE(&from, this);
  const RequestHeader* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<RequestHeader>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:RpcProtocol.RequestHeader)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:RpcProtocol.RequestHeader)
    MergeFrom(*source);
  }
}

void RequestHeader::MergeFrom(const RequestHeader& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:RpcProtocol.RequestHeader)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.servicename().size() > 0) {

    servicename_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.servicename_);
  }
  if (from.methodname().size() > 0) {

    methodname_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.methodname_);
  }
  if (from.argsize() != 0) {
    _internal_set_argsize(from._internal_argsize());
  }
}

void RequestHeader::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:RpcProtocol.RequestHeader)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RequestHeader::CopyFrom(const RequestHeader& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:RpcProtocol.RequestHeader)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RequestHeader::IsInitialized() const {
  return true;
}

void RequestHeader::InternalSwap(RequestHeader* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  servicename_.Swap(&other->servicename_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  methodname_.Swap(&other->methodname_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(argsize_, other->argsize_);
}

::PROTOBUF_NAMESPACE_ID::Metadata RequestHeader::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace RpcProtocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::RpcProtocol::RequestHeader* Arena::CreateMaybeMessage< ::RpcProtocol::RequestHeader >(Arena* arena) {
  return Arena::CreateInternal< ::RpcProtocol::RequestHeader >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
