# Presentation
### **Secure_OTA_Update** 
This document reports the development of the secure OTA update project, for the course Cybersecurity
for Embedded Systems. It describes how this OTA protocol was develop and then designed with
a look at possible and future developments, starting from a simpler working base. By Reading this
report, we will review some concepts for wireless update (using an internet connection) and safety
concepts that we want to guarantee and apply to our protocol. The main actors in this protocol
are a common PC, used to upload the new binary file to be downloaded to the device, the internet
connection to the exchange server (in this case we choose Google Drive as a prototype server to check
that our mechanism works correctly), and the boards used for IoT communications (ESP32s).
At the end of the report you will be able to implement step by step a working update protocol for
devices that use ESP32, being aware of the secure mechanism used.
