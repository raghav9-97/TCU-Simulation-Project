# Telematics Control Unit (TCU) Firmware Update System

## Project Overview

The **Telematics Control Unit (TCU) Firmware Update System** is an advanced embedded systems project designed to simulate an Over-the-Air (OTA) firmware update mechanism for **Telematics Control Units (TCU)** and **Electronic Control Units (ECU)**. The project uses **CAN-FD**, **SPI**, and **AWS IoT Core** to establish secure communication between the TCU and ECU, allowing firmware updates to be transferred from the cloud to the ECU via the TCU. The system incorporates key features like **sensor data collection**, **threshold monitoring**, and **firmware integrity checks**, aiming to build a robust and scalable solution for automotive and IoT devices.

The development is structured into **phases**, with each phase focused on a specific aspect of the system. The goal is to implement a modular OTA update mechanism that ensures firmware integrity, rollback capability, and cloud connectivity.

---

## Project Phases

### **Phase 1: TCU and ECU Communication Setup**

**Objective**: This phase sets up the basic hardware and communication protocols necessary for the functioning of the system. The following steps are involved:

- **Hardware Setup**: The TCU is based on the **STM32F446RE**, and the ECU is also emulated on another **STM32F446RE** board. To establish cloud communication, the **ESP32 module** is used for Wi-Fi connectivity and communication with **AWS IoT Core**.
  
- **Communication Protocols**: 
  - **SPI (Serial Peripheral Interface)** is chosen for communication between the **TCU** and **ESP32**. The SPI protocol will be crucial for future firmware updates, ensuring faster data transfer rates compared to other protocols like UART.
  - **CAN-FD** is implemented between the **TCU** and **ECU** to simulate automotive network communication. **CAN-FD (Controller Area Network with Flexible Data rate)** allows for larger payloads and faster data transmission compared to standard **CAN**, which is important for firmware updates and sensor data exchange.

- **ECU Firmware**: The **ECU** firmware is designed to simulate various sensor values (e.g., temperature, pressure) and periodically send these sensor snapshots to the **AWS IoT Core** every 5 seconds. The **TCU** collects this sensor data via **CAN** and uses **ESP32** to transmit it to the cloud.

By the end of Phase 1, the TCU and ECU are communicating successfully, and the TCU can send periodic sensor data to the cloud.

---

### **Phase 2: Custom Bootloader Implementation**

**Objective**: The main goal of this phase is to implement a **custom bootloader** for the ECU, enabling safe firmware updates and ensuring firmware integrity. This phase will focus on the following key features:

- **Custom Bootloader**: The custom bootloader will be responsible for flashing new firmware onto the **ECU** and verifying its integrity. The bootloader will also handle the switching between the old and new firmware stored in the **dual-bank flash memory**.
  
- **Dual-Bank Memory**: In a dual-bank setup, the bootloader ensures that the system can switch between two versions of firmware, providing safety and reliability. If an update is successful, the ECU will boot from the newly flashed firmware; otherwise, it will revert to the old version.

- **Integrity Check**: Before flashing any firmware, the bootloader performs integrity checks using checksums or hash values to ensure the firmware has not been corrupted during transmission.

- **Rollback Mechanism**: If the firmware flashing process fails, the bootloader will use the **rollback mechanism** to revert to the previous working version of the firmware, ensuring the system remains functional even in the event of an error.

**Testing Environment**: The custom bootloader will initially be tested in a simulated environment using **QEMU** for the ECU, to simulate the behavior before hardware deployment.

---

### **Phase 3: Firmware Transfer from TCU to ECU over CAN-FD**

**Objective**: In this phase, the main task is to transfer the firmware from the **TCU** to the **ECU** via the **CAN-FD** protocol. The firmware size is expected to be large, so a proper method for fragmentation and reassembly will be necessary. The following tasks will be accomplished:

- **UDS over CAN-FD**: The **Unified Diagnostic Services (UDS)** protocol over **CAN-FD** will be used to handle large firmware files. UDS is an automotive protocol designed for diagnostics, firmware flashing, and more. Using UDS over **CAN-FD** will handle the fragmentation and reassembly of firmware packets since **CAN-FD** frames have size limitations.

- **Firmware Transfer**: The **TCU** will send the firmware stored on its external storage to the **ECU** over the **CAN-FD** bus. The transfer must be efficient, and any data packet loss during transmission will be handled with **retransmission** mechanisms.

- **Successful Transfer and Acknowledgments**: The transfer will only be considered successful if the **ECU** correctly receives and stores the firmware. The **TCU** will send acknowledgment messages upon successful firmware receipt, and retransmission will be triggered in case of any packet loss.

By the end of this phase, the TCU will be capable of transferring firmware to the ECU over CAN-FD, ensuring reliable delivery even for large firmware files.

---

### **Phase 4: Firmware Delivery from AWS IoT Cloud to TCU**

**Objective**: This phase focuses on the TCU downloading the latest firmware from the **AWS IoT Cloud**. The steps in this phase include:

- **AWS IoT Core Integration**: The **TCU** will communicate with **AWS IoT Core** to check for firmware updates. The **Device Shadow** in AWS will keep track of the current firmware version running on the **TCU** and **ECU**.

- **Firmware Request**: Once the **TCU** receives a request indicating that a new firmware version is available on the cloud, it will acknowledge the request and download the firmware. The **ESP32** will handle the cloud communication, downloading the firmware from **AWS S3**.

- **Storage and Integrity Checks**: The **TCU** will store the downloaded firmware on its external storage and perform integrity checks to verify that the firmware is intact and authentic. This ensures that no tampering has occurred during the download process.

At the end of this phase, the **TCU** will be capable of securely downloading and storing new firmware from the **AWS IoT Cloud**.

---

### **Phase 5: Integrating OTA Update End-to-End**

**Objective**: This phase integrates all previous components and ensures the end-to-end functionality of the OTA update mechanism. The main tasks include:

- **Sensor Threshold Logic for ECU**: The new firmware for the **ECU** will include logic to monitor sensor data and upload snapshots of the data only when a threshold is violated (e.g., high temperature). This minimizes unnecessary data transmission while ensuring critical events are reported.

- **End-to-End Firmware Update**: The process will begin with the **TCU** downloading a firmware update from the cloud (AWS IoT Core) and then flashing this firmware onto the **ECU** over **CAN-FD**.

- **Device Shadow Update**: After a successful firmware update, the **ECU** will report the new firmware version to the **TCU**, and the **Device Shadow** in AWS will be updated with the new firmware version for both the **TCU** and **ECU**.

By the end of this phase, the entire OTA update mechanism will be functional, with the **ECU** successfully receiving firmware updates based on sensor thresholds and the **TCU** managing the firmware delivery process.

---

## Future Goals

Once the basic OTA update mechanism is fully functional, additional features and improvements will be explored:

- **Differential Firmware Updates**: Instead of transferring the entire firmware, future updates may use differential updates to minimize data transfer.
- **TCU and ECU Firmware Versions**: Newer firmware versions for the **TCU** and **ECU** may be introduced to improve functionality, security, and performance.

---

## Getting Started

To get started with this project:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/TCU-Firmware-Update-System.git
