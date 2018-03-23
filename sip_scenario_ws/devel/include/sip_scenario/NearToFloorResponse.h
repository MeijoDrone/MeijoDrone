// Generated by gencpp from file sip_scenario/NearToFloorResponse.msg
// DO NOT EDIT!


#ifndef SIP_SCENARIO_MESSAGE_NEARTOFLOORRESPONSE_H
#define SIP_SCENARIO_MESSAGE_NEARTOFLOORRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sip_scenario
{
template <class ContainerAllocator>
struct NearToFloorResponse_
{
  typedef NearToFloorResponse_<ContainerAllocator> Type;

  NearToFloorResponse_()
    : success(false)  {
    }
  NearToFloorResponse_(const ContainerAllocator& _alloc)
    : success(false)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;




  typedef boost::shared_ptr< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> const> ConstPtr;

}; // struct NearToFloorResponse_

typedef ::sip_scenario::NearToFloorResponse_<std::allocator<void> > NearToFloorResponse;

typedef boost::shared_ptr< ::sip_scenario::NearToFloorResponse > NearToFloorResponsePtr;
typedef boost::shared_ptr< ::sip_scenario::NearToFloorResponse const> NearToFloorResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sip_scenario::NearToFloorResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace sip_scenario

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::sip_scenario::NearToFloorResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sip_scenario/NearToFloorResponse";
  }

  static const char* value(const ::sip_scenario::NearToFloorResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n\
\n\
";
  }

  static const char* value(const ::sip_scenario::NearToFloorResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct NearToFloorResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sip_scenario::NearToFloorResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sip_scenario::NearToFloorResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SIP_SCENARIO_MESSAGE_NEARTOFLOORRESPONSE_H
