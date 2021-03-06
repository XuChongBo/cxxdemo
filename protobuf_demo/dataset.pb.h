// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dataset.proto

#ifndef PROTOBUF_dataset_2eproto__INCLUDED
#define PROTOBUF_dataset_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace dataset {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_dataset_2eproto();
void protobuf_AssignDesc_dataset_2eproto();
void protobuf_ShutdownFile_dataset_2eproto();

class Block;
class BlockList;
class ImageEntity;

// ===================================================================

class Block : public ::google::protobuf::Message {
 public:
  Block();
  virtual ~Block();

  Block(const Block& from);

  inline Block& operator=(const Block& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Block& default_instance();

  void Swap(Block* other);

  // implements Message ----------------------------------------------

  Block* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Block& from);
  void MergeFrom(const Block& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 x1 = 1 [default = 0];
  inline bool has_x1() const;
  inline void clear_x1();
  static const int kX1FieldNumber = 1;
  inline ::google::protobuf::int32 x1() const;
  inline void set_x1(::google::protobuf::int32 value);

  // required int32 y1 = 2 [default = 0];
  inline bool has_y1() const;
  inline void clear_y1();
  static const int kY1FieldNumber = 2;
  inline ::google::protobuf::int32 y1() const;
  inline void set_y1(::google::protobuf::int32 value);

  // required int32 x2 = 3 [default = 0];
  inline bool has_x2() const;
  inline void clear_x2();
  static const int kX2FieldNumber = 3;
  inline ::google::protobuf::int32 x2() const;
  inline void set_x2(::google::protobuf::int32 value);

  // required int32 y2 = 4 [default = 0];
  inline bool has_y2() const;
  inline void clear_y2();
  static const int kY2FieldNumber = 4;
  inline ::google::protobuf::int32 y2() const;
  inline void set_y2(::google::protobuf::int32 value);

  // optional string text = 5 [default = ""];
  inline bool has_text() const;
  inline void clear_text();
  static const int kTextFieldNumber = 5;
  inline const ::std::string& text() const;
  inline void set_text(const ::std::string& value);
  inline void set_text(const char* value);
  inline void set_text(const char* value, size_t size);
  inline ::std::string* mutable_text();
  inline ::std::string* release_text();
  inline void set_allocated_text(::std::string* text);

  // @@protoc_insertion_point(class_scope:dataset.Block)
 private:
  inline void set_has_x1();
  inline void clear_has_x1();
  inline void set_has_y1();
  inline void clear_has_y1();
  inline void set_has_x2();
  inline void clear_has_x2();
  inline void set_has_y2();
  inline void clear_has_y2();
  inline void set_has_text();
  inline void clear_has_text();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 x1_;
  ::google::protobuf::int32 y1_;
  ::google::protobuf::int32 x2_;
  ::google::protobuf::int32 y2_;
  ::std::string* text_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_dataset_2eproto();
  friend void protobuf_AssignDesc_dataset_2eproto();
  friend void protobuf_ShutdownFile_dataset_2eproto();

  void InitAsDefaultInstance();
  static Block* default_instance_;
};
// -------------------------------------------------------------------

class BlockList : public ::google::protobuf::Message {
 public:
  BlockList();
  virtual ~BlockList();

  BlockList(const BlockList& from);

  inline BlockList& operator=(const BlockList& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const BlockList& default_instance();

  void Swap(BlockList* other);

  // implements Message ----------------------------------------------

  BlockList* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const BlockList& from);
  void MergeFrom(const BlockList& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .dataset.Block blocks = 1;
  inline int blocks_size() const;
  inline void clear_blocks();
  static const int kBlocksFieldNumber = 1;
  inline const ::dataset::Block& blocks(int index) const;
  inline ::dataset::Block* mutable_blocks(int index);
  inline ::dataset::Block* add_blocks();
  inline const ::google::protobuf::RepeatedPtrField< ::dataset::Block >&
      blocks() const;
  inline ::google::protobuf::RepeatedPtrField< ::dataset::Block >*
      mutable_blocks();

  // @@protoc_insertion_point(class_scope:dataset.BlockList)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::dataset::Block > blocks_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_dataset_2eproto();
  friend void protobuf_AssignDesc_dataset_2eproto();
  friend void protobuf_ShutdownFile_dataset_2eproto();

  void InitAsDefaultInstance();
  static BlockList* default_instance_;
};
// -------------------------------------------------------------------

class ImageEntity : public ::google::protobuf::Message {
 public:
  ImageEntity();
  virtual ~ImageEntity();

  ImageEntity(const ImageEntity& from);

  inline ImageEntity& operator=(const ImageEntity& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ImageEntity& default_instance();

  void Swap(ImageEntity* other);

  // implements Message ----------------------------------------------

  ImageEntity* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ImageEntity& from);
  void MergeFrom(const ImageEntity& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 channels = 1;
  inline bool has_channels() const;
  inline void clear_channels();
  static const int kChannelsFieldNumber = 1;
  inline ::google::protobuf::int32 channels() const;
  inline void set_channels(::google::protobuf::int32 value);

  // required int32 height = 2;
  inline bool has_height() const;
  inline void clear_height();
  static const int kHeightFieldNumber = 2;
  inline ::google::protobuf::int32 height() const;
  inline void set_height(::google::protobuf::int32 value);

  // required int32 width = 3;
  inline bool has_width() const;
  inline void clear_width();
  static const int kWidthFieldNumber = 3;
  inline ::google::protobuf::int32 width() const;
  inline void set_width(::google::protobuf::int32 value);

  // required bytes data = 4;
  inline bool has_data() const;
  inline void clear_data();
  static const int kDataFieldNumber = 4;
  inline const ::std::string& data() const;
  inline void set_data(const ::std::string& value);
  inline void set_data(const char* value);
  inline void set_data(const void* value, size_t size);
  inline ::std::string* mutable_data();
  inline ::std::string* release_data();
  inline void set_allocated_data(::std::string* data);

  // optional string recog_text = 5 [default = ""];
  inline bool has_recog_text() const;
  inline void clear_recog_text();
  static const int kRecogTextFieldNumber = 5;
  inline const ::std::string& recog_text() const;
  inline void set_recog_text(const ::std::string& value);
  inline void set_recog_text(const char* value);
  inline void set_recog_text(const char* value, size_t size);
  inline ::std::string* mutable_recog_text();
  inline ::std::string* release_recog_text();
  inline void set_allocated_recog_text(::std::string* recog_text);

  // optional float score = 6 [default = 0];
  inline bool has_score() const;
  inline void clear_score();
  static const int kScoreFieldNumber = 6;
  inline float score() const;
  inline void set_score(float value);

  // optional string truth_text = 7 [default = ""];
  inline bool has_truth_text() const;
  inline void clear_truth_text();
  static const int kTruthTextFieldNumber = 7;
  inline const ::std::string& truth_text() const;
  inline void set_truth_text(const ::std::string& value);
  inline void set_truth_text(const char* value);
  inline void set_truth_text(const char* value, size_t size);
  inline ::std::string* mutable_truth_text();
  inline ::std::string* release_truth_text();
  inline void set_allocated_truth_text(::std::string* truth_text);

  // @@protoc_insertion_point(class_scope:dataset.ImageEntity)
 private:
  inline void set_has_channels();
  inline void clear_has_channels();
  inline void set_has_height();
  inline void clear_has_height();
  inline void set_has_width();
  inline void clear_has_width();
  inline void set_has_data();
  inline void clear_has_data();
  inline void set_has_recog_text();
  inline void clear_has_recog_text();
  inline void set_has_score();
  inline void clear_has_score();
  inline void set_has_truth_text();
  inline void clear_has_truth_text();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 channels_;
  ::google::protobuf::int32 height_;
  ::std::string* data_;
  ::google::protobuf::int32 width_;
  float score_;
  ::std::string* recog_text_;
  ::std::string* truth_text_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

  friend void  protobuf_AddDesc_dataset_2eproto();
  friend void protobuf_AssignDesc_dataset_2eproto();
  friend void protobuf_ShutdownFile_dataset_2eproto();

  void InitAsDefaultInstance();
  static ImageEntity* default_instance_;
};
// ===================================================================


// ===================================================================

// Block

// required int32 x1 = 1 [default = 0];
inline bool Block::has_x1() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Block::set_has_x1() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Block::clear_has_x1() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Block::clear_x1() {
  x1_ = 0;
  clear_has_x1();
}
inline ::google::protobuf::int32 Block::x1() const {
  return x1_;
}
inline void Block::set_x1(::google::protobuf::int32 value) {
  set_has_x1();
  x1_ = value;
}

// required int32 y1 = 2 [default = 0];
inline bool Block::has_y1() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Block::set_has_y1() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Block::clear_has_y1() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Block::clear_y1() {
  y1_ = 0;
  clear_has_y1();
}
inline ::google::protobuf::int32 Block::y1() const {
  return y1_;
}
inline void Block::set_y1(::google::protobuf::int32 value) {
  set_has_y1();
  y1_ = value;
}

// required int32 x2 = 3 [default = 0];
inline bool Block::has_x2() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Block::set_has_x2() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Block::clear_has_x2() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Block::clear_x2() {
  x2_ = 0;
  clear_has_x2();
}
inline ::google::protobuf::int32 Block::x2() const {
  return x2_;
}
inline void Block::set_x2(::google::protobuf::int32 value) {
  set_has_x2();
  x2_ = value;
}

// required int32 y2 = 4 [default = 0];
inline bool Block::has_y2() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Block::set_has_y2() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Block::clear_has_y2() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Block::clear_y2() {
  y2_ = 0;
  clear_has_y2();
}
inline ::google::protobuf::int32 Block::y2() const {
  return y2_;
}
inline void Block::set_y2(::google::protobuf::int32 value) {
  set_has_y2();
  y2_ = value;
}

// optional string text = 5 [default = ""];
inline bool Block::has_text() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Block::set_has_text() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Block::clear_has_text() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Block::clear_text() {
  if (text_ != &::google::protobuf::internal::kEmptyString) {
    text_->clear();
  }
  clear_has_text();
}
inline const ::std::string& Block::text() const {
  return *text_;
}
inline void Block::set_text(const ::std::string& value) {
  set_has_text();
  if (text_ == &::google::protobuf::internal::kEmptyString) {
    text_ = new ::std::string;
  }
  text_->assign(value);
}
inline void Block::set_text(const char* value) {
  set_has_text();
  if (text_ == &::google::protobuf::internal::kEmptyString) {
    text_ = new ::std::string;
  }
  text_->assign(value);
}
inline void Block::set_text(const char* value, size_t size) {
  set_has_text();
  if (text_ == &::google::protobuf::internal::kEmptyString) {
    text_ = new ::std::string;
  }
  text_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Block::mutable_text() {
  set_has_text();
  if (text_ == &::google::protobuf::internal::kEmptyString) {
    text_ = new ::std::string;
  }
  return text_;
}
inline ::std::string* Block::release_text() {
  clear_has_text();
  if (text_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = text_;
    text_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Block::set_allocated_text(::std::string* text) {
  if (text_ != &::google::protobuf::internal::kEmptyString) {
    delete text_;
  }
  if (text) {
    set_has_text();
    text_ = text;
  } else {
    clear_has_text();
    text_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// BlockList

// repeated .dataset.Block blocks = 1;
inline int BlockList::blocks_size() const {
  return blocks_.size();
}
inline void BlockList::clear_blocks() {
  blocks_.Clear();
}
inline const ::dataset::Block& BlockList::blocks(int index) const {
  return blocks_.Get(index);
}
inline ::dataset::Block* BlockList::mutable_blocks(int index) {
  return blocks_.Mutable(index);
}
inline ::dataset::Block* BlockList::add_blocks() {
  return blocks_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::dataset::Block >&
BlockList::blocks() const {
  return blocks_;
}
inline ::google::protobuf::RepeatedPtrField< ::dataset::Block >*
BlockList::mutable_blocks() {
  return &blocks_;
}

// -------------------------------------------------------------------

// ImageEntity

// required int32 channels = 1;
inline bool ImageEntity::has_channels() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ImageEntity::set_has_channels() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ImageEntity::clear_has_channels() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ImageEntity::clear_channels() {
  channels_ = 0;
  clear_has_channels();
}
inline ::google::protobuf::int32 ImageEntity::channels() const {
  return channels_;
}
inline void ImageEntity::set_channels(::google::protobuf::int32 value) {
  set_has_channels();
  channels_ = value;
}

// required int32 height = 2;
inline bool ImageEntity::has_height() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ImageEntity::set_has_height() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ImageEntity::clear_has_height() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ImageEntity::clear_height() {
  height_ = 0;
  clear_has_height();
}
inline ::google::protobuf::int32 ImageEntity::height() const {
  return height_;
}
inline void ImageEntity::set_height(::google::protobuf::int32 value) {
  set_has_height();
  height_ = value;
}

// required int32 width = 3;
inline bool ImageEntity::has_width() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ImageEntity::set_has_width() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ImageEntity::clear_has_width() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ImageEntity::clear_width() {
  width_ = 0;
  clear_has_width();
}
inline ::google::protobuf::int32 ImageEntity::width() const {
  return width_;
}
inline void ImageEntity::set_width(::google::protobuf::int32 value) {
  set_has_width();
  width_ = value;
}

// required bytes data = 4;
inline bool ImageEntity::has_data() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ImageEntity::set_has_data() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ImageEntity::clear_has_data() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ImageEntity::clear_data() {
  if (data_ != &::google::protobuf::internal::kEmptyString) {
    data_->clear();
  }
  clear_has_data();
}
inline const ::std::string& ImageEntity::data() const {
  return *data_;
}
inline void ImageEntity::set_data(const ::std::string& value) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::kEmptyString) {
    data_ = new ::std::string;
  }
  data_->assign(value);
}
inline void ImageEntity::set_data(const char* value) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::kEmptyString) {
    data_ = new ::std::string;
  }
  data_->assign(value);
}
inline void ImageEntity::set_data(const void* value, size_t size) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::kEmptyString) {
    data_ = new ::std::string;
  }
  data_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ImageEntity::mutable_data() {
  set_has_data();
  if (data_ == &::google::protobuf::internal::kEmptyString) {
    data_ = new ::std::string;
  }
  return data_;
}
inline ::std::string* ImageEntity::release_data() {
  clear_has_data();
  if (data_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = data_;
    data_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void ImageEntity::set_allocated_data(::std::string* data) {
  if (data_ != &::google::protobuf::internal::kEmptyString) {
    delete data_;
  }
  if (data) {
    set_has_data();
    data_ = data;
  } else {
    clear_has_data();
    data_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string recog_text = 5 [default = ""];
inline bool ImageEntity::has_recog_text() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void ImageEntity::set_has_recog_text() {
  _has_bits_[0] |= 0x00000010u;
}
inline void ImageEntity::clear_has_recog_text() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void ImageEntity::clear_recog_text() {
  if (recog_text_ != &::google::protobuf::internal::kEmptyString) {
    recog_text_->clear();
  }
  clear_has_recog_text();
}
inline const ::std::string& ImageEntity::recog_text() const {
  return *recog_text_;
}
inline void ImageEntity::set_recog_text(const ::std::string& value) {
  set_has_recog_text();
  if (recog_text_ == &::google::protobuf::internal::kEmptyString) {
    recog_text_ = new ::std::string;
  }
  recog_text_->assign(value);
}
inline void ImageEntity::set_recog_text(const char* value) {
  set_has_recog_text();
  if (recog_text_ == &::google::protobuf::internal::kEmptyString) {
    recog_text_ = new ::std::string;
  }
  recog_text_->assign(value);
}
inline void ImageEntity::set_recog_text(const char* value, size_t size) {
  set_has_recog_text();
  if (recog_text_ == &::google::protobuf::internal::kEmptyString) {
    recog_text_ = new ::std::string;
  }
  recog_text_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ImageEntity::mutable_recog_text() {
  set_has_recog_text();
  if (recog_text_ == &::google::protobuf::internal::kEmptyString) {
    recog_text_ = new ::std::string;
  }
  return recog_text_;
}
inline ::std::string* ImageEntity::release_recog_text() {
  clear_has_recog_text();
  if (recog_text_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = recog_text_;
    recog_text_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void ImageEntity::set_allocated_recog_text(::std::string* recog_text) {
  if (recog_text_ != &::google::protobuf::internal::kEmptyString) {
    delete recog_text_;
  }
  if (recog_text) {
    set_has_recog_text();
    recog_text_ = recog_text;
  } else {
    clear_has_recog_text();
    recog_text_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional float score = 6 [default = 0];
inline bool ImageEntity::has_score() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void ImageEntity::set_has_score() {
  _has_bits_[0] |= 0x00000020u;
}
inline void ImageEntity::clear_has_score() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void ImageEntity::clear_score() {
  score_ = 0;
  clear_has_score();
}
inline float ImageEntity::score() const {
  return score_;
}
inline void ImageEntity::set_score(float value) {
  set_has_score();
  score_ = value;
}

// optional string truth_text = 7 [default = ""];
inline bool ImageEntity::has_truth_text() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void ImageEntity::set_has_truth_text() {
  _has_bits_[0] |= 0x00000040u;
}
inline void ImageEntity::clear_has_truth_text() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void ImageEntity::clear_truth_text() {
  if (truth_text_ != &::google::protobuf::internal::kEmptyString) {
    truth_text_->clear();
  }
  clear_has_truth_text();
}
inline const ::std::string& ImageEntity::truth_text() const {
  return *truth_text_;
}
inline void ImageEntity::set_truth_text(const ::std::string& value) {
  set_has_truth_text();
  if (truth_text_ == &::google::protobuf::internal::kEmptyString) {
    truth_text_ = new ::std::string;
  }
  truth_text_->assign(value);
}
inline void ImageEntity::set_truth_text(const char* value) {
  set_has_truth_text();
  if (truth_text_ == &::google::protobuf::internal::kEmptyString) {
    truth_text_ = new ::std::string;
  }
  truth_text_->assign(value);
}
inline void ImageEntity::set_truth_text(const char* value, size_t size) {
  set_has_truth_text();
  if (truth_text_ == &::google::protobuf::internal::kEmptyString) {
    truth_text_ = new ::std::string;
  }
  truth_text_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ImageEntity::mutable_truth_text() {
  set_has_truth_text();
  if (truth_text_ == &::google::protobuf::internal::kEmptyString) {
    truth_text_ = new ::std::string;
  }
  return truth_text_;
}
inline ::std::string* ImageEntity::release_truth_text() {
  clear_has_truth_text();
  if (truth_text_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = truth_text_;
    truth_text_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void ImageEntity::set_allocated_truth_text(::std::string* truth_text) {
  if (truth_text_ != &::google::protobuf::internal::kEmptyString) {
    delete truth_text_;
  }
  if (truth_text) {
    set_has_truth_text();
    truth_text_ = truth_text;
  } else {
    clear_has_truth_text();
    truth_text_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace dataset

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_dataset_2eproto__INCLUDED
