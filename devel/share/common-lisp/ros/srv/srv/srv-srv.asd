
(cl:in-package :asdf)

(defsystem "srv-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SpeechRecognition" :depends-on ("_package_SpeechRecognition"))
    (:file "_package_SpeechRecognition" :depends-on ("_package"))
  ))