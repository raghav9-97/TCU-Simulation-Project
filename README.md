# Telematics Control Unit (TCU) Firmware Update System

## Project Overview

---

## Project Phases

### **Phase 1: Communication Setup of TCU & ECU Assembly**

---

### **Phase 2: Custom Bootloader Implementation for ECU**

---

### **Phase 3: Version 2.0 Firmware delivery using OTA update**

---

### Future Goals

---

## Hardware Components List
- **STM32F446RE Nucleo Board** (TCU Component Emulation).
- **STM32H753ZI Nucleo Board** (ECU Component Emulation - Dual Bank Flash and CAN-FD Support).
- **ESP32 DevkitCv4 Board** (WiFi Module for communicating with AWS IoT Core).
- **MCP2562FD CAN-FD Transceiver** (CAN Transceivers for setting up CAN-FD Communication).
- **SDCard Breakout Board** (SD Card Module for ECU and TCU Assembly).
---

## Software Development Tools
- **STM32CubeIDE** (For Development of STM32 Firmware, initializing Peripherals and Flashing firmware onto the boards).
- **ESP-IDF** (Development environment for ESP32 DevKitC, setting up communication with AWS IoT Core).
- **VSCode** (Handling VCS, Maintaining Code Repository).
- **Git** (For Tracking Issues, Maintaining Repository and Project Directory).
- **Miro Board** (Kanban Framework Board for keeping track of the issues).
---

## Communication Protocols 
- **UART** (Communication protocol between TCU and ESP32 DevkitC for high speed transmission).
- **CAN-FD** (Communication Protocol between ECU and TCU assembly).
- **ISO-TP** (Transport Protocol for use over CAN-FD to handle fragmentation and reassembly logic of firmware updates).
- **TLS/HTTPS** (Communication Channel between ESP32 and AWS IoT Core).
- **XMODEM/YMODEM** (Transport Protocol for use over UART to handle fragmentation and reassembly).
---
