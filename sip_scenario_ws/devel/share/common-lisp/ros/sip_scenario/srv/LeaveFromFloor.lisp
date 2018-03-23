; Auto-generated. Do not edit!


(cl:in-package sip_scenario-srv)


;//! \htmlinclude LeaveFromFloor-request.msg.html

(cl:defclass <LeaveFromFloor-request> (roslisp-msg-protocol:ros-message)
  ((distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass LeaveFromFloor-request (<LeaveFromFloor-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LeaveFromFloor-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LeaveFromFloor-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sip_scenario-srv:<LeaveFromFloor-request> is deprecated: use sip_scenario-srv:LeaveFromFloor-request instead.")))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <LeaveFromFloor-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sip_scenario-srv:distance-val is deprecated.  Use sip_scenario-srv:distance instead.")
  (distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LeaveFromFloor-request>) ostream)
  "Serializes a message object of type '<LeaveFromFloor-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LeaveFromFloor-request>) istream)
  "Deserializes a message object of type '<LeaveFromFloor-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LeaveFromFloor-request>)))
  "Returns string type for a service object of type '<LeaveFromFloor-request>"
  "sip_scenario/LeaveFromFloorRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LeaveFromFloor-request)))
  "Returns string type for a service object of type 'LeaveFromFloor-request"
  "sip_scenario/LeaveFromFloorRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LeaveFromFloor-request>)))
  "Returns md5sum for a message object of type '<LeaveFromFloor-request>"
  "df4b6884ffadda4d31d3c1de4bbcf17e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LeaveFromFloor-request)))
  "Returns md5sum for a message object of type 'LeaveFromFloor-request"
  "df4b6884ffadda4d31d3c1de4bbcf17e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LeaveFromFloor-request>)))
  "Returns full string definition for message of type '<LeaveFromFloor-request>"
  (cl:format cl:nil "float64 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LeaveFromFloor-request)))
  "Returns full string definition for message of type 'LeaveFromFloor-request"
  (cl:format cl:nil "float64 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LeaveFromFloor-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LeaveFromFloor-request>))
  "Converts a ROS message object to a list"
  (cl:list 'LeaveFromFloor-request
    (cl:cons ':distance (distance msg))
))
;//! \htmlinclude LeaveFromFloor-response.msg.html

(cl:defclass <LeaveFromFloor-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass LeaveFromFloor-response (<LeaveFromFloor-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LeaveFromFloor-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LeaveFromFloor-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sip_scenario-srv:<LeaveFromFloor-response> is deprecated: use sip_scenario-srv:LeaveFromFloor-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <LeaveFromFloor-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sip_scenario-srv:success-val is deprecated.  Use sip_scenario-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LeaveFromFloor-response>) ostream)
  "Serializes a message object of type '<LeaveFromFloor-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LeaveFromFloor-response>) istream)
  "Deserializes a message object of type '<LeaveFromFloor-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LeaveFromFloor-response>)))
  "Returns string type for a service object of type '<LeaveFromFloor-response>"
  "sip_scenario/LeaveFromFloorResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LeaveFromFloor-response)))
  "Returns string type for a service object of type 'LeaveFromFloor-response"
  "sip_scenario/LeaveFromFloorResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LeaveFromFloor-response>)))
  "Returns md5sum for a message object of type '<LeaveFromFloor-response>"
  "df4b6884ffadda4d31d3c1de4bbcf17e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LeaveFromFloor-response)))
  "Returns md5sum for a message object of type 'LeaveFromFloor-response"
  "df4b6884ffadda4d31d3c1de4bbcf17e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LeaveFromFloor-response>)))
  "Returns full string definition for message of type '<LeaveFromFloor-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LeaveFromFloor-response)))
  "Returns full string definition for message of type 'LeaveFromFloor-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LeaveFromFloor-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LeaveFromFloor-response>))
  "Converts a ROS message object to a list"
  (cl:list 'LeaveFromFloor-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'LeaveFromFloor)))
  'LeaveFromFloor-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'LeaveFromFloor)))
  'LeaveFromFloor-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LeaveFromFloor)))
  "Returns string type for a service object of type '<LeaveFromFloor>"
  "sip_scenario/LeaveFromFloor")