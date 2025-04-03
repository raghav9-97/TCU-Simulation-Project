## Challenges Faced
1. TLS Connection not setting up between ESP32 and AWS IoT Core, Certificate Parse error related stuff, Trying with inbuilt examples of ESP-IDF
2. Including certificates issue with the ESP-IDF Code
---

## Solutions Tried
1. Tested certificates with Mosquitto client, in order to check them for validity, it worked fine.
2. CmakeLists.txt was not correct, took inspiration from ESP-IDF Examples for MQTT Mutual Auth
---
