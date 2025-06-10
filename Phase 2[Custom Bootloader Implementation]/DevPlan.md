### Custom Bootloader Implementation Considerations :

1. Usually keep the bootloader at the start of the flash 0x08000000.
2. Handling open/read errors of binary firmware file on the SD card via SPI Interface.
3. Calculate a checksum to verify firmware file before flashing and store it separately for verification after flashing.
4. Erasing the flash sectors/pages before writing the firmware file.
5. Reading firmware in chunks, writing each chunk to flash sequentially, reading back flash content to verify correctness.
6. Handling write failures with retries.
7. Updating the vector table offset register(VTOR) to point to the new firmware.
8. After flashing and verification, perform a system reset.
9. Write protections for custom bootloader.
10. Debug output to track the bootloader progress and errors.[Power Failure / Rechecking Chunks etc.]