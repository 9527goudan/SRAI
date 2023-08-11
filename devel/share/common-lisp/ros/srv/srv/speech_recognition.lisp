; Auto-generated. Do not edit!


(cl:in-package srv-srv)


;//! \htmlinclude speech_recognition-request.msg.html

(cl:defclass <speech_recognition-request> (roslisp-msg-protocol:ros-message)
  ((WakenUp
    :reader WakenUp
    :initarg :WakenUp
    :type cl:fixnum
    :initform 0))
)

(cl:defclass speech_recognition-request (<speech_recognition-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <speech_recognition-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'speech_recognition-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name srv-srv:<speech_recognition-request> is deprecated: use srv-srv:speech_recognition-request instead.")))

(cl:ensure-generic-function 'WakenUp-val :lambda-list '(m))
(cl:defmethod WakenUp-val ((m <speech_recognition-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader srv-srv:WakenUp-val is deprecated.  Use srv-srv:WakenUp instead.")
  (WakenUp m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <speech_recognition-request>) ostream)
  "Serializes a message object of type '<speech_recognition-request>"
  (cl:let* ((signed (cl:slot-value msg 'WakenUp)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <speech_recognition-request>) istream)
  "Deserializes a message object of type '<speech_recognition-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'WakenUp) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<speech_recognition-request>)))
  "Returns string type for a service object of type '<speech_recognition-request>"
  "srv/speech_recognitionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'speech_recognition-request)))
  "Returns string type for a service object of type 'speech_recognition-request"
  "srv/speech_recognitionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<speech_recognition-request>)))
  "Returns md5sum for a message object of type '<speech_recognition-request>"
  "c05feedf1ccb8f1f38dacceac93906b6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'speech_recognition-request)))
  "Returns md5sum for a message object of type 'speech_recognition-request"
  "c05feedf1ccb8f1f38dacceac93906b6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<speech_recognition-request>)))
  "Returns full string definition for message of type '<speech_recognition-request>"
  (cl:format cl:nil "int8 WakenUp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'speech_recognition-request)))
  "Returns full string definition for message of type 'speech_recognition-request"
  (cl:format cl:nil "int8 WakenUp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <speech_recognition-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <speech_recognition-request>))
  "Converts a ROS message object to a list"
  (cl:list 'speech_recognition-request
    (cl:cons ':WakenUp (WakenUp msg))
))
;//! \htmlinclude speech_recognition-response.msg.html

(cl:defclass <speech_recognition-response> (roslisp-msg-protocol:ros-message)
  ((SpeechRecogition
    :reader SpeechRecogition
    :initarg :SpeechRecogition
    :type cl:fixnum
    :initform 0))
)

(cl:defclass speech_recognition-response (<speech_recognition-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <speech_recognition-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'speech_recognition-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name srv-srv:<speech_recognition-response> is deprecated: use srv-srv:speech_recognition-response instead.")))

(cl:ensure-generic-function 'SpeechRecogition-val :lambda-list '(m))
(cl:defmethod SpeechRecogition-val ((m <speech_recognition-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader srv-srv:SpeechRecogition-val is deprecated.  Use srv-srv:SpeechRecogition instead.")
  (SpeechRecogition m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <speech_recognition-response>) ostream)
  "Serializes a message object of type '<speech_recognition-response>"
  (cl:let* ((signed (cl:slot-value msg 'SpeechRecogition)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <speech_recognition-response>) istream)
  "Deserializes a message object of type '<speech_recognition-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'SpeechRecogition) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<speech_recognition-response>)))
  "Returns string type for a service object of type '<speech_recognition-response>"
  "srv/speech_recognitionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'speech_recognition-response)))
  "Returns string type for a service object of type 'speech_recognition-response"
  "srv/speech_recognitionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<speech_recognition-response>)))
  "Returns md5sum for a message object of type '<speech_recognition-response>"
  "c05feedf1ccb8f1f38dacceac93906b6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'speech_recognition-response)))
  "Returns md5sum for a message object of type 'speech_recognition-response"
  "c05feedf1ccb8f1f38dacceac93906b6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<speech_recognition-response>)))
  "Returns full string definition for message of type '<speech_recognition-response>"
  (cl:format cl:nil "int8 SpeechRecogition~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'speech_recognition-response)))
  "Returns full string definition for message of type 'speech_recognition-response"
  (cl:format cl:nil "int8 SpeechRecogition~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <speech_recognition-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <speech_recognition-response>))
  "Converts a ROS message object to a list"
  (cl:list 'speech_recognition-response
    (cl:cons ':SpeechRecogition (SpeechRecogition msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'speech_recognition)))
  'speech_recognition-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'speech_recognition)))
  'speech_recognition-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'speech_recognition)))
  "Returns string type for a service object of type '<speech_recognition>"
  "srv/speech_recognition")