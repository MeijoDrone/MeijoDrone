; Auto-generated. Do not edit!


(cl:in-package sip_scenario-srv)


;//! \htmlinclude AccessToFloor-request.msg.html

(cl:defclass <AccessToFloor-request> (roslisp-msg-protocol:ros-message)
  ((force
    :reader force
    :initarg :force
    :type cl:float
    :initform 0.0))
)

(cl:defclass AccessToFloor-request (<AccessToFloor-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AccessToFloor-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AccessToFloor-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sip_scenario-srv:<AccessToFloor-request> is deprecated: use sip_scenario-srv:AccessToFloor-request instead.")))

(cl:ensure-generic-function 'force-val :lambda-list '(m))
(cl:defmethod force-val ((m <AccessToFloor-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sip_scenario-srv:force-val is deprecated.  Use sip_scenario-srv:force instead.")
  (force m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AccessToFloor-request>) ostream)
  "Serializes a message object of type '<AccessToFloor-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'force))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AccessToFloor-request>) istream)
  "Deserializes a message object of type '<AccessToFloor-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'force) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AccessToFloor-request>)))
  "Returns string type for a service object of type '<AccessToFloor-request>"
  "sip_scenario/AccessToFloorRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AccessToFloor-request)))
  "Returns string type for a service object of type 'AccessToFloor-request"
  "sip_scenario/AccessToFloorRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AccessToFloor-request>)))
  "Returns md5sum for a message object of type '<AccessToFloor-request>"
  "80c7dd3d66bf2a99c16e42e7089d1344")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AccessToFloor-request)))
  "Returns md5sum for a message object of type 'AccessToFloor-request"
  "80c7dd3d66bf2a99c16e42e7089d1344")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AccessToFloor-request>)))
  "Returns full string definition for message of type '<AccessToFloor-request>"
  (cl:format cl:nil "float64 force~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AccessToFloor-request)))
  "Returns full string definition for message of type 'AccessToFloor-request"
  (cl:format cl:nil "float64 force~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AccessToFloor-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AccessToFloor-request>))
  "Converts a ROS message object to a list"
  (cl:list 'AccessToFloor-request
    (cl:cons ':force (force msg))
))
;//! \htmlinclude AccessToFloor-response.msg.html

(cl:defclass <AccessToFloor-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass AccessToFloor-response (<AccessToFloor-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AccessToFloor-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AccessToFloor-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sip_scenario-srv:<AccessToFloor-response> is deprecated: use sip_scenario-srv:AccessToFloor-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <AccessToFloor-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sip_scenario-srv:success-val is deprecated.  Use sip_scenario-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AccessToFloor-response>) ostream)
  "Serializes a message object of type '<AccessToFloor-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AccessToFloor-response>) istream)
  "Deserializes a message object of type '<AccessToFloor-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AccessToFloor-response>)))
  "Returns string type for a service object of type '<AccessToFloor-response>"
  "sip_scenario/AccessToFloorResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AccessToFloor-response)))
  "Returns string type for a service object of type 'AccessToFloor-response"
  "sip_scenario/AccessToFloorResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AccessToFloor-response>)))
  "Returns md5sum for a message object of type '<AccessToFloor-response>"
  "80c7dd3d66bf2a99c16e42e7089d1344")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AccessToFloor-response)))
  "Returns md5sum for a message object of type 'AccessToFloor-response"
  "80c7dd3d66bf2a99c16e42e7089d1344")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AccessToFloor-response>)))
  "Returns full string definition for message of type '<AccessToFloor-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AccessToFloor-response)))
  "Returns full string definition for message of type 'AccessToFloor-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AccessToFloor-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AccessToFloor-response>))
  "Converts a ROS message object to a list"
  (cl:list 'AccessToFloor-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'AccessToFloor)))
  'AccessToFloor-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'AccessToFloor)))
  'AccessToFloor-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AccessToFloor)))
  "Returns string type for a service object of type '<AccessToFloor>"
  "sip_scenario/AccessToFloor")