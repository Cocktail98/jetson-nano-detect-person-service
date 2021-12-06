// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: detect.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_detect_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_detect_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/timestamp.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_detect_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_detect_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_detect_2eproto;
namespace Detect {
class BoxRect;
struct BoxRectDefaultTypeInternal;
extern BoxRectDefaultTypeInternal _BoxRect_default_instance_;
class CameraRect;
struct CameraRectDefaultTypeInternal;
extern CameraRectDefaultTypeInternal _CameraRect_default_instance_;
class DetectRequest;
struct DetectRequestDefaultTypeInternal;
extern DetectRequestDefaultTypeInternal _DetectRequest_default_instance_;
class DetectResponse;
struct DetectResponseDefaultTypeInternal;
extern DetectResponseDefaultTypeInternal _DetectResponse_default_instance_;
}  // namespace Detect
PROTOBUF_NAMESPACE_OPEN
template<> ::Detect::BoxRect* Arena::CreateMaybeMessage<::Detect::BoxRect>(Arena*);
template<> ::Detect::CameraRect* Arena::CreateMaybeMessage<::Detect::CameraRect>(Arena*);
template<> ::Detect::DetectRequest* Arena::CreateMaybeMessage<::Detect::DetectRequest>(Arena*);
template<> ::Detect::DetectResponse* Arena::CreateMaybeMessage<::Detect::DetectResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Detect {

// ===================================================================

class BoxRect final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Detect.BoxRect) */ {
 public:
  inline BoxRect() : BoxRect(nullptr) {}
  ~BoxRect() override;
  explicit constexpr BoxRect(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  BoxRect(const BoxRect& from);
  BoxRect(BoxRect&& from) noexcept
    : BoxRect() {
    *this = ::std::move(from);
  }

  inline BoxRect& operator=(const BoxRect& from) {
    CopyFrom(from);
    return *this;
  }
  inline BoxRect& operator=(BoxRect&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const BoxRect& default_instance() {
    return *internal_default_instance();
  }
  static inline const BoxRect* internal_default_instance() {
    return reinterpret_cast<const BoxRect*>(
               &_BoxRect_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(BoxRect& a, BoxRect& b) {
    a.Swap(&b);
  }
  inline void Swap(BoxRect* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(BoxRect* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline BoxRect* New() const final {
    return new BoxRect();
  }

  BoxRect* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<BoxRect>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const BoxRect& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const BoxRect& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BoxRect* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Detect.BoxRect";
  }
  protected:
  explicit BoxRect(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
    kWidthFieldNumber = 3,
    kHeightFieldNumber = 4,
    kClassIdFieldNumber = 5,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // double width = 3;
  void clear_width();
  double width() const;
  void set_width(double value);
  private:
  double _internal_width() const;
  void _internal_set_width(double value);
  public:

  // double height = 4;
  void clear_height();
  double height() const;
  void set_height(double value);
  private:
  double _internal_height() const;
  void _internal_set_height(double value);
  public:

  // int64 class_id = 5;
  void clear_class_id();
  ::PROTOBUF_NAMESPACE_ID::int64 class_id() const;
  void set_class_id(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_class_id() const;
  void _internal_set_class_id(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // @@protoc_insertion_point(class_scope:Detect.BoxRect)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double x_;
  double y_;
  double width_;
  double height_;
  ::PROTOBUF_NAMESPACE_ID::int64 class_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_detect_2eproto;
};
// -------------------------------------------------------------------

class CameraRect final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Detect.CameraRect) */ {
 public:
  inline CameraRect() : CameraRect(nullptr) {}
  ~CameraRect() override;
  explicit constexpr CameraRect(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  CameraRect(const CameraRect& from);
  CameraRect(CameraRect&& from) noexcept
    : CameraRect() {
    *this = ::std::move(from);
  }

  inline CameraRect& operator=(const CameraRect& from) {
    CopyFrom(from);
    return *this;
  }
  inline CameraRect& operator=(CameraRect&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const CameraRect& default_instance() {
    return *internal_default_instance();
  }
  static inline const CameraRect* internal_default_instance() {
    return reinterpret_cast<const CameraRect*>(
               &_CameraRect_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(CameraRect& a, CameraRect& b) {
    a.Swap(&b);
  }
  inline void Swap(CameraRect* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(CameraRect* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline CameraRect* New() const final {
    return new CameraRect();
  }

  CameraRect* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<CameraRect>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const CameraRect& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const CameraRect& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(CameraRect* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Detect.CameraRect";
  }
  protected:
  explicit CameraRect(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBoxRectFieldNumber = 2,
    kCameraIdFieldNumber = 1,
  };
  // repeated .Detect.BoxRect box_rect = 2;
  int box_rect_size() const;
  private:
  int _internal_box_rect_size() const;
  public:
  void clear_box_rect();
  ::Detect::BoxRect* mutable_box_rect(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Detect::BoxRect >*
      mutable_box_rect();
  private:
  const ::Detect::BoxRect& _internal_box_rect(int index) const;
  ::Detect::BoxRect* _internal_add_box_rect();
  public:
  const ::Detect::BoxRect& box_rect(int index) const;
  ::Detect::BoxRect* add_box_rect();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Detect::BoxRect >&
      box_rect() const;

  // int64 camera_id = 1;
  void clear_camera_id();
  ::PROTOBUF_NAMESPACE_ID::int64 camera_id() const;
  void set_camera_id(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_camera_id() const;
  void _internal_set_camera_id(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // @@protoc_insertion_point(class_scope:Detect.CameraRect)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Detect::BoxRect > box_rect_;
  ::PROTOBUF_NAMESPACE_ID::int64 camera_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_detect_2eproto;
};
// -------------------------------------------------------------------

class DetectRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Detect.DetectRequest) */ {
 public:
  inline DetectRequest() : DetectRequest(nullptr) {}
  ~DetectRequest() override;
  explicit constexpr DetectRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  DetectRequest(const DetectRequest& from);
  DetectRequest(DetectRequest&& from) noexcept
    : DetectRequest() {
    *this = ::std::move(from);
  }

  inline DetectRequest& operator=(const DetectRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline DetectRequest& operator=(DetectRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const DetectRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const DetectRequest* internal_default_instance() {
    return reinterpret_cast<const DetectRequest*>(
               &_DetectRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(DetectRequest& a, DetectRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(DetectRequest* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(DetectRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline DetectRequest* New() const final {
    return new DetectRequest();
  }

  DetectRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<DetectRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const DetectRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const DetectRequest& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DetectRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Detect.DetectRequest";
  }
  protected:
  explicit DetectRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStatusFieldNumber = 1,
  };
  // bool status = 1;
  void clear_status();
  bool status() const;
  void set_status(bool value);
  private:
  bool _internal_status() const;
  void _internal_set_status(bool value);
  public:

  // @@protoc_insertion_point(class_scope:Detect.DetectRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  bool status_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_detect_2eproto;
};
// -------------------------------------------------------------------

class DetectResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Detect.DetectResponse) */ {
 public:
  inline DetectResponse() : DetectResponse(nullptr) {}
  ~DetectResponse() override;
  explicit constexpr DetectResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  DetectResponse(const DetectResponse& from);
  DetectResponse(DetectResponse&& from) noexcept
    : DetectResponse() {
    *this = ::std::move(from);
  }

  inline DetectResponse& operator=(const DetectResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline DetectResponse& operator=(DetectResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const DetectResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const DetectResponse* internal_default_instance() {
    return reinterpret_cast<const DetectResponse*>(
               &_DetectResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(DetectResponse& a, DetectResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(DetectResponse* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(DetectResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline DetectResponse* New() const final {
    return new DetectResponse();
  }

  DetectResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<DetectResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const DetectResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const DetectResponse& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DetectResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Detect.DetectResponse";
  }
  protected:
  explicit DetectResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kCameraRectFieldNumber = 2,
    kRespTimestampFieldNumber = 3,
    kStatusFieldNumber = 1,
  };
  // repeated .Detect.CameraRect camera_rect = 2;
  int camera_rect_size() const;
  private:
  int _internal_camera_rect_size() const;
  public:
  void clear_camera_rect();
  ::Detect::CameraRect* mutable_camera_rect(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Detect::CameraRect >*
      mutable_camera_rect();
  private:
  const ::Detect::CameraRect& _internal_camera_rect(int index) const;
  ::Detect::CameraRect* _internal_add_camera_rect();
  public:
  const ::Detect::CameraRect& camera_rect(int index) const;
  ::Detect::CameraRect* add_camera_rect();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Detect::CameraRect >&
      camera_rect() const;

  // .google.protobuf.Timestamp resp_timestamp = 3;
  bool has_resp_timestamp() const;
  private:
  bool _internal_has_resp_timestamp() const;
  public:
  void clear_resp_timestamp();
  const PROTOBUF_NAMESPACE_ID::Timestamp& resp_timestamp() const;
  PROTOBUF_MUST_USE_RESULT PROTOBUF_NAMESPACE_ID::Timestamp* release_resp_timestamp();
  PROTOBUF_NAMESPACE_ID::Timestamp* mutable_resp_timestamp();
  void set_allocated_resp_timestamp(PROTOBUF_NAMESPACE_ID::Timestamp* resp_timestamp);
  private:
  const PROTOBUF_NAMESPACE_ID::Timestamp& _internal_resp_timestamp() const;
  PROTOBUF_NAMESPACE_ID::Timestamp* _internal_mutable_resp_timestamp();
  public:
  void unsafe_arena_set_allocated_resp_timestamp(
      PROTOBUF_NAMESPACE_ID::Timestamp* resp_timestamp);
  PROTOBUF_NAMESPACE_ID::Timestamp* unsafe_arena_release_resp_timestamp();

  // bool status = 1;
  void clear_status();
  bool status() const;
  void set_status(bool value);
  private:
  bool _internal_status() const;
  void _internal_set_status(bool value);
  public:

  // @@protoc_insertion_point(class_scope:Detect.DetectResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Detect::CameraRect > camera_rect_;
  PROTOBUF_NAMESPACE_ID::Timestamp* resp_timestamp_;
  bool status_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_detect_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BoxRect

// double x = 1;
inline void BoxRect::clear_x() {
  x_ = 0;
}
inline double BoxRect::_internal_x() const {
  return x_;
}
inline double BoxRect::x() const {
  // @@protoc_insertion_point(field_get:Detect.BoxRect.x)
  return _internal_x();
}
inline void BoxRect::_internal_set_x(double value) {
  
  x_ = value;
}
inline void BoxRect::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:Detect.BoxRect.x)
}

// double y = 2;
inline void BoxRect::clear_y() {
  y_ = 0;
}
inline double BoxRect::_internal_y() const {
  return y_;
}
inline double BoxRect::y() const {
  // @@protoc_insertion_point(field_get:Detect.BoxRect.y)
  return _internal_y();
}
inline void BoxRect::_internal_set_y(double value) {
  
  y_ = value;
}
inline void BoxRect::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:Detect.BoxRect.y)
}

// double width = 3;
inline void BoxRect::clear_width() {
  width_ = 0;
}
inline double BoxRect::_internal_width() const {
  return width_;
}
inline double BoxRect::width() const {
  // @@protoc_insertion_point(field_get:Detect.BoxRect.width)
  return _internal_width();
}
inline void BoxRect::_internal_set_width(double value) {
  
  width_ = value;
}
inline void BoxRect::set_width(double value) {
  _internal_set_width(value);
  // @@protoc_insertion_point(field_set:Detect.BoxRect.width)
}

// double height = 4;
inline void BoxRect::clear_height() {
  height_ = 0;
}
inline double BoxRect::_internal_height() const {
  return height_;
}
inline double BoxRect::height() const {
  // @@protoc_insertion_point(field_get:Detect.BoxRect.height)
  return _internal_height();
}
inline void BoxRect::_internal_set_height(double value) {
  
  height_ = value;
}
inline void BoxRect::set_height(double value) {
  _internal_set_height(value);
  // @@protoc_insertion_point(field_set:Detect.BoxRect.height)
}

// int64 class_id = 5;
inline void BoxRect::clear_class_id() {
  class_id_ = int64_t{0};
}
inline ::PROTOBUF_NAMESPACE_ID::int64 BoxRect::_internal_class_id() const {
  return class_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 BoxRect::class_id() const {
  // @@protoc_insertion_point(field_get:Detect.BoxRect.class_id)
  return _internal_class_id();
}
inline void BoxRect::_internal_set_class_id(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  class_id_ = value;
}
inline void BoxRect::set_class_id(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_class_id(value);
  // @@protoc_insertion_point(field_set:Detect.BoxRect.class_id)
}

// -------------------------------------------------------------------

// CameraRect

// int64 camera_id = 1;
inline void CameraRect::clear_camera_id() {
  camera_id_ = int64_t{0};
}
inline ::PROTOBUF_NAMESPACE_ID::int64 CameraRect::_internal_camera_id() const {
  return camera_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 CameraRect::camera_id() const {
  // @@protoc_insertion_point(field_get:Detect.CameraRect.camera_id)
  return _internal_camera_id();
}
inline void CameraRect::_internal_set_camera_id(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  camera_id_ = value;
}
inline void CameraRect::set_camera_id(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_camera_id(value);
  // @@protoc_insertion_point(field_set:Detect.CameraRect.camera_id)
}

// repeated .Detect.BoxRect box_rect = 2;
inline int CameraRect::_internal_box_rect_size() const {
  return box_rect_.size();
}
inline int CameraRect::box_rect_size() const {
  return _internal_box_rect_size();
}
inline void CameraRect::clear_box_rect() {
  box_rect_.Clear();
}
inline ::Detect::BoxRect* CameraRect::mutable_box_rect(int index) {
  // @@protoc_insertion_point(field_mutable:Detect.CameraRect.box_rect)
  return box_rect_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Detect::BoxRect >*
CameraRect::mutable_box_rect() {
  // @@protoc_insertion_point(field_mutable_list:Detect.CameraRect.box_rect)
  return &box_rect_;
}
inline const ::Detect::BoxRect& CameraRect::_internal_box_rect(int index) const {
  return box_rect_.Get(index);
}
inline const ::Detect::BoxRect& CameraRect::box_rect(int index) const {
  // @@protoc_insertion_point(field_get:Detect.CameraRect.box_rect)
  return _internal_box_rect(index);
}
inline ::Detect::BoxRect* CameraRect::_internal_add_box_rect() {
  return box_rect_.Add();
}
inline ::Detect::BoxRect* CameraRect::add_box_rect() {
  ::Detect::BoxRect* _add = _internal_add_box_rect();
  // @@protoc_insertion_point(field_add:Detect.CameraRect.box_rect)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Detect::BoxRect >&
CameraRect::box_rect() const {
  // @@protoc_insertion_point(field_list:Detect.CameraRect.box_rect)
  return box_rect_;
}

// -------------------------------------------------------------------

// DetectRequest

// bool status = 1;
inline void DetectRequest::clear_status() {
  status_ = false;
}
inline bool DetectRequest::_internal_status() const {
  return status_;
}
inline bool DetectRequest::status() const {
  // @@protoc_insertion_point(field_get:Detect.DetectRequest.status)
  return _internal_status();
}
inline void DetectRequest::_internal_set_status(bool value) {
  
  status_ = value;
}
inline void DetectRequest::set_status(bool value) {
  _internal_set_status(value);
  // @@protoc_insertion_point(field_set:Detect.DetectRequest.status)
}

// -------------------------------------------------------------------

// DetectResponse

// bool status = 1;
inline void DetectResponse::clear_status() {
  status_ = false;
}
inline bool DetectResponse::_internal_status() const {
  return status_;
}
inline bool DetectResponse::status() const {
  // @@protoc_insertion_point(field_get:Detect.DetectResponse.status)
  return _internal_status();
}
inline void DetectResponse::_internal_set_status(bool value) {
  
  status_ = value;
}
inline void DetectResponse::set_status(bool value) {
  _internal_set_status(value);
  // @@protoc_insertion_point(field_set:Detect.DetectResponse.status)
}

// repeated .Detect.CameraRect camera_rect = 2;
inline int DetectResponse::_internal_camera_rect_size() const {
  return camera_rect_.size();
}
inline int DetectResponse::camera_rect_size() const {
  return _internal_camera_rect_size();
}
inline void DetectResponse::clear_camera_rect() {
  camera_rect_.Clear();
}
inline ::Detect::CameraRect* DetectResponse::mutable_camera_rect(int index) {
  // @@protoc_insertion_point(field_mutable:Detect.DetectResponse.camera_rect)
  return camera_rect_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Detect::CameraRect >*
DetectResponse::mutable_camera_rect() {
  // @@protoc_insertion_point(field_mutable_list:Detect.DetectResponse.camera_rect)
  return &camera_rect_;
}
inline const ::Detect::CameraRect& DetectResponse::_internal_camera_rect(int index) const {
  return camera_rect_.Get(index);
}
inline const ::Detect::CameraRect& DetectResponse::camera_rect(int index) const {
  // @@protoc_insertion_point(field_get:Detect.DetectResponse.camera_rect)
  return _internal_camera_rect(index);
}
inline ::Detect::CameraRect* DetectResponse::_internal_add_camera_rect() {
  return camera_rect_.Add();
}
inline ::Detect::CameraRect* DetectResponse::add_camera_rect() {
  ::Detect::CameraRect* _add = _internal_add_camera_rect();
  // @@protoc_insertion_point(field_add:Detect.DetectResponse.camera_rect)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Detect::CameraRect >&
DetectResponse::camera_rect() const {
  // @@protoc_insertion_point(field_list:Detect.DetectResponse.camera_rect)
  return camera_rect_;
}

// .google.protobuf.Timestamp resp_timestamp = 3;
inline bool DetectResponse::_internal_has_resp_timestamp() const {
  return this != internal_default_instance() && resp_timestamp_ != nullptr;
}
inline bool DetectResponse::has_resp_timestamp() const {
  return _internal_has_resp_timestamp();
}
inline const PROTOBUF_NAMESPACE_ID::Timestamp& DetectResponse::_internal_resp_timestamp() const {
  const PROTOBUF_NAMESPACE_ID::Timestamp* p = resp_timestamp_;
  return p != nullptr ? *p : reinterpret_cast<const PROTOBUF_NAMESPACE_ID::Timestamp&>(
      PROTOBUF_NAMESPACE_ID::_Timestamp_default_instance_);
}
inline const PROTOBUF_NAMESPACE_ID::Timestamp& DetectResponse::resp_timestamp() const {
  // @@protoc_insertion_point(field_get:Detect.DetectResponse.resp_timestamp)
  return _internal_resp_timestamp();
}
inline void DetectResponse::unsafe_arena_set_allocated_resp_timestamp(
    PROTOBUF_NAMESPACE_ID::Timestamp* resp_timestamp) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(resp_timestamp_);
  }
  resp_timestamp_ = resp_timestamp;
  if (resp_timestamp) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Detect.DetectResponse.resp_timestamp)
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* DetectResponse::release_resp_timestamp() {
  
  PROTOBUF_NAMESPACE_ID::Timestamp* temp = resp_timestamp_;
  resp_timestamp_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* DetectResponse::unsafe_arena_release_resp_timestamp() {
  // @@protoc_insertion_point(field_release:Detect.DetectResponse.resp_timestamp)
  
  PROTOBUF_NAMESPACE_ID::Timestamp* temp = resp_timestamp_;
  resp_timestamp_ = nullptr;
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* DetectResponse::_internal_mutable_resp_timestamp() {
  
  if (resp_timestamp_ == nullptr) {
    auto* p = CreateMaybeMessage<PROTOBUF_NAMESPACE_ID::Timestamp>(GetArenaForAllocation());
    resp_timestamp_ = p;
  }
  return resp_timestamp_;
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* DetectResponse::mutable_resp_timestamp() {
  PROTOBUF_NAMESPACE_ID::Timestamp* _msg = _internal_mutable_resp_timestamp();
  // @@protoc_insertion_point(field_mutable:Detect.DetectResponse.resp_timestamp)
  return _msg;
}
inline void DetectResponse::set_allocated_resp_timestamp(PROTOBUF_NAMESPACE_ID::Timestamp* resp_timestamp) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(resp_timestamp_);
  }
  if (resp_timestamp) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(resp_timestamp));
    if (message_arena != submessage_arena) {
      resp_timestamp = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, resp_timestamp, submessage_arena);
    }
    
  } else {
    
  }
  resp_timestamp_ = resp_timestamp;
  // @@protoc_insertion_point(field_set_allocated:Detect.DetectResponse.resp_timestamp)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Detect

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_detect_2eproto
