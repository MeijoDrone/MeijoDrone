// Generated by gencpp from file sip_scenario/NearToFloorRequest.msg
// DO NOT EDIT!


#ifndef SIP_SCENARIO_MESSAGE_NEARTOFLOORREQUEST_H
#define SIP_SCENARIO_MESSAGE_NEARTOFLOORREQUEST_H


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
struct NearToFloorRequest_
{
  typedef NearToFloorRequest_<ContainerAllocator> Type;

  NearToFloorRequest_()
    : distance(0.0)  {
    }
  NearToFloorRequest_(const ContainerAllocator& _alloc)
    : distance(0.0)  {
  (void)_alloc;
    }



   typedef double _distance_type;
  _distance_type distance;




  typedef boost::shared_ptr< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> const> ConstPtr;

}; // struct NearToFloorRequest_

typedef ::sip_scenario::NearToFloorRequest_<std::allocator<void> > NearToFloorRequest;

typedef boost::shared_ptr< ::sip_scenario::NearToFloorRequest > NearToFloorRequestPtr;
typedef boost::shared_ptr< ::sip_scenario::NearToFloorRequest const> NearToFloorRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sip_scenario::NearToFloorRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "acff7fda0c683c872875f5c4b069f124";
  }

  static const char* value(const ::sip_scenario::NearToFloorRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xacff7fda0c683c87ULL;
  static const uint64_t static_value2 = 0x2875f5c4b069f124ULL;
};

template<class ContainerAllocator>
struct DataType< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sip_scenario/NearToFloorRequest";
  }

  static const char* value(const ::sip_scenario::NearToFloorRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 distance\n\
";
  }

  static const char* value(const ::sip_scenario::NearToFloorRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct NearToFloorRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sip_scenario::NearToFloorRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sip_scenario::NearToFloorRequest_<ContainerAllocator>& v)
  {
    s << indent << "distance: ";
    Printer<double>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SIP_SCENARIO_MESSAGE_NEARTOFLOORREQUEST_H
