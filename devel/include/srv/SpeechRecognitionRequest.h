// Generated by gencpp from file srv/SpeechRecognitionRequest.msg
// DO NOT EDIT!


#ifndef SRV_MESSAGE_SPEECHRECOGNITIONREQUEST_H
#define SRV_MESSAGE_SPEECHRECOGNITIONREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace srv
{
template <class ContainerAllocator>
struct SpeechRecognitionRequest_
{
  typedef SpeechRecognitionRequest_<ContainerAllocator> Type;

  SpeechRecognitionRequest_()
    : WakenUp(false)  {
    }
  SpeechRecognitionRequest_(const ContainerAllocator& _alloc)
    : WakenUp(false)  {
  (void)_alloc;
    }



   typedef uint8_t _WakenUp_type;
  _WakenUp_type WakenUp;





  typedef boost::shared_ptr< ::srv::SpeechRecognitionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::srv::SpeechRecognitionRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SpeechRecognitionRequest_

typedef ::srv::SpeechRecognitionRequest_<std::allocator<void> > SpeechRecognitionRequest;

typedef boost::shared_ptr< ::srv::SpeechRecognitionRequest > SpeechRecognitionRequestPtr;
typedef boost::shared_ptr< ::srv::SpeechRecognitionRequest const> SpeechRecognitionRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::srv::SpeechRecognitionRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::srv::SpeechRecognitionRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::srv::SpeechRecognitionRequest_<ContainerAllocator1> & lhs, const ::srv::SpeechRecognitionRequest_<ContainerAllocator2> & rhs)
{
  return lhs.WakenUp == rhs.WakenUp;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::srv::SpeechRecognitionRequest_<ContainerAllocator1> & lhs, const ::srv::SpeechRecognitionRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace srv

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::srv::SpeechRecognitionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::srv::SpeechRecognitionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::srv::SpeechRecognitionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::srv::SpeechRecognitionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::srv::SpeechRecognitionRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::srv::SpeechRecognitionRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::srv::SpeechRecognitionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6fced7e0db87647133531483e2687b25";
  }

  static const char* value(const ::srv::SpeechRecognitionRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6fced7e0db876471ULL;
  static const uint64_t static_value2 = 0x33531483e2687b25ULL;
};

template<class ContainerAllocator>
struct DataType< ::srv::SpeechRecognitionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "srv/SpeechRecognitionRequest";
  }

  static const char* value(const ::srv::SpeechRecognitionRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::srv::SpeechRecognitionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool WakenUp\n"
;
  }

  static const char* value(const ::srv::SpeechRecognitionRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::srv::SpeechRecognitionRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.WakenUp);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SpeechRecognitionRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::srv::SpeechRecognitionRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::srv::SpeechRecognitionRequest_<ContainerAllocator>& v)
  {
    s << indent << "WakenUp: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.WakenUp);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SRV_MESSAGE_SPEECHRECOGNITIONREQUEST_H
