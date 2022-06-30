# Project_16_Cybersecurity
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

### **Introduction**
An over-the-air (OTA) update is the wireless delivery of new software, firmware, or other data to mobile devices. Wireless carriers and original equipment manufacturers (OEMs) typically use over-the-air updates to deploy firmware and configure phones for use on their networks over Wi-Fi or mobile broadband. The initialization of a newly pur-chased phone, for example, requires an over-the-air update. With the rise of smartphones, tablets and internet of things (IoT) devices, carriers and manufacturers have turned to different over-the-air update architecture methods for deploying new operating systems (OSes) to these devices.
### **Goal of the Project**
Defining and implementation of an inter-cluster protocol where nodes verify the binary of other nodes by means of co-operative hash checking. Defining/Implementation of mechanism to receive/execute the updates.
### **References**
There are many reference implementations like RIOT secure OTA update that can be stud-ied/adapted.
### **Constraints**
The target design/implementation is for IoT devices that are communication within clus-ter of nodes which are using RTOSs and GPOS.
