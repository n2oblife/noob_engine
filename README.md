# Project

This repository is a try of game engine concepts based on all the video I watch and the youtube channel of [Hirsch Daniel](https://www.youtube.com/@HirschDaniel/featured).

## Table of Contents
- [Project](#project)
  - [Project Overview](#project-overview)
    - [Project Specifications](#project-specifications)
  - [Project Structure](#project-structure)
    - [Key Files](#key-files)
  - [Setup and Installation](#setup-and-installation)
    - [Prerequisites](#prerequisites)
      - [On Ubuntu](#on-ubuntu)
    - [Building the Project](#building-the-emulator)
  - [Usage](#usage)
    - [Controls](#controls)
  - [Running Tests](#running-tests)
    - [New tests](#new-tests)
  - [Acknowledgments](#acknowledgments)
  - [License](#license)

---

## Project Overview
The Project ...

### Project Specifications
...

## Project Structure
This repository is organized as follows:

```plaintext
project/
├── .github/           # GitHub-specific workflows, issue templates, and actions for CI/CD
├── .gitlab-ci.yml     # GitLab CI/CD pipeline configuration
├── .dockerignore      # Specifies files to exclude when building the Docker image
├── .gitignore         # Specifies files to ignore in version control
├── .gitlab-ci/        # Additional scripts and configurations for GitLab CI/CD
├── app/               # Application-specific files (if applicable)
├── docs/              # Project documentation (Doxygen, Markdown files, etc.)
├── extern/            # External dependencies (e.g., third-party libraries)
├── include/           # Header files (.h, .hpp) for project modules
├── scripts/           # Utility scripts (e.g., build automation, deployment)
├── src/               # Source files for the main project implementation
├── tests/             # Unit tests (GoogleTest, Catch2, etc.)
├── CMakeLists.txt     # CMake build configuration file
├── Dockerfile         # Docker image definition for the project
├── Makefile           # Makefile for building and running the project
├── package_list.txt   # List of required system packages
└── README.md          # Project documentation, setup, and usage instructions
```

### Key Files
- **`app.cpp`**: Header file defining the `Chip8` class, which contains the core emulator components.
- **`main.cpp`**: Entry point for the emulator, initializing and running the emulator loop.
- **`Makefile`**: Build instructions for the project.

## Setup and Installation
This emulator is built using C++20 and requires the SDL2 library for rendering and input handling.

## Prerequisites

The following dependencies are required to build and run this project:  

- **Build Tools**: `g++`, `make`, `cmake`, `ninja-build`  
- **Documentation**: `doxygen`, `doxygen-gui`, `doxygen-latex`, `graphviz`  
- **Code Coverage**: `gcov`, `lcov`  

All required packages are listed in **`package_list.txt`** for easy installation.  

To install them on a **Debian-based system (Ubuntu, Debian)**, run:  

```sh
xargs sudo apt-get install -y < package_list.txt
```  

For other distributions, refer to your package manager (e.g., `brew` for macOS, `dnf/yum` for Fedora).  

Let me know if you need any modifications! 🚀

### Building the Emulator
Clone this repository and run the `Makefile` to build the project:

```bash
git clone ...
cd ...
make all
```

If successful, the compiled binary will be located in `build/bin/chip8`.

## Usage
Once built, you can ...

```bash
make run ...
```

### Controls
...

## Running Tests
To run all tests and display failures, use:

```bash
make tests
```

This will execute all test cases and show detailed output if any test fails. The results are saved in `log/report`, with a unique ID consisting of the commit hash and timestamp.

### New tests

Create a New Test File
Test files should be placed in the `tests/` directory and named with the `Test*.cpp` prefix.

For example:
```plaintext
tests/
 ├── TestApp.cpp
 ├── ...
```

Include Google Test:
In your test file, include `gtest/gtest.h` and any required headers from the project.

## Acknowledgments
Special thanks to ...

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.