// Generated by gencpp from file sip_scenario/AccessToFloorRequest.msg
// DO NOT EDIT!


#ifndef SIP_SCENARIO_MESSAGE_ACCESSTOFLOORREQUEST_H
#define SIP_SCENARIO_MESSAGE_ACCESSTOFLOORREQUEST_H


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
struct AccessToFloorRequest_
{
  typedef AccessToFloorRequest_<ContainerAllocator> Type;

  AccessToFloorRequest_()
    : force(0.0)  {
    }
  AccessToFloorRequest_(const ContainerAllocator& _alloc)
    : force(0.0)  {
  (void)_alloc;
    }



   typedef double _force_type;
  _force_type force;




  typedef boost::shared_ptr< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> const> ConstPtr;

}; // struct AccessToFloorRequest_

typedef ::sip_scenario::AccessToFloorRequest_<std::allocator<void> > AccessToFloorRequest;

typedef boost::shared_ptr< ::sip_scenario::AccessToFloorRequest > AccessToFloorRequestPtr;
typedef boost::shared_ptr< ::sip_scenario::AccessToFloorRequest const> AccessToFloorRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e18a51329659ac6263f87aaf9a01fe62";
  }

  static const char* value(const ::sip_scenario::AccessToFloorRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe18a51329659ac62ULL;
  static const uint64_t static_value2 = 0x63f87aaf9a01fe62ULL;
};

template<class ContainerAllocator>
struct DataType< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sip_scenario/AccessToFloorRequest";
  }

  static const char* value(const ::sip_scenario::AccessToFloorRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 force\n\
";
  }

  static const char* value(const ::sip_scenario::AccessToFloorRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.force);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AccessToFloorRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sip_scenario::AccessToFloorRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sip_scenario::AccessToFloorRequest_<ContainerAllocator>& v)
  {
    s << indent << "force: ";
    Printer<double>::stream(s, indent + "  ", v.force);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SIP_SCENARIO_MESSAGE_ACCESSTOFLOORREQUEST_H
