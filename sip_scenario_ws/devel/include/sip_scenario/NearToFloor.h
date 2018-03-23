// Generated by gencpp from file sip_scenario/NearToFloor.msg
// DO NOT EDIT!


#ifndef SIP_SCENARIO_MESSAGE_NEARTOFLOOR_H
#define SIP_SCENARIO_MESSAGE_NEARTOFLOOR_H

#include <ros/service_traits.h>


#include <sip_scenario/NearToFloorRequest.h>
#include <sip_scenario/NearToFloorResponse.h>


namespace sip_scenario
{

struct NearToFloor
{

typedef NearToFloorRequest Request;
typedef NearToFloorResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct NearToFloor
} // namespace sip_scenario


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::sip_scenario::NearToFloor > {
  static const char* value()
  {
    return "df4b6884ffadda4d31d3c1de4bbcf17e";
  }

  static const char* value(const ::sip_scenario::NearToFloor&) { return value(); }
};

template<>
struct DataType< ::sip_scenario::NearToFloor > {
  static const char* value()
  {
    return "sip_scenario/NearToFloor";
  }

  static const char* value(const ::sip_scenario::NearToFloor&) { return value(); }
};


// service_traits::MD5Sum< ::sip_scenario::NearToFloorRequest> should match 
// service_traits::MD5Sum< ::sip_scenario::NearToFloor > 
template<>
struct MD5Sum< ::sip_scenario::NearToFloorRequest>
{
  static const char* value()
  {
    return MD5Sum< ::sip_scenario::NearToFloor >::value();
  }
  static const char* value(const ::sip_scenario::NearToFloorRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::sip_scenario::NearToFloorRequest> should match 
// service_traits::DataType< ::sip_scenario::NearToFloor > 
template<>
struct DataType< ::sip_scenario::NearToFloorRequest>
{
  static const char* value()
  {
    return DataType< ::sip_scenario::NearToFloor >::value();
  }
  static const char* value(const ::sip_scenario::NearToFloorRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::sip_scenario::NearToFloorResponse> should match 
// service_traits::MD5Sum< ::sip_scenario::NearToFloor > 
template<>
struct MD5Sum< ::sip_scenario::NearToFloorResponse>
{
  static const char* value()
  {
    return MD5Sum< ::sip_scenario::NearToFloor >::value();
  }
  static const char* value(const ::sip_scenario::NearToFloorResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::sip_scenario::NearToFloorResponse> should match 
// service_traits::DataType< ::sip_scenario::NearToFloor > 
template<>
struct DataType< ::sip_scenario::NearToFloorResponse>
{
  static const char* value()
  {
    return DataType< ::sip_scenario::NearToFloor >::value();
  }
  static const char* value(const ::sip_scenario::NearToFloorResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SIP_SCENARIO_MESSAGE_NEARTOFLOOR_H
