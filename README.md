# code-challenge

# Overview

This is a C++ application.

The application is divided into 3 parts:
- logic
- driver
- test

Logic hold all the business functionality
Driver is the top-level application that provided the required scenarios
Test is a unit test suite

# Running the application

The bin directory contains prebuilt Windows x64 binaries for driver and test applications. Running on other platforms requires building from source.
All required runtime dependancies anre included in the bin folder.

To run: 
-Navigate to the bin folder in Windows explorer or from a command terminal
-In Windows explorer, double click the driver or test EXE files to execute
-From command terminal, type the driver.exe or test.exe commands in the terminal and hit ENTER.

# Building the application from source

## Logic
All logic source code is standard C++ and STL, so only a C++ compiler toolchain is required to build. There
are no 3rd party libraries or frameworks required.

Required source code is under the logic/src directory
Headers are stored in logic/include and logic/interfaces

## Driver and Test
The driver and test programs are dependant upon the logic code.

Driver and Test source code is under the driver and test directories, respectively.

The driver program is standard C++ and STL.
The test program uses Google Test (source not included, but is available via github)