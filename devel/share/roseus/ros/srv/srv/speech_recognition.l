;; Auto-generated. Do not edit!


(when (boundp 'srv::speech_recognition)
  (if (not (find-package "SRV"))
    (make-package "SRV"))
  (shadow 'speech_recognition (find-package "SRV")))
(unless (find-package "SRV::SPEECH_RECOGNITION")
  (make-package "SRV::SPEECH_RECOGNITION"))
(unless (find-package "SRV::SPEECH_RECOGNITIONREQUEST")
  (make-package "SRV::SPEECH_RECOGNITIONREQUEST"))
(unless (find-package "SRV::SPEECH_RECOGNITIONRESPONSE")
  (make-package "SRV::SPEECH_RECOGNITIONRESPONSE"))

(in-package "ROS")





(defclass srv::speech_recognitionRequest
  :super ros::object
  :slots (_WakenUp ))

(defmethod srv::speech_recognitionRequest
  (:init
   (&key
    ((:WakenUp __WakenUp) 0)
    )
   (send-super :init)
   (setq _WakenUp (round __WakenUp))
   self)
  (:WakenUp
   (&optional __WakenUp)
   (if __WakenUp (setq _WakenUp __WakenUp)) _WakenUp)
  (:serialization-length
   ()
   (+
    ;; int8 _WakenUp
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _WakenUp
       (write-byte _WakenUp s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _WakenUp
     (setq _WakenUp (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _WakenUp 127) (setq _WakenUp (- _WakenUp 256)))
   ;;
   self)
  )

(defclass srv::speech_recognitionResponse
  :super ros::object
  :slots (_SpeechRecogition ))

(defmethod srv::speech_recognitionResponse
  (:init
   (&key
    ((:SpeechRecogition __SpeechRecogition) 0)
    )
   (send-super :init)
   (setq _SpeechRecogition (round __SpeechRecogition))
   self)
  (:SpeechRecogition
   (&optional __SpeechRecogition)
   (if __SpeechRecogition (setq _SpeechRecogition __SpeechRecogition)) _SpeechRecogition)
  (:serialization-length
   ()
   (+
    ;; int8 _SpeechRecogition
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _SpeechRecogition
       (write-byte _SpeechRecogition s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _SpeechRecogition
     (setq _SpeechRecogition (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _SpeechRecogition 127) (setq _SpeechRecogition (- _SpeechRecogition 256)))
   ;;
   self)
  )

(defclass srv::speech_recognition
  :super ros::object
  :slots ())

(setf (get srv::speech_recognition :md5sum-) "c05feedf1ccb8f1f38dacceac93906b6")
(setf (get srv::speech_recognition :datatype-) "srv/speech_recognition")
(setf (get srv::speech_recognition :request) srv::speech_recognitionRequest)
(setf (get srv::speech_recognition :response) srv::speech_recognitionResponse)

(defmethod srv::speech_recognitionRequest
  (:response () (instance srv::speech_recognitionResponse :init)))

(setf (get srv::speech_recognitionRequest :md5sum-) "c05feedf1ccb8f1f38dacceac93906b6")
(setf (get srv::speech_recognitionRequest :datatype-) "srv/speech_recognitionRequest")
(setf (get srv::speech_recognitionRequest :definition-)
      "int8 WakenUp
---
int8 SpeechRecogition

")

(setf (get srv::speech_recognitionResponse :md5sum-) "c05feedf1ccb8f1f38dacceac93906b6")
(setf (get srv::speech_recognitionResponse :datatype-) "srv/speech_recognitionResponse")
(setf (get srv::speech_recognitionResponse :definition-)
      "int8 WakenUp
---
int8 SpeechRecogition

")



(provide :srv/speech_recognition "c05feedf1ccb8f1f38dacceac93906b6")


