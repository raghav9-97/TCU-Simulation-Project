# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

set(EXTRA_COMPONENT_DIRS components/esp-aws-iot)

project(aws_iot_test)
target_add_binary_data(${CMAKE_PROJECT_NAME}.elf "main/certificates/client.crt" TEXT)
target_add_binary_data(${CMAKE_PROJECT_NAME}.elf "main/certificates/client.key" TEXT)
target_add_binary_data(${CMAKE_PROJECT_NAME}.elf "main/certificates/server.crt" TEXT)