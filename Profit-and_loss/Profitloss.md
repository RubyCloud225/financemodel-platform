# Profit and Loss Calculation API in C++

This document provides a step-by-step guide to creating a C++ API that calculates profit and loss based on data fetched from an external API. The implementation uses the Crow framework for handling HTTP requests, along with `libcurl` for making HTTP requests and `nlohmann/json` for JSON parsing.

## Prerequisites

Before you begin, ensure you have the following installed:

- **C++ Compiler**: A modern C++ compiler (e.g., g++, clang++).
- **CMake**: For building the project.
- **libcurl**: For making HTTP requests.
- **nlohmann/json**: For JSON parsing.
- **Crow Framework**: A C++ micro web framework.

### Installing Dependencies

1. **libcurl**: Install using your package manager. For example, on Ubuntu:
   ```bash
   sudo apt-get install libcurl4-openssl-dev

2. **nlohmann/json: install or include directly
    ```bash
    git clone https://github.com/nlohmann/json.git
3. **CrowFramework**: clone the crow respository
    ```bash
    git clone https://github.com/CrowCpp/Crow.git 

### Project structure

/your_project |-- main.cpp |-- ProfitLossCalculator.cpp |-- ProfitLossCalculator.h |-- /crow | |-- crow_all.h |-- /json | |-- json.hpp

### Code Implementation

Defined header file - ProfitLossCalculator.h, this declars the nominal data structure

implemented the ProfitLossCalculator class - ProfitLossCalculator.cpp, this implements the methods for fetching data from external API and calculating profit and loss. 

