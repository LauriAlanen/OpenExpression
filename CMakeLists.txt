cmake_minimum_required(VERSION 3.22)

option(SEMIHOSTING "Enable semihosting" ON)
include(cmake/gcc-arm-none-eabi.cmake SEMIHOSTING)
message("SEMIHOSTING is set to: ${SEMIHOSTING}")

# Setup compiler settings
set(CMAKE_C_STANDARD                99)
set(CMAKE_C_STANDARD_REQUIRED       ON)
set(CMAKE_C_EXTENSIONS              ON)
set(CMAKE_CXX_STANDARD              20)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            ON)
set(PROJ_PATH                       ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
message("Build type: "              ${CMAKE_BUILD_TYPE})

#
# Core project settings
#
project(STM32L432KC)
enable_language(C ASM)

#
# Core MCU flags, CPU, instruction set and FPU setup
# Needs to be set properly for your MCU
#
set(CPU_PARAMETERS
    -mthumb

    # This needs attention to properly set for used MCU
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
)

# Set linker script
set(linker_script_SRC               ${PROJ_PATH}/STM32L432KCUX_FLASH.ld)
set(EXECUTABLE                      ${CMAKE_PROJECT_NAME})

# List of source files to compile
function(collect_sources output_list directory)
    file(GLOB_RECURSE _sources "${directory}/*.c" "${directory}/*.S")
    list(APPEND ${output_list} ${_sources})
    set(${output_list} ${${output_list}} PARENT_SCOPE)
endfunction()

# List of source directories
set(source_directories
    "${PROJ_PATH}/Core/Source"
    "${PROJ_PATH}/Core/Startup"
    "${PROJ_PATH}/Drivers/stm32l4xx_hal_driver/Src"
)

# Initialize list for source files
set(sources_SRCS "")

# Collect source files from each directory
foreach(dir ${source_directories})
    collect_sources(sources_SRCS ${dir})
endforeach()

# Include directories
set(include_path_DIRS
    ${PROJ_PATH}/Core/Include
    ${PROJ_PATH}/Drivers/stm32l4xx_hal_driver/Inc
    ${PROJ_PATH}/Drivers/CMSIS/Include
)

#
# Symbols definition
#
set(symbols_SYMB
    "DEBUG"
    "STM32L432xx"
)

# Executable files
add_executable(${EXECUTABLE} ${sources_SRCS})

# Include paths
target_include_directories(${EXECUTABLE} PRIVATE ${include_path_DIRS})

# Project symbols
target_compile_definitions(${EXECUTABLE} PRIVATE ${symbols_SYMB})

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
    ${CPU_PARAMETERS}
    -Wall
    -Wextra
    -Wpedantic
    -Wno-unused-parameter
    # Full debug configuration
    -Og -g3 -ggdb
)

if(SEMIHOSTING)
    target_link_options(${EXECUTABLE} PRIVATE
    -lrdimon
    )
    target_compile_definitions(${EXECUTABLE} PRIVATE SEMIHOSTING_ENABLED)
endif(SEMIHOSTING)

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
    -T${linker_script_SRC}
    ${CPU_PARAMETERS}
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
    -u _printf_float                # STDIO float formatting support
    -Wl,--start-group
    -lc
    #-lm
    #-lstdc++
    #-lsupc++
    -Wl,--end-group
    -Wl,--print-memory-usage
)



# Execute post-build to print size
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE}>
)

# Convert output to hex and binary
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.hex
)

# Convert to bin file -> add conditional check?
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.bin
)

# Convert to bin file -> add conditional check?
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.bin
)

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND st-flash --reset write ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.bin 0x8000000
    COMMENT "Flashing ${PROJECT_NAME} to STM32"
)

