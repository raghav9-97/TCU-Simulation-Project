# Telematics Control Unit (TCU) Firmware Update System

## Project Overview

---

## Project Phases

### **Phase 1: TCU and ECU Communication Setup**

---

### **Phase 2: Custom Bootloader Implementation**

---

### **Phase 3: Firmware Transfer from TCU to ECU over CAN-FD**

---

### **Phase 4: Firmware Delivery from AWS IoT Cloud to TCU**

---

### **Phase 5: Integrating OTA Update End-to-End**

---

### Future Goals

---

## Hardware Components List
- **STM32F446RE Nucleo Board** (TCU Component Emulation).
- **STM32F446RE Nucleo Board** (ECU Component Emulation).
- **ESP32 DevkitCv4 Board** (WiFi Module for communicating with AWS IoT Core).
- **MCP2562FD CAN-FD Transceiver** (CAN Transceivers for setting up CAN-FD Communication).
---

## Software Development Tools
- **STM32CubeIDE** (For Development of STM32 Firmware, initializing Peripherals and Flashing firmware onto the boards).
- **ESP-IDF** (Development environment for ESP32 DevKitC, setting up communication with AWS IoT Core).
- **VSCode** (Handling VCS, Maintaining Code Repository).
- **Git** (For Tracking Issues, Maintaining Repository and Project Directory).
---

## Communication Protocols 
- **SPI** (Communication protocol between TCU and ESP32 DevkitC for high speed transmission).
- **CAN-FD** (Communication Protocol between ECU and TCU for firmware updates).
- **UDS** (UDS Protocol for use over CAN-FD to handle fragmentation and reassembly logic of firmware updates).
- **TLS/HTTPS** (Communication Channel between ESP32 and AWS IoT Core).
---
