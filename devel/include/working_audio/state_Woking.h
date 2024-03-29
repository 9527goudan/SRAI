// Generated by gencpp from file working_audio/state_Woking.msg
// DO NOT EDIT!


#ifndef WORKING_AUDIO_MESSAGE_STATE_WOKING_H
#define WORKING_AUDIO_MESSAGE_STATE_WOKING_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace working_audio
{
template <class ContainerAllocator>
struct state_Woking_
{
  typedef state_Woking_<ContainerAllocator> Type;

  state_Woking_()
    : stateworking(0)  {
    }
  state_Woking_(const ContainerAllocator& _alloc)
    : stateworking(0)  {
  (void)_alloc;
    }



   typedef int64_t _stateworking_type;
  _stateworking_type stateworking;





  typedef boost::shared_ptr< ::working_audio::state_Woking_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::working_audio::state_Woking_<ContainerAllocator> const> ConstPtr;

}; // struct state_Woking_

typedef ::working_audio::state_Woking_<std::allocator<void> > state_Woking;

typedef boost::shared_ptr< ::working_audio::state_Woking > state_WokingPtr;
typedef boost::shared_ptr< ::working_audio::state_Woking const> state_WokingConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::working_audio::state_Woking_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::working_audio::state_Woking_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::working_audio::state_Woking_<ContainerAllocator1> & lhs, const ::working_audio::state_Woking_<ContainerAllocator2> & rhs)
{
  return lhs.stateworking == rhs.stateworking;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::working_audio::state_Woking_<ContainerAllocator1> & lhs, const ::working_audio::state_Woking_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace working_audio

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::working_audio::state_Woking_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::working_audio::state_Woking_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::working_audio::state_Woking_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::working_audio::state_Woking_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::working_audio::state_Woking_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::working_audio::state_Woking_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::working_audio::state_Woking_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dc665f7d3e15bf1394666a415605eaf6";
  }

  static const char* value(const ::working_audio::state_Woking_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdc665f7d3e15bf13ULL;
  static const uint64_t static_value2 = 0x94666a415605eaf6ULL;
};

template<class ContainerAllocator>
struct DataType< ::working_audio::state_Woking_<ContainerAllocator> >
{
  static const char* value()
  {
    return "working_audio/state_Woking";
  }

  static const char* value(const ::working_audio::state_Woking_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::working_audio::state_Woking_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 stateworking\n"
;
  }

  static const char* value(const ::working_audio::state_Woking_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::working_audio::state_Woking_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stateworking);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct state_Woking_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::working_audio::state_Woking_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::working_audio::state_Woking_<ContainerAllocator>& v)
  {
    s << indent << "stateworking: ";
    Printer<int64_t>::stream(s, indent + "  ", v.stateworking);
  }
};

} // namespace message_operations
} // namespace ros

#endif // WORKING_AUDIO_MESSAGE_STATE_WOKING_H
