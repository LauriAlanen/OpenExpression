# In Progress... 

## Sidenote
This project is currently only made for the purpose of learning ARM based processors, building toolchains, cross compiling and learning the building/linking processes

All of the following configurations and tools are designed to be runned in Linux based operating systems.

# OpenExpression
- Fully open source as the name implies :)
- 3D Printed expression pedal which communicates using the MIDI protocol.
- AS5600 Magnetic Encoder is used for reading the angle of the pedal. This is totally unnecessary and complicates lots of things, but has been chosen for the sake of learning.
- Uses any STM32L4xx based MCU. The code is written mostly using the `STM32L4xx` HAL. Currently can be built only for the `STM32L432`, but this is limited by startup scripts and some parts that use direct register access. 
## Smoot Pedal Mechanism
- All moving joints in the pedal use bearings for smooth action
- Always locked in the upright position by springs
- Simple rotating disk mechanism for achieving the springines with configurable tension


"In Progress Picture of the Mechanism in the Pedal"

![image](https://github.com/LauriAlanen/OpenExpression/assets/80245457/e5ffd25b-2732-40a6-ba2c-e7bf9da54242)

## Debugging
- Includes preconfigured launch options for debugging `launch.json`, with GDB + STLink.
- Easy debugging with prebuilt vscode tasks that automaticly build the project according to debug options.
- Semihosting is supported (Seperate launch option)

## CMake
- Preconfigured build options.
- Semihosting can be enabled easily, which automaticly includes the necessary libraries and correct build linker flags.
