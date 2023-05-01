# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

#include build functions from Pico SDK
include(pico_sdk_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C++ Standards
project(frequency-viewer C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

file(GLOB HEADERS
        "${CMAKE_SOURCE_DIR}/src/headers/led_gestion.h"
        "${CMAKE_SOURCE_DIR}/src/headers/ADC_gestion.h"
        "${CMAKE_SOURCE_DIR}/src/headers/my_utils.h"
)

file(GLOB FILES
        "${CMAKE_SOURCE_DIR}/src/codes/led_gestion.c"
        "${CMAKE_SOURCE_DIR}/src/codes/ADC_gestion.c"
        "${CMAKE_SOURCE_DIR}/src/codes/my_utils.c"
)

file(GLOB TEST_HEADERS
        "${CMAKE_SOURCE_DIR}/src/tests/headers/test_led.h"
        "${CMAKE_SOURCE_DIR}/src/tests/headers/test_adc.h"
)

file(GLOB TEST_FILES
        "${CMAKE_SOURCE_DIR}/src/tests/codes/test_led.c"
        "${CMAKE_SOURCE_DIR}/src/tests/codes/test_adc.c"
)


if (TARGET tinyusb_device)
        if (NOT TEST)
        # point out the CMake, where to find the executable source file
        add_executable(${PROJECT_NAME}
                ${CMAKE_SOURCE_DIR}/src/main.c
                ${FILES}
                ${HEADERS}
        )

        elseif (TEST)
                message("********* Build in Test mode *********")
                # point out the CMake, where to find the executable source file
                add_executable(${PROJECT_NAME}
                        ${CMAKE_SOURCE_DIR}/src/tests/main_test.c
                        ${FILES}
                        ${HEADERS}
                        ${TEST_HEADERS}
                        ${TEST_FILES}
                )
        endif()

        # create map/bin/hex/uf2 files.
        pico_add_extra_outputs(${PROJECT_NAME})

        # Pull in our pico_stdlib which pulls in commonly used features (gpio, timer-delay etc)
        target_link_libraries(${PROJECT_NAME}
                pico_stdlib
                hardware_gpio
                hardware_adc
                hardware_irq
        )

        # Enable usb output, disable uart output
        pico_enable_stdio_usb(${PROJECT_NAME} 1)
        pico_enable_stdio_uart(${PROJECT_NAME} 0)

elseif(PICO_ON_DEVICE)
        message(WARNING "not building because TinyUSB submodule is not initialized in
        the SDK")
endif()