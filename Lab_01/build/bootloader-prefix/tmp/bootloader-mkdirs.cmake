# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/SEMESTER7/EMBEDDED/esp/esp-idf/Espressif/frameworks/esp-idf-v5.1.1/components/bootloader/subproject"
  "D:/SEMESTER7/EMBEDDED/LAB_01_02/embedded_System_All_Labs/Lab_01/build/bootloader"
  "D:/SEMESTER7/EMBEDDED/LAB_01_02/embedded_System_All_Labs/Lab_01/build/bootloader-prefix"
  "D:/SEMESTER7/EMBEDDED/LAB_01_02/embedded_System_All_Labs/Lab_01/build/bootloader-prefix/tmp"
  "D:/SEMESTER7/EMBEDDED/LAB_01_02/embedded_System_All_Labs/Lab_01/build/bootloader-prefix/src/bootloader-stamp"
  "D:/SEMESTER7/EMBEDDED/LAB_01_02/embedded_System_All_Labs/Lab_01/build/bootloader-prefix/src"
  "D:/SEMESTER7/EMBEDDED/LAB_01_02/embedded_System_All_Labs/Lab_01/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/SEMESTER7/EMBEDDED/LAB_01_02/embedded_System_All_Labs/Lab_01/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/SEMESTER7/EMBEDDED/LAB_01_02/embedded_System_All_Labs/Lab_01/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
