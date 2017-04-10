// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dqlib.proto

#ifndef PROTOBUF_dqlib_2eproto__INCLUDED
#define PROTOBUF_dqlib_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace echo {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_dqlib_2eproto();
void protobuf_InitDefaults_dqlib_2eproto();
void protobuf_AssignDesc_dqlib_2eproto();
void protobuf_ShutdownFile_dqlib_2eproto();

class Matrix;
class MvoAssetAllocationInput;
class MvoAssetAllocationOutput;
class Vector;

enum Matrix_StorageOrder {
  Matrix_StorageOrder_RowMajor = 0,
  Matrix_StorageOrder_ColMajor = 1,
  Matrix_StorageOrder_Matrix_StorageOrder_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Matrix_StorageOrder_Matrix_StorageOrder_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Matrix_StorageOrder_IsValid(int value);
const Matrix_StorageOrder Matrix_StorageOrder_StorageOrder_MIN = Matrix_StorageOrder_RowMajor;
const Matrix_StorageOrder Matrix_StorageOrder_StorageOrder_MAX = Matrix_StorageOrder_ColMajor;
const int Matrix_StorageOrder_StorageOrder_ARRAYSIZE = Matrix_StorageOrder_StorageOrder_MAX + 1;

const ::google::protobuf::EnumDescriptor* Matrix_StorageOrder_descriptor();
inline const ::std::string& Matrix_StorageOrder_Name(Matrix_StorageOrder value) {
  return ::google::protobuf::internal::NameOfEnum(
    Matrix_StorageOrder_descriptor(), value);
}
inline bool Matrix_StorageOrder_Parse(
    const ::std::string& name, Matrix_StorageOrder* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Matrix_StorageOrder>(
    Matrix_StorageOrder_descriptor(), name, value);
}
// ===================================================================

class Vector : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:echo.Vector) */ {
 public:
  Vector();
  virtual ~Vector();

  Vector(const Vector& from);

  inline Vector& operator=(const Vector& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Vector& default_instance();

  static const Vector* internal_default_instance();

  void Swap(Vector* other);

  // implements Message ----------------------------------------------

  inline Vector* New() const { return New(NULL); }

  Vector* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Vector& from);
  void MergeFrom(const Vector& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Vector* other);
  void UnsafeMergeFrom(const Vector& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated double data = 2;
  int data_size() const;
  void clear_data();
  static const int kDataFieldNumber = 2;
  double data(int index) const;
  void set_data(int index, double value);
  void add_data(double value);
  const ::google::protobuf::RepeatedField< double >&
      data() const;
  ::google::protobuf::RepeatedField< double >*
      mutable_data();

  // @@protoc_insertion_point(class_scope:echo.Vector)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< double > data_;
  mutable int _data_cached_byte_size_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_dqlib_2eproto_impl();
  friend void  protobuf_AddDesc_dqlib_2eproto_impl();
  friend void protobuf_AssignDesc_dqlib_2eproto();
  friend void protobuf_ShutdownFile_dqlib_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<Vector> Vector_default_instance_;

// -------------------------------------------------------------------

class Matrix : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:echo.Matrix) */ {
 public:
  Matrix();
  virtual ~Matrix();

  Matrix(const Matrix& from);

  inline Matrix& operator=(const Matrix& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Matrix& default_instance();

  static const Matrix* internal_default_instance();

  void Swap(Matrix* other);

  // implements Message ----------------------------------------------

  inline Matrix* New() const { return New(NULL); }

  Matrix* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Matrix& from);
  void MergeFrom(const Matrix& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Matrix* other);
  void UnsafeMergeFrom(const Matrix& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef Matrix_StorageOrder StorageOrder;
  static const StorageOrder RowMajor =
    Matrix_StorageOrder_RowMajor;
  static const StorageOrder ColMajor =
    Matrix_StorageOrder_ColMajor;
  static inline bool StorageOrder_IsValid(int value) {
    return Matrix_StorageOrder_IsValid(value);
  }
  static const StorageOrder StorageOrder_MIN =
    Matrix_StorageOrder_StorageOrder_MIN;
  static const StorageOrder StorageOrder_MAX =
    Matrix_StorageOrder_StorageOrder_MAX;
  static const int StorageOrder_ARRAYSIZE =
    Matrix_StorageOrder_StorageOrder_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  StorageOrder_descriptor() {
    return Matrix_StorageOrder_descriptor();
  }
  static inline const ::std::string& StorageOrder_Name(StorageOrder value) {
    return Matrix_StorageOrder_Name(value);
  }
  static inline bool StorageOrder_Parse(const ::std::string& name,
      StorageOrder* value) {
    return Matrix_StorageOrder_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional int32 rows = 1;
  void clear_rows();
  static const int kRowsFieldNumber = 1;
  ::google::protobuf::int32 rows() const;
  void set_rows(::google::protobuf::int32 value);

  // optional int32 cols = 2;
  void clear_cols();
  static const int kColsFieldNumber = 2;
  ::google::protobuf::int32 cols() const;
  void set_cols(::google::protobuf::int32 value);

  // repeated double data = 3;
  int data_size() const;
  void clear_data();
  static const int kDataFieldNumber = 3;
  double data(int index) const;
  void set_data(int index, double value);
  void add_data(double value);
  const ::google::protobuf::RepeatedField< double >&
      data() const;
  ::google::protobuf::RepeatedField< double >*
      mutable_data();

  // optional .echo.Matrix.StorageOrder storage_order = 4;
  void clear_storage_order();
  static const int kStorageOrderFieldNumber = 4;
  ::echo::Matrix_StorageOrder storage_order() const;
  void set_storage_order(::echo::Matrix_StorageOrder value);

  // @@protoc_insertion_point(class_scope:echo.Matrix)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< double > data_;
  mutable int _data_cached_byte_size_;
  ::google::protobuf::int32 rows_;
  ::google::protobuf::int32 cols_;
  int storage_order_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_dqlib_2eproto_impl();
  friend void  protobuf_AddDesc_dqlib_2eproto_impl();
  friend void protobuf_AssignDesc_dqlib_2eproto();
  friend void protobuf_ShutdownFile_dqlib_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<Matrix> Matrix_default_instance_;

// -------------------------------------------------------------------

class MvoAssetAllocationInput : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:echo.MvoAssetAllocationInput) */ {
 public:
  MvoAssetAllocationInput();
  virtual ~MvoAssetAllocationInput();

  MvoAssetAllocationInput(const MvoAssetAllocationInput& from);

  inline MvoAssetAllocationInput& operator=(const MvoAssetAllocationInput& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MvoAssetAllocationInput& default_instance();

  static const MvoAssetAllocationInput* internal_default_instance();

  void Swap(MvoAssetAllocationInput* other);

  // implements Message ----------------------------------------------

  inline MvoAssetAllocationInput* New() const { return New(NULL); }

  MvoAssetAllocationInput* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MvoAssetAllocationInput& from);
  void MergeFrom(const MvoAssetAllocationInput& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(MvoAssetAllocationInput* other);
  void UnsafeMergeFrom(const MvoAssetAllocationInput& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .echo.Matrix asset_return = 1;
  bool has_asset_return() const;
  void clear_asset_return();
  static const int kAssetReturnFieldNumber = 1;
  const ::echo::Matrix& asset_return() const;
  ::echo::Matrix* mutable_asset_return();
  ::echo::Matrix* release_asset_return();
  void set_allocated_asset_return(::echo::Matrix* asset_return);

  // optional string strategy = 2;
  void clear_strategy();
  static const int kStrategyFieldNumber = 2;
  const ::std::string& strategy() const;
  void set_strategy(const ::std::string& value);
  void set_strategy(const char* value);
  void set_strategy(const char* value, size_t size);
  ::std::string* mutable_strategy();
  ::std::string* release_strategy();
  void set_allocated_strategy(::std::string* strategy);

  // optional string target_type = 3;
  void clear_target_type();
  static const int kTargetTypeFieldNumber = 3;
  const ::std::string& target_type() const;
  void set_target_type(const ::std::string& value);
  void set_target_type(const char* value);
  void set_target_type(const char* value, size_t size);
  ::std::string* mutable_target_type();
  ::std::string* release_target_type();
  void set_allocated_target_type(::std::string* target_type);

  // optional .echo.Vector lower_bound = 4;
  bool has_lower_bound() const;
  void clear_lower_bound();
  static const int kLowerBoundFieldNumber = 4;
  const ::echo::Vector& lower_bound() const;
  ::echo::Vector* mutable_lower_bound();
  ::echo::Vector* release_lower_bound();
  void set_allocated_lower_bound(::echo::Vector* lower_bound);

  // optional .echo.Vector upper_bound = 5;
  bool has_upper_bound() const;
  void clear_upper_bound();
  static const int kUpperBoundFieldNumber = 5;
  const ::echo::Vector& upper_bound() const;
  ::echo::Vector* mutable_upper_bound();
  ::echo::Vector* release_upper_bound();
  void set_allocated_upper_bound(::echo::Vector* upper_bound);

  // optional double target_value = 6;
  void clear_target_value();
  static const int kTargetValueFieldNumber = 6;
  double target_value() const;
  void set_target_value(double value);

  // optional double annualization_scale = 7;
  void clear_annualization_scale();
  static const int kAnnualizationScaleFieldNumber = 7;
  double annualization_scale() const;
  void set_annualization_scale(double value);

  // optional int32 num_returns_for_mean = 8;
  void clear_num_returns_for_mean();
  static const int kNumReturnsForMeanFieldNumber = 8;
  ::google::protobuf::int32 num_returns_for_mean() const;
  void set_num_returns_for_mean(::google::protobuf::int32 value);

  // optional int32 num_ef_points = 9;
  void clear_num_ef_points();
  static const int kNumEfPointsFieldNumber = 9;
  ::google::protobuf::int32 num_ef_points() const;
  void set_num_ef_points(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:echo.MvoAssetAllocationInput)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr strategy_;
  ::google::protobuf::internal::ArenaStringPtr target_type_;
  ::echo::Matrix* asset_return_;
  ::echo::Vector* lower_bound_;
  ::echo::Vector* upper_bound_;
  double target_value_;
  double annualization_scale_;
  ::google::protobuf::int32 num_returns_for_mean_;
  ::google::protobuf::int32 num_ef_points_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_dqlib_2eproto_impl();
  friend void  protobuf_AddDesc_dqlib_2eproto_impl();
  friend void protobuf_AssignDesc_dqlib_2eproto();
  friend void protobuf_ShutdownFile_dqlib_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<MvoAssetAllocationInput> MvoAssetAllocationInput_default_instance_;

// -------------------------------------------------------------------

class MvoAssetAllocationOutput : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:echo.MvoAssetAllocationOutput) */ {
 public:
  MvoAssetAllocationOutput();
  virtual ~MvoAssetAllocationOutput();

  MvoAssetAllocationOutput(const MvoAssetAllocationOutput& from);

  inline MvoAssetAllocationOutput& operator=(const MvoAssetAllocationOutput& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MvoAssetAllocationOutput& default_instance();

  static const MvoAssetAllocationOutput* internal_default_instance();

  void Swap(MvoAssetAllocationOutput* other);

  // implements Message ----------------------------------------------

  inline MvoAssetAllocationOutput* New() const { return New(NULL); }

  MvoAssetAllocationOutput* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MvoAssetAllocationOutput& from);
  void MergeFrom(const MvoAssetAllocationOutput& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(MvoAssetAllocationOutput* other);
  void UnsafeMergeFrom(const MvoAssetAllocationOutput& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .echo.Vector weights = 1;
  bool has_weights() const;
  void clear_weights();
  static const int kWeightsFieldNumber = 1;
  const ::echo::Vector& weights() const;
  ::echo::Vector* mutable_weights();
  ::echo::Vector* release_weights();
  void set_allocated_weights(::echo::Vector* weights);

  // optional double target_value = 2;
  void clear_target_value();
  static const int kTargetValueFieldNumber = 2;
  double target_value() const;
  void set_target_value(double value);

  // @@protoc_insertion_point(class_scope:echo.MvoAssetAllocationOutput)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::echo::Vector* weights_;
  double target_value_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_dqlib_2eproto_impl();
  friend void  protobuf_AddDesc_dqlib_2eproto_impl();
  friend void protobuf_AssignDesc_dqlib_2eproto();
  friend void protobuf_ShutdownFile_dqlib_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<MvoAssetAllocationOutput> MvoAssetAllocationOutput_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Vector

// repeated double data = 2;
inline int Vector::data_size() const {
  return data_.size();
}
inline void Vector::clear_data() {
  data_.Clear();
}
inline double Vector::data(int index) const {
  // @@protoc_insertion_point(field_get:echo.Vector.data)
  return data_.Get(index);
}
inline void Vector::set_data(int index, double value) {
  data_.Set(index, value);
  // @@protoc_insertion_point(field_set:echo.Vector.data)
}
inline void Vector::add_data(double value) {
  data_.Add(value);
  // @@protoc_insertion_point(field_add:echo.Vector.data)
}
inline const ::google::protobuf::RepeatedField< double >&
Vector::data() const {
  // @@protoc_insertion_point(field_list:echo.Vector.data)
  return data_;
}
inline ::google::protobuf::RepeatedField< double >*
Vector::mutable_data() {
  // @@protoc_insertion_point(field_mutable_list:echo.Vector.data)
  return &data_;
}

inline const Vector* Vector::internal_default_instance() {
  return &Vector_default_instance_.get();
}
// -------------------------------------------------------------------

// Matrix

// optional int32 rows = 1;
inline void Matrix::clear_rows() {
  rows_ = 0;
}
inline ::google::protobuf::int32 Matrix::rows() const {
  // @@protoc_insertion_point(field_get:echo.Matrix.rows)
  return rows_;
}
inline void Matrix::set_rows(::google::protobuf::int32 value) {
  
  rows_ = value;
  // @@protoc_insertion_point(field_set:echo.Matrix.rows)
}

// optional int32 cols = 2;
inline void Matrix::clear_cols() {
  cols_ = 0;
}
inline ::google::protobuf::int32 Matrix::cols() const {
  // @@protoc_insertion_point(field_get:echo.Matrix.cols)
  return cols_;
}
inline void Matrix::set_cols(::google::protobuf::int32 value) {
  
  cols_ = value;
  // @@protoc_insertion_point(field_set:echo.Matrix.cols)
}

// repeated double data = 3;
inline int Matrix::data_size() const {
  return data_.size();
}
inline void Matrix::clear_data() {
  data_.Clear();
}
inline double Matrix::data(int index) const {
  // @@protoc_insertion_point(field_get:echo.Matrix.data)
  return data_.Get(index);
}
inline void Matrix::set_data(int index, double value) {
  data_.Set(index, value);
  // @@protoc_insertion_point(field_set:echo.Matrix.data)
}
inline void Matrix::add_data(double value) {
  data_.Add(value);
  // @@protoc_insertion_point(field_add:echo.Matrix.data)
}
inline const ::google::protobuf::RepeatedField< double >&
Matrix::data() const {
  // @@protoc_insertion_point(field_list:echo.Matrix.data)
  return data_;
}
inline ::google::protobuf::RepeatedField< double >*
Matrix::mutable_data() {
  // @@protoc_insertion_point(field_mutable_list:echo.Matrix.data)
  return &data_;
}

// optional .echo.Matrix.StorageOrder storage_order = 4;
inline void Matrix::clear_storage_order() {
  storage_order_ = 0;
}
inline ::echo::Matrix_StorageOrder Matrix::storage_order() const {
  // @@protoc_insertion_point(field_get:echo.Matrix.storage_order)
  return static_cast< ::echo::Matrix_StorageOrder >(storage_order_);
}
inline void Matrix::set_storage_order(::echo::Matrix_StorageOrder value) {
  
  storage_order_ = value;
  // @@protoc_insertion_point(field_set:echo.Matrix.storage_order)
}

inline const Matrix* Matrix::internal_default_instance() {
  return &Matrix_default_instance_.get();
}
// -------------------------------------------------------------------

// MvoAssetAllocationInput

// optional .echo.Matrix asset_return = 1;
inline bool MvoAssetAllocationInput::has_asset_return() const {
  return this != internal_default_instance() && asset_return_ != NULL;
}
inline void MvoAssetAllocationInput::clear_asset_return() {
  if (GetArenaNoVirtual() == NULL && asset_return_ != NULL) delete asset_return_;
  asset_return_ = NULL;
}
inline const ::echo::Matrix& MvoAssetAllocationInput::asset_return() const {
  // @@protoc_insertion_point(field_get:echo.MvoAssetAllocationInput.asset_return)
  return asset_return_ != NULL ? *asset_return_
                         : *::echo::Matrix::internal_default_instance();
}
inline ::echo::Matrix* MvoAssetAllocationInput::mutable_asset_return() {
  
  if (asset_return_ == NULL) {
    asset_return_ = new ::echo::Matrix;
  }
  // @@protoc_insertion_point(field_mutable:echo.MvoAssetAllocationInput.asset_return)
  return asset_return_;
}
inline ::echo::Matrix* MvoAssetAllocationInput::release_asset_return() {
  // @@protoc_insertion_point(field_release:echo.MvoAssetAllocationInput.asset_return)
  
  ::echo::Matrix* temp = asset_return_;
  asset_return_ = NULL;
  return temp;
}
inline void MvoAssetAllocationInput::set_allocated_asset_return(::echo::Matrix* asset_return) {
  delete asset_return_;
  asset_return_ = asset_return;
  if (asset_return) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:echo.MvoAssetAllocationInput.asset_return)
}

// optional string strategy = 2;
inline void MvoAssetAllocationInput::clear_strategy() {
  strategy_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MvoAssetAllocationInput::strategy() const {
  // @@protoc_insertion_point(field_get:echo.MvoAssetAllocationInput.strategy)
  return strategy_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MvoAssetAllocationInput::set_strategy(const ::std::string& value) {
  
  strategy_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:echo.MvoAssetAllocationInput.strategy)
}
inline void MvoAssetAllocationInput::set_strategy(const char* value) {
  
  strategy_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:echo.MvoAssetAllocationInput.strategy)
}
inline void MvoAssetAllocationInput::set_strategy(const char* value, size_t size) {
  
  strategy_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:echo.MvoAssetAllocationInput.strategy)
}
inline ::std::string* MvoAssetAllocationInput::mutable_strategy() {
  
  // @@protoc_insertion_point(field_mutable:echo.MvoAssetAllocationInput.strategy)
  return strategy_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MvoAssetAllocationInput::release_strategy() {
  // @@protoc_insertion_point(field_release:echo.MvoAssetAllocationInput.strategy)
  
  return strategy_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MvoAssetAllocationInput::set_allocated_strategy(::std::string* strategy) {
  if (strategy != NULL) {
    
  } else {
    
  }
  strategy_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), strategy);
  // @@protoc_insertion_point(field_set_allocated:echo.MvoAssetAllocationInput.strategy)
}

// optional string target_type = 3;
inline void MvoAssetAllocationInput::clear_target_type() {
  target_type_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MvoAssetAllocationInput::target_type() const {
  // @@protoc_insertion_point(field_get:echo.MvoAssetAllocationInput.target_type)
  return target_type_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MvoAssetAllocationInput::set_target_type(const ::std::string& value) {
  
  target_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:echo.MvoAssetAllocationInput.target_type)
}
inline void MvoAssetAllocationInput::set_target_type(const char* value) {
  
  target_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:echo.MvoAssetAllocationInput.target_type)
}
inline void MvoAssetAllocationInput::set_target_type(const char* value, size_t size) {
  
  target_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:echo.MvoAssetAllocationInput.target_type)
}
inline ::std::string* MvoAssetAllocationInput::mutable_target_type() {
  
  // @@protoc_insertion_point(field_mutable:echo.MvoAssetAllocationInput.target_type)
  return target_type_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MvoAssetAllocationInput::release_target_type() {
  // @@protoc_insertion_point(field_release:echo.MvoAssetAllocationInput.target_type)
  
  return target_type_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MvoAssetAllocationInput::set_allocated_target_type(::std::string* target_type) {
  if (target_type != NULL) {
    
  } else {
    
  }
  target_type_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), target_type);
  // @@protoc_insertion_point(field_set_allocated:echo.MvoAssetAllocationInput.target_type)
}

// optional .echo.Vector lower_bound = 4;
inline bool MvoAssetAllocationInput::has_lower_bound() const {
  return this != internal_default_instance() && lower_bound_ != NULL;
}
inline void MvoAssetAllocationInput::clear_lower_bound() {
  if (GetArenaNoVirtual() == NULL && lower_bound_ != NULL) delete lower_bound_;
  lower_bound_ = NULL;
}
inline const ::echo::Vector& MvoAssetAllocationInput::lower_bound() const {
  // @@protoc_insertion_point(field_get:echo.MvoAssetAllocationInput.lower_bound)
  return lower_bound_ != NULL ? *lower_bound_
                         : *::echo::Vector::internal_default_instance();
}
inline ::echo::Vector* MvoAssetAllocationInput::mutable_lower_bound() {
  
  if (lower_bound_ == NULL) {
    lower_bound_ = new ::echo::Vector;
  }
  // @@protoc_insertion_point(field_mutable:echo.MvoAssetAllocationInput.lower_bound)
  return lower_bound_;
}
inline ::echo::Vector* MvoAssetAllocationInput::release_lower_bound() {
  // @@protoc_insertion_point(field_release:echo.MvoAssetAllocationInput.lower_bound)
  
  ::echo::Vector* temp = lower_bound_;
  lower_bound_ = NULL;
  return temp;
}
inline void MvoAssetAllocationInput::set_allocated_lower_bound(::echo::Vector* lower_bound) {
  delete lower_bound_;
  lower_bound_ = lower_bound;
  if (lower_bound) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:echo.MvoAssetAllocationInput.lower_bound)
}

// optional .echo.Vector upper_bound = 5;
inline bool MvoAssetAllocationInput::has_upper_bound() const {
  return this != internal_default_instance() && upper_bound_ != NULL;
}
inline void MvoAssetAllocationInput::clear_upper_bound() {
  if (GetArenaNoVirtual() == NULL && upper_bound_ != NULL) delete upper_bound_;
  upper_bound_ = NULL;
}
inline const ::echo::Vector& MvoAssetAllocationInput::upper_bound() const {
  // @@protoc_insertion_point(field_get:echo.MvoAssetAllocationInput.upper_bound)
  return upper_bound_ != NULL ? *upper_bound_
                         : *::echo::Vector::internal_default_instance();
}
inline ::echo::Vector* MvoAssetAllocationInput::mutable_upper_bound() {
  
  if (upper_bound_ == NULL) {
    upper_bound_ = new ::echo::Vector;
  }
  // @@protoc_insertion_point(field_mutable:echo.MvoAssetAllocationInput.upper_bound)
  return upper_bound_;
}
inline ::echo::Vector* MvoAssetAllocationInput::release_upper_bound() {
  // @@protoc_insertion_point(field_release:echo.MvoAssetAllocationInput.upper_bound)
  
  ::echo::Vector* temp = upper_bound_;
  upper_bound_ = NULL;
  return temp;
}
inline void MvoAssetAllocationInput::set_allocated_upper_bound(::echo::Vector* upper_bound) {
  delete upper_bound_;
  upper_bound_ = upper_bound;
  if (upper_bound) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:echo.MvoAssetAllocationInput.upper_bound)
}

// optional double target_value = 6;
inline void MvoAssetAllocationInput::clear_target_value() {
  target_value_ = 0;
}
inline double MvoAssetAllocationInput::target_value() const {
  // @@protoc_insertion_point(field_get:echo.MvoAssetAllocationInput.target_value)
  return target_value_;
}
inline void MvoAssetAllocationInput::set_target_value(double value) {
  
  target_value_ = value;
  // @@protoc_insertion_point(field_set:echo.MvoAssetAllocationInput.target_value)
}

// optional double annualization_scale = 7;
inline void MvoAssetAllocationInput::clear_annualization_scale() {
  annualization_scale_ = 0;
}
inline double MvoAssetAllocationInput::annualization_scale() const {
  // @@protoc_insertion_point(field_get:echo.MvoAssetAllocationInput.annualization_scale)
  return annualization_scale_;
}
inline void MvoAssetAllocationInput::set_annualization_scale(double value) {
  
  annualization_scale_ = value;
  // @@protoc_insertion_point(field_set:echo.MvoAssetAllocationInput.annualization_scale)
}

// optional int32 num_returns_for_mean = 8;
inline void MvoAssetAllocationInput::clear_num_returns_for_mean() {
  num_returns_for_mean_ = 0;
}
inline ::google::protobuf::int32 MvoAssetAllocationInput::num_returns_for_mean() const {
  // @@protoc_insertion_point(field_get:echo.MvoAssetAllocationInput.num_returns_for_mean)
  return num_returns_for_mean_;
}
inline void MvoAssetAllocationInput::set_num_returns_for_mean(::google::protobuf::int32 value) {
  
  num_returns_for_mean_ = value;
  // @@protoc_insertion_point(field_set:echo.MvoAssetAllocationInput.num_returns_for_mean)
}

// optional int32 num_ef_points = 9;
inline void MvoAssetAllocationInput::clear_num_ef_points() {
  num_ef_points_ = 0;
}
inline ::google::protobuf::int32 MvoAssetAllocationInput::num_ef_points() const {
  // @@protoc_insertion_point(field_get:echo.MvoAssetAllocationInput.num_ef_points)
  return num_ef_points_;
}
inline void MvoAssetAllocationInput::set_num_ef_points(::google::protobuf::int32 value) {
  
  num_ef_points_ = value;
  // @@protoc_insertion_point(field_set:echo.MvoAssetAllocationInput.num_ef_points)
}

inline const MvoAssetAllocationInput* MvoAssetAllocationInput::internal_default_instance() {
  return &MvoAssetAllocationInput_default_instance_.get();
}
// -------------------------------------------------------------------

// MvoAssetAllocationOutput

// optional .echo.Vector weights = 1;
inline bool MvoAssetAllocationOutput::has_weights() const {
  return this != internal_default_instance() && weights_ != NULL;
}
inline void MvoAssetAllocationOutput::clear_weights() {
  if (GetArenaNoVirtual() == NULL && weights_ != NULL) delete weights_;
  weights_ = NULL;
}
inline const ::echo::Vector& MvoAssetAllocationOutput::weights() const {
  // @@protoc_insertion_point(field_get:echo.MvoAssetAllocationOutput.weights)
  return weights_ != NULL ? *weights_
                         : *::echo::Vector::internal_default_instance();
}
inline ::echo::Vector* MvoAssetAllocationOutput::mutable_weights() {
  
  if (weights_ == NULL) {
    weights_ = new ::echo::Vector;
  }
  // @@protoc_insertion_point(field_mutable:echo.MvoAssetAllocationOutput.weights)
  return weights_;
}
inline ::echo::Vector* MvoAssetAllocationOutput::release_weights() {
  // @@protoc_insertion_point(field_release:echo.MvoAssetAllocationOutput.weights)
  
  ::echo::Vector* temp = weights_;
  weights_ = NULL;
  return temp;
}
inline void MvoAssetAllocationOutput::set_allocated_weights(::echo::Vector* weights) {
  delete weights_;
  weights_ = weights;
  if (weights) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:echo.MvoAssetAllocationOutput.weights)
}

// optional double target_value = 2;
inline void MvoAssetAllocationOutput::clear_target_value() {
  target_value_ = 0;
}
inline double MvoAssetAllocationOutput::target_value() const {
  // @@protoc_insertion_point(field_get:echo.MvoAssetAllocationOutput.target_value)
  return target_value_;
}
inline void MvoAssetAllocationOutput::set_target_value(double value) {
  
  target_value_ = value;
  // @@protoc_insertion_point(field_set:echo.MvoAssetAllocationOutput.target_value)
}

inline const MvoAssetAllocationOutput* MvoAssetAllocationOutput::internal_default_instance() {
  return &MvoAssetAllocationOutput_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace echo

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::echo::Matrix_StorageOrder> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::echo::Matrix_StorageOrder>() {
  return ::echo::Matrix_StorageOrder_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_dqlib_2eproto__INCLUDED
