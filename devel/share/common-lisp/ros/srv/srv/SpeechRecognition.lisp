; Auto-generated. Do not edit!


(cl:in-package srv-srv)


;//! \htmlinclude SpeechRecognition-request.msg.html

(cl:defclass <SpeechRecognition-request> (roslisp-msg-protocol:ros-message)
  ((WakenUp
    :reader WakenUp
    :initarg :WakenUp
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass SpeechRecognition-request (<SpeechRecognition-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SpeechRecognition-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SpeechRecognition-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name srv-srv:<SpeechRecognition-request> is deprecated: use srv-srv:SpeechRecognition-request instead.")))

(cl:ensure-generic-function 'WakenUp-val :lambda-list '(m))
(cl:defmethod WakenUp-val ((m <SpeechRecognition-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader srv-srv:WakenUp-val is deprecated.  Use srv-srv:WakenUp instead.")
  (WakenUp m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SpeechRecognition-request>) ostream)
  "Serializes a message object of type '<SpeechRecognition-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'WakenUp) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SpeechRecognition-request>) istream)
  "Deserializes a message object of type '<SpeechRecognition-request>"
    (cl:setf (cl:slot-value msg 'WakenUp) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SpeechRecognition-request>)))
  "Returns string type for a service object of type '<SpeechRecognition-request>"
  "srv/SpeechRecognitionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SpeechRecognition-request)))
  "Returns string type for a service object of type 'SpeechRecognition-request"
  "srv/SpeechRecognitionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SpeechRecognition-request>)))
  "Returns md5sum for a message object of type '<SpeechRecognition-request>"
  "f0cb90399b5d115dbbf48f3fc50c1e7a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SpeechRecognition-request)))
  "Returns md5sum for a message object of type 'SpeechRecognition-request"
  "f0cb90399b5d115dbbf48f3fc50c1e7a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SpeechRecognition-request>)))
  "Returns full string definition for message of type '<SpeechRecognition-request>"
  (cl:format cl:nil "bool WakenUp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SpeechRecognition-request)))
  "Returns full string definition for message of type 'SpeechRecognition-request"
  (cl:format cl:nil "bool WakenUp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SpeechRecognition-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SpeechRecognition-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SpeechRecognition-request
    (cl:cons ':WakenUp (WakenUp msg))
))
;//! \htmlinclude SpeechRecognition-response.msg.html

(cl:defclass <SpeechRecognition-response> (roslisp-msg-protocol:ros-message)
  ((SpeechRecogition
    :reader SpeechRecogition
    :initarg :SpeechRecogition
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass SpeechRecognition-response (<SpeechRecognition-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SpeechRecognition-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SpeechRecognition-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name srv-srv:<SpeechRecognition-response> is deprecated: use srv-srv:SpeechRecognition-response instead.")))

(cl:ensure-generic-function 'SpeechRecogition-val :lambda-list '(m))
(cl:defmethod SpeechRecogition-val ((m <SpeechRecognition-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader srv-srv:SpeechRecogition-val is deprecated.  Use srv-srv:SpeechRecogition instead.")
  (SpeechRecogition m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SpeechRecognition-response>) ostream)
  "Serializes a message object of type '<SpeechRecognition-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'SpeechRecogition) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SpeechRecognition-response>) istream)
  "Deserializes a message object of type '<SpeechRecognition-response>"
    (cl:setf (cl:slot-value msg 'SpeechRecogition) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SpeechRecognition-response>)))
  "Returns string type for a service object of type '<SpeechRecognition-response>"
  "srv/SpeechRecognitionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SpeechRecognition-response)))
  "Returns string type for a service object of type 'SpeechRecognition-response"
  "srv/SpeechRecognitionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SpeechRecognition-response>)))
  "Returns md5sum for a message object of type '<SpeechRecognition-response>"
  "f0cb90399b5d115dbbf48f3fc50c1e7a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SpeechRecognition-response)))
  "Returns md5sum for a message object of type 'SpeechRecognition-response"
  "f0cb90399b5d115dbbf48f3fc50c1e7a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SpeechRecognition-response>)))
  "Returns full string definition for message of type '<SpeechRecognition-response>"
  (cl:format cl:nil "bool SpeechRecogition~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SpeechRecognition-response)))
  "Returns full string definition for message of type 'SpeechRecognition-response"
  (cl:format cl:nil "bool SpeechRecogition~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SpeechRecognition-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SpeechRecognition-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SpeechRecognition-response
    (cl:cons ':SpeechRecogition (SpeechRecogition msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SpeechRecognition)))
  'SpeechRecognition-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SpeechRecognition)))
  'SpeechRecognition-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SpeechRecognition)))
  "Returns string type for a service object of type '<SpeechRecognition>"
  "srv/SpeechRecognition")