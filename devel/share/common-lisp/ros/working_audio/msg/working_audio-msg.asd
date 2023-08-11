
(cl:in-package :asdf)

(defsystem "working_audio-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "state_Woking" :depends-on ("_package_state_Woking"))
    (:file "_package_state_Woking" :depends-on ("_package"))
  ))