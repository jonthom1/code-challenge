# code-challenge

# Overview

This repo contains both C++ and Java versions of the application

The application is conceptually divided into 3 parts:
- logic
- driver
- test

Logic holds all the business functionality
Driver is the top-level class/application/main that provides the required scenarios
Test is a unit test suite

# Java

## Running the application

The code package is named codechallenge. This contains a gradle wrapper that can be used to build, run, and test the application.
Run ./gradlew tasks to view all available tasks.

The application uses standard Java 8.
The test runner and unit tests are using JUnit 4.12

# C++

## Running the application

The bin directory contains prebuilt Windows x64 binaries for driver and test applications. Running on other platforms requires building from source.
All required runtime dependancies anre included in the cpp/bin folder.

To run: 
- Navigate to the bin folder in Windows explorer or from a command terminal
- In Windows explorer, double click the driver or test EXE files to execute
- From command terminal, type the driver.exe or test.exe commands in the terminal and hit ENTER.

## Building the application from source

### Logic
All logic source code is standard C++ and STL, so only a C++ compiler toolchain is required to build. There
are no 3rd party libraries or frameworks required.

Required source code is under the cpp/logic/src directory
Headers are stored in cpp/logic/include and cpp/logic/interfaces

### Driver and Test
The driver and test programs are dependant upon the logic code.

Driver and Test source code is under the driver and test directories, respectively.

The driver program is standard C++ and STL.
The test program uses Google Test (source not included, but is available via github)