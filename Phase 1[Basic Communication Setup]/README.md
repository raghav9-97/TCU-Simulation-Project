# Phase 1: Development Plan

## Overview
Phase 1 focuses on setting up the basic hardware and establishing fundamental communication channels between different components. The goal is to ensure seamless interaction between the STM32-based TCU, STM32-based ECU, and ESP32, along with cloud connectivity to AWS IoT Core. This setup will serve as the foundation for future phases, including firmware updates and advanced diagnostics.

## Goals

1. **Hardware Setup:**  
   - Configure STM32 boards for TCU and ECU roles.
   - Set up ESP32 for cloud communication.
   
2. **Communication Between TCU and ESP32:**  
   - Establish SPI communication between STM32 TCU and ESP32.  
   - Ensure data exchange capability for future firmware updates.

3. **ECU Sensor Simulation:**  
   - Develop basic firmware for the STM32 ECU to simulate sensor values.
   - Generate periodic sensor snapshots every 5 seconds.
   
4. **CAN-FD Communication Between TCU and ECU:**  
   - Implement CAN-FD communication for sensor data transfer from ECU to TCU.
   - Replace QEMU simulation with a real STM32 board for ECU due to CAN-FD limitations in emulation.

5. **Cloud Integration:**  
   - Ensure TCU forwards sensor data from ECU to ESP32.
   - Transmit sensor data from ESP32 to AWS IoT Core.
   - Setup AWS Dashboard for better visualization of Sensor Data.

6. **RTOS Integration Consideration:**  
   - Evaluate the necessity of RTOS for handling communication and task scheduling efficiently.
   - Potentially set up FreeRTOS on:
     - **ESP32** (for Wi-Fi, SPI, and cloud communication tasks).
     - **TCU** (for managing SPI, CAN-FD, and cloud interactions).
     - **ECU** (for sensor simulation and CAN-FD communication).

## Expected Outcome
- A fully functional hardware and software setup where simulated sensor data flows from ECU → TCU → ESP32 → AWS IoT Core.
- Stable and tested communication protocols (SPI and CAN-FD) to support future firmware updates.
- Optional RTOS integration for modular and efficient task handling.
