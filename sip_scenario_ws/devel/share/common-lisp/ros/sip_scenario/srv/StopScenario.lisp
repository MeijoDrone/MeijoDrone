; Auto-generated. Do not edit!


(cl:in-package sip_scenario-srv)


;//! \htmlinclude StopScenario-request.msg.html

(cl:defclass <StopScenario-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass StopScenario-request (<StopScenario-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StopScenario-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StopScenario-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sip_scenario-srv:<StopScenario-request> is deprecated: use sip_scenario-srv:StopScenario-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StopScenario-request>) ostream)
  "Serializes a message object of type '<StopScenario-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StopScenario-request>) istream)
  "Deserializes a message object of type '<StopScenario-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StopScenario-request>)))
  "Returns string type for a service object of type '<StopScenario-request>"
  "sip_scenario/StopScenarioRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StopScenario-request)))
  "Returns string type for a service object of type 'StopScenario-request"
  "sip_scenario/StopScenarioRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StopScenario-request>)))
  "Returns md5sum for a message object of type '<StopScenario-request>"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StopScenario-request)))
  "Returns md5sum for a message object of type 'StopScenario-request"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StopScenario-request>)))
  "Returns full string definition for message of type '<StopScenario-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StopScenario-request)))
  "Returns full string definition for message of type 'StopScenario-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StopScenario-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StopScenario-request>))
  "Converts a ROS message object to a list"
  (cl:list 'StopScenario-request
))
;//! \htmlinclude StopScenario-response.msg.html

(cl:defclass <StopScenario-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass StopScenario-response (<StopScenario-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StopScenario-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StopScenario-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sip_scenario-srv:<StopScenario-response> is deprecated: use sip_scenario-srv:StopScenario-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <StopScenario-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sip_scenario-srv:success-val is deprecated.  Use sip_scenario-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StopScenario-response>) ostream)
  "Serializes a message object of type '<StopScenario-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StopScenario-response>) istream)
  "Deserializes a message object of type '<StopScenario-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StopScenario-response>)))
  "Returns string type for a service object of type '<StopScenario-response>"
  "sip_scenario/StopScenarioResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StopScenario-response)))
  "Returns string type for a service object of type 'StopScenario-response"
  "sip_scenario/StopScenarioResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StopScenario-response>)))
  "Returns md5sum for a message object of type '<StopScenario-response>"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StopScenario-response)))
  "Returns md5sum for a message object of type 'StopScenario-response"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StopScenario-response>)))
  "Returns full string definition for message of type '<StopScenario-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StopScenario-response)))
  "Returns full string definition for message of type 'StopScenario-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StopScenario-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StopScenario-response>))
  "Converts a ROS message object to a list"
  (cl:list 'StopScenario-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'StopScenario)))
  'StopScenario-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'StopScenario)))
  'StopScenario-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StopScenario)))
  "Returns string type for a service object of type '<StopScenario>"
  "sip_scenario/StopScenario")