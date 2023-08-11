; Auto-generated. Do not edit!


(cl:in-package working_audio-msg)


;//! \htmlinclude state_Woking.msg.html

(cl:defclass <state_Woking> (roslisp-msg-protocol:ros-message)
  ((stateworking
    :reader stateworking
    :initarg :stateworking
    :type cl:integer
    :initform 0))
)

(cl:defclass state_Woking (<state_Woking>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <state_Woking>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'state_Woking)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name working_audio-msg:<state_Woking> is deprecated: use working_audio-msg:state_Woking instead.")))

(cl:ensure-generic-function 'stateworking-val :lambda-list '(m))
(cl:defmethod stateworking-val ((m <state_Woking>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader working_audio-msg:stateworking-val is deprecated.  Use working_audio-msg:stateworking instead.")
  (stateworking m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <state_Woking>) ostream)
  "Serializes a message object of type '<state_Woking>"
  (cl:let* ((signed (cl:slot-value msg 'stateworking)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <state_Woking>) istream)
  "Deserializes a message object of type '<state_Woking>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stateworking) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<state_Woking>)))
  "Returns string type for a message object of type '<state_Woking>"
  "working_audio/state_Woking")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'state_Woking)))
  "Returns string type for a message object of type 'state_Woking"
  "working_audio/state_Woking")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<state_Woking>)))
  "Returns md5sum for a message object of type '<state_Woking>"
  "dc665f7d3e15bf1394666a415605eaf6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'state_Woking)))
  "Returns md5sum for a message object of type 'state_Woking"
  "dc665f7d3e15bf1394666a415605eaf6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<state_Woking>)))
  "Returns full string definition for message of type '<state_Woking>"
  (cl:format cl:nil "int64 stateworking~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'state_Woking)))
  "Returns full string definition for message of type 'state_Woking"
  (cl:format cl:nil "int64 stateworking~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <state_Woking>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <state_Woking>))
  "Converts a ROS message object to a list"
  (cl:list 'state_Woking
    (cl:cons ':stateworking (stateworking msg))
))
