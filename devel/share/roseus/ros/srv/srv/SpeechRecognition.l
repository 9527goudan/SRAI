;; Auto-generated. Do not edit!


(when (boundp 'srv::SpeechRecognition)
  (if (not (find-package "SRV"))
    (make-package "SRV"))
  (shadow 'SpeechRecognition (find-package "SRV")))
(unless (find-package "SRV::SPEECHRECOGNITION")
  (make-package "SRV::SPEECHRECOGNITION"))
(unless (find-package "SRV::SPEECHRECOGNITIONREQUEST")
  (make-package "SRV::SPEECHRECOGNITIONREQUEST"))
(unless (find-package "SRV::SPEECHRECOGNITIONRESPONSE")
  (make-package "SRV::SPEECHRECOGNITIONRESPONSE"))

(in-package "ROS")





(defclass srv::SpeechRecognitionRequest
  :super ros::object
  :slots (_WakenUp ))

(defmethod srv::SpeechRecognitionRequest
  (:init
   (&key
    ((:WakenUp __WakenUp) nil)
    )
   (send-super :init)
   (setq _WakenUp __WakenUp)
   self)
  (:WakenUp
   (&optional (__WakenUp :null))
   (if (not (eq __WakenUp :null)) (setq _WakenUp __WakenUp)) _WakenUp)
  (:serialization-length
   ()
   (+
    ;; bool _WakenUp
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _WakenUp
       (if _WakenUp (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _WakenUp
     (setq _WakenUp (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass srv::SpeechRecognitionResponse
  :super ros::object
  :slots (_SpeechRecogition ))

(defmethod srv::SpeechRecognitionResponse
  (:init
   (&key
    ((:SpeechRecogition __SpeechRecogition) nil)
    )
   (send-super :init)
   (setq _SpeechRecogition __SpeechRecogition)
   self)
  (:SpeechRecogition
   (&optional (__SpeechRecogition :null))
   (if (not (eq __SpeechRecogition :null)) (setq _SpeechRecogition __SpeechRecogition)) _SpeechRecogition)
  (:serialization-length
   ()
   (+
    ;; bool _SpeechRecogition
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _SpeechRecogition
       (if _SpeechRecogition (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _SpeechRecogition
     (setq _SpeechRecogition (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass srv::SpeechRecognition
  :super ros::object
  :slots ())

(setf (get srv::SpeechRecognition :md5sum-) "f0cb90399b5d115dbbf48f3fc50c1e7a")
(setf (get srv::SpeechRecognition :datatype-) "srv/SpeechRecognition")
(setf (get srv::SpeechRecognition :request) srv::SpeechRecognitionRequest)
(setf (get srv::SpeechRecognition :response) srv::SpeechRecognitionResponse)

(defmethod srv::SpeechRecognitionRequest
  (:response () (instance srv::SpeechRecognitionResponse :init)))

(setf (get srv::SpeechRecognitionRequest :md5sum-) "f0cb90399b5d115dbbf48f3fc50c1e7a")
(setf (get srv::SpeechRecognitionRequest :datatype-) "srv/SpeechRecognitionRequest")
(setf (get srv::SpeechRecognitionRequest :definition-)
      "bool WakenUp
---
bool SpeechRecogition

")

(setf (get srv::SpeechRecognitionResponse :md5sum-) "f0cb90399b5d115dbbf48f3fc50c1e7a")
(setf (get srv::SpeechRecognitionResponse :datatype-) "srv/SpeechRecognitionResponse")
(setf (get srv::SpeechRecognitionResponse :definition-)
      "bool WakenUp
---
bool SpeechRecogition

")



(provide :srv/SpeechRecognition "f0cb90399b5d115dbbf48f3fc50c1e7a")


