
(cl:in-package :asdf)

(defsystem "sip_scenario-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "LampInput" :depends-on ("_package_LampInput"))
    (:file "_package_LampInput" :depends-on ("_package"))
    (:file "StopScenario" :depends-on ("_package_StopScenario"))
    (:file "_package_StopScenario" :depends-on ("_package"))
    (:file "AccessToFloor" :depends-on ("_package_AccessToFloor"))
    (:file "_package_AccessToFloor" :depends-on ("_package"))
    (:file "NearToFloor" :depends-on ("_package_NearToFloor"))
    (:file "_package_NearToFloor" :depends-on ("_package"))
    (:file "LeaveFromFloor" :depends-on ("_package_LeaveFromFloor"))
    (:file "_package_LeaveFromFloor" :depends-on ("_package"))
  ))