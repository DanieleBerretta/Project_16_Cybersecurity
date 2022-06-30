# User Manual
In this chapter is described how to use the OTA protocol and retry to perform itself the demo seen
on the project presentation Demo.

### Step 1: ESP32 ESP-IDF
To use the ESP32 board we have to install the ESP-IDF, the development framework used to build
and flash our project. There you can find the link with more information and how to download it:
https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html
As IDE we used VS Code, but it is possible use other editor tool, as Eclipse etc. Once you have the
all tools installed, you can open the ESP-IDF tool, (is like a prompt command), and go in the
project folder ”cd C:project path”. than using the command:
 idf.py build - compile and build the project
 idf.py flash - research ESP32 COM port and flash it
 idf.py monitor - show the serial comunication in orther to follow the update step
Also at this link you can find other useful command:
https://docs.espressif.com/projects/esp-idf/en/v4.2/esp32/api-guides/build-system.html
### **Step 2: Configure the Wi-Fi**
In order to connect the board on the Wi-Fi network you need to change and modify the Wi-Fi
credential with your actual connection. Open the folder at this link:
https://drive.google.com/drive/folders/12X8qwaMzzthq3UGNoWMIBG-sxKIKymrK
Download it and open with a text editor. Replace now ”myssid” with actual SSID connection and
change ”mypassword” with the connection password.
### **Step 3: Compile and Flash ESP32**
we have everything set to build the code. Open ESP-IDF and go on the project path. digit
idf.py build and the build start. At the end press idf.py flash and the SW will Flash on the
board. This is the version 0 that is flashed on partition zero, used also as back up.
15
Cybersecurity for Embedded Systems 16
### **Step 4: Start procedure**
At this point everything is configured and ready, you can start to use the OTA protocol. To see the
protocol working you can modify the software adding or changing the release number and compile it.
Once compiled, copy the bin and paste on Google Drive folder (in our case the link is that one, but
is possible to use your own drive page), if changed the related link on the code. To flash the upload
you can press the button on the ESP32 Board and see the OTA update working. If all gone fine you
have displayed the new release SW.
