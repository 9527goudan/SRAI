;; Auto-generated. Do not edit!


(when (boundp 'working_audio::state_Woking)
  (if (not (find-package "WORKING_AUDIO"))
    (make-package "WORKING_AUDIO"))
  (shadow 'state_Woking (find-package "WORKING_AUDIO")))
(unless (find-package "WORKING_AUDIO::STATE_WOKING")
  (make-package "WORKING_AUDIO::STATE_WOKING"))

(in-package "ROS")
;;//! \htmlinclude state_Woking.msg.html


(defclass working_audio::state_Woking
  :super ros::object
  :slots (_stateworking ))

(defmethod working_audio::state_Woking
  (:init
   (&key
    ((:stateworking __stateworking) 0)
    )
   (send-super :init)
   (setq _stateworking (round __stateworking))
   self)
  (:stateworking
   (&optional __stateworking)
   (if __stateworking (setq _stateworking __stateworking)) _stateworking)
  (:serialization-length
   ()
   (+
    ;; int64 _stateworking
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _stateworking
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _stateworking (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _stateworking) (= (length (_stateworking . bv)) 2)) ;; bignum
              (write-long (ash (elt (_stateworking . bv) 0) 0) s)
              (write-long (ash (elt (_stateworking . bv) 1) -1) s))
             ((and (class _stateworking) (= (length (_stateworking . bv)) 1)) ;; big1
              (write-long (elt (_stateworking . bv) 0) s)
              (write-long (if (>= _stateworking 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _stateworking s)(write-long (if (>= _stateworking 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _stateworking
#+(or :alpha :irix6 :x86_64)
      (setf _stateworking (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _stateworking (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get working_audio::state_Woking :md5sum-) "dc665f7d3e15bf1394666a415605eaf6")
(setf (get working_audio::state_Woking :datatype-) "working_audio/state_Woking")
(setf (get working_audio::state_Woking :definition-)
      "int64 stateworking

")



(provide :working_audio/state_Woking "dc665f7d3e15bf1394666a415605eaf6")


