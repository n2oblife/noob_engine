/**
 * @file lib.h
 * @brief Declaration of utility functions for the project.
 *
 * This file contains function prototypes for command-line argument parsing
 * and usage information display. These utilities provide support for handling
 * common application startup tasks.
 */

 #pragma once

 #include <iostream>
 #include <string>
 #include "common.h" // Include global constants and utilities
 
 /**
  * @brief Prints the application usage information.
  * 
  * Displays a help message outlining how to use the application.
  *
  * @param appName The name of the executable.
  */
 void printUsage(const std::string& appName);
 
 /**
  * @brief Parses command-line arguments.
  *
  * Processes command-line arguments and handles common options such as help
  * and version display.
  *
  * @param argc Number of command-line arguments.
  * @param argv Array of argument strings.
  * @return True if the application should continue execution, false if it should exit.
  */
 bool parseArguments(int argc, char* argv[]);
 