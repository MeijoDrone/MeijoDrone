; Auto-generated. Do not edit!


(cl:in-package sip_scenario-srv)


;//! \htmlinclude LampInput-request.msg.html

(cl:defclass <LampInput-request> (roslisp-msg-protocol:ros-message)
  ((target
    :reader target
    :initarg :target
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass LampInput-request (<LampInput-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LampInput-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LampInput-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sip_scenario-srv:<LampInput-request> is deprecated: use sip_scenario-srv:LampInput-request instead.")))

(cl:ensure-generic-function 'target-val :lambda-list '(m))
(cl:defmethod target-val ((m <LampInput-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sip_scenario-srv:target-val is deprecated.  Use sip_scenario-srv:target instead.")
  (target m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LampInput-request>) ostream)
  "Serializes a message object of type '<LampInput-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'target) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LampInput-request>) istream)
  "Deserializes a message object of type '<LampInput-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'target) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LampInput-request>)))
  "Returns string type for a service object of type '<LampInput-request>"
  "sip_scenario/LampInputRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LampInput-request)))
  "Returns string type for a service object of type 'LampInput-request"
  "sip_scenario/LampInputRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LampInput-request>)))
  "Returns md5sum for a message object of type '<LampInput-request>"
  "585976945ba2a0bae2bfb5564650a375")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LampInput-request)))
  "Returns md5sum for a message object of type 'LampInput-request"
  "585976945ba2a0bae2bfb5564650a375")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LampInput-request>)))
  "Returns full string definition for message of type '<LampInput-request>"
  (cl:format cl:nil "geometry_msgs/Point target~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LampInput-request)))
  "Returns full string definition for message of type 'LampInput-request"
  (cl:format cl:nil "geometry_msgs/Point target~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LampInput-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'target))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LampInput-request>))
  "Converts a ROS message object to a list"
  (cl:list 'LampInput-request
    (cl:cons ':target (target msg))
))
;//! \htmlinclude LampInput-response.msg.html

(cl:defclass <LampInput-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass LampInput-response (<LampInput-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LampInput-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LampInput-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sip_scenario-srv:<LampInput-response> is deprecated: use sip_scenario-srv:LampInput-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <LampInput-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sip_scenario-srv:success-val is deprecated.  Use sip_scenario-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LampInput-response>) ostream)
  "Serializes a message object of type '<LampInput-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LampInput-response>) istream)
  "Deserializes a message object of type '<LampInput-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LampInput-response>)))
  "Returns string type for a service object of type '<LampInput-response>"
  "sip_scenario/LampInputResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LampInput-response)))
  "Returns string type for a service object of type 'LampInput-response"
  "sip_scenario/LampInputResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LampInput-response>)))
  "Returns md5sum for a message object of type '<LampInput-response>"
  "585976945ba2a0bae2bfb5564650a375")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LampInput-response)))
  "Returns md5sum for a message object of type 'LampInput-response"
  "585976945ba2a0bae2bfb5564650a375")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LampInput-response>)))
  "Returns full string definition for message of type '<LampInput-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LampInput-response)))
  "Returns full string definition for message of type 'LampInput-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LampInput-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LampInput-response>))
  "Converts a ROS message object to a list"
  (cl:list 'LampInput-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'LampInput)))
  'LampInput-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'LampInput)))
  'LampInput-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LampInput)))
  "Returns string type for a service object of type '<LampInput>"
  "sip_scenario/LampInput")