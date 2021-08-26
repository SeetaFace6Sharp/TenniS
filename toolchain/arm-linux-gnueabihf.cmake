set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(ARM_ARCH gnueabihf)

#set(CMAKE_SYSROOT /usr/arm-linux-${ARM_ARCH})
set(CMAKE_FIND_ROOT_PATH /usr/arm-linux-${ARM_ARCH})
#set(CMAKE_STAGING_PREFIX /usr/arm-linux-${ARM_ARCH})

set(CMAKE_C_COMPILER arm-linux-${ARM_ARCH}-gcc)
set(CMAKE_CXX_COMPILER arm-linux-${ARM_ARCH}-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

