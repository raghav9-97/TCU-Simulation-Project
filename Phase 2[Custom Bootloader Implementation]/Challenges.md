# Challenges Faced during Implementation

## 1. During USART initialization, the pins were wrongly mapped by the CubeMX boilerplate code. The issue was the message was not getting printed on the termnial. Fixed the issue by going through the documentation and figuring out the pins required for mapping USART3.

## 2. Ethernet configuration is not working as expected correctly. Need to fix by figuring out the clock tree config and then on success board should get assigned an IP Address.
