; Auto-generated. Do not edit!


(cl:in-package sip_scenario-srv)


;//! \htmlinclude NearToFloor-request.msg.html

(cl:defclass <NearToFloor-request> (roslisp-msg-protocol:ros-message)
  ((distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass NearToFloor-request (<NearToFloor-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NearToFloor-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NearToFloor-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sip_scenario-srv:<NearToFloor-request> is deprecated: use sip_scenario-srv:NearToFloor-request instead.")))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <NearToFloor-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sip_scenario-srv:distance-val is deprecated.  Use sip_scenario-srv:distance instead.")
  (distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NearToFloor-request>) ostream)
  "Serializes a message object of type '<NearToFloor-request>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NearToFloor-request>) istream)
  "Deserializes a message object of type '<NearToFloor-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NearToFloor-request>)))
  "Returns string type for a service object of type '<NearToFloor-request>"
  "sip_scenario/NearToFloorRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NearToFloor-request)))
  "Returns string type for a service object of type 'NearToFloor-request"
  "sip_scenario/NearToFloorRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NearToFloor-request>)))
  "Returns md5sum for a message object of type '<NearToFloor-request>"
  "df4b6884ffadda4d31d3c1de4bbcf17e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NearToFloor-request)))
  "Returns md5sum for a message object of type 'NearToFloor-request"
  "df4b6884ffadda4d31d3c1de4bbcf17e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NearToFloor-request>)))
  "Returns full string definition for message of type '<NearToFloor-request>"
  (cl:format cl:nil "float64 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NearToFloor-request)))
  "Returns full string definition for message of type 'NearToFloor-request"
  (cl:format cl:nil "float64 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NearToFloor-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NearToFloor-request>))
  "Converts a ROS message object to a list"
  (cl:list 'NearToFloor-request
    (cl:cons ':distance (distance msg))
))
;//! \htmlinclude NearToFloor-response.msg.html

(cl:defclass <NearToFloor-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass NearToFloor-response (<NearToFloor-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NearToFloor-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NearToFloor-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sip_scenario-srv:<NearToFloor-response> is deprecated: use sip_scenario-srv:NearToFloor-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <NearToFloor-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sip_scenario-srv:success-val is deprecated.  Use sip_scenario-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NearToFloor-response>) ostream)
  "Serializes a message object of type '<NearToFloor-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NearToFloor-response>) istream)
  "Deserializes a message object of type '<NearToFloor-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NearToFloor-response>)))
  "Returns string type for a service object of type '<NearToFloor-response>"
  "sip_scenario/NearToFloorResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NearToFloor-response)))
  "Returns string type for a service object of type 'NearToFloor-response"
  "sip_scenario/NearToFloorResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NearToFloor-response>)))
  "Returns md5sum for a message object of type '<NearToFloor-response>"
  "df4b6884ffadda4d31d3c1de4bbcf17e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NearToFloor-response)))
  "Returns md5sum for a message object of type 'NearToFloor-response"
  "df4b6884ffadda4d31d3c1de4bbcf17e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NearToFloor-response>)))
  "Returns full string definition for message of type '<NearToFloor-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NearToFloor-response)))
  "Returns full string definition for message of type 'NearToFloor-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NearToFloor-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NearToFloor-response>))
  "Converts a ROS message object to a list"
  (cl:list 'NearToFloor-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'NearToFloor)))
  'NearToFloor-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'NearToFloor)))
  'NearToFloor-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NearToFloor)))
  "Returns string type for a service object of type '<NearToFloor>"
  "sip_scenario/NearToFloor")