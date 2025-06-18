/**
* @file common.h
* @brief Common definitions, utilities, and constants for the project.
*
* This file provides global constants, platform detection macros, logging utilities,
* and helper functions that can be used throughout the project.
*/

#pragma once

#include <cstdint>
#include <string>
#include <iostream>
#include <chrono>
#include <iostream>
#include <vector>
#include <thread>


/** @def PROJECT_NAME
 *  @brief Defines the current project name.
 */
constexpr auto PROJECT_NAME = "my_app";

/** @def PROJECT_VERSION
 *  @brief Defines the current project version.
 */
constexpr auto PROJECT_VERSION = "1.0.0";

/** @name Platform Detection
 *  Macros to identify the operating system at compile time.
 *  @{
 */
#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_WINDOWS ///< Windows platform
#elif defined(__APPLE__) || defined(__MACH__)
    #define PLATFORM_MACOS   ///< macOS platform
#elif defined(__linux__)
    #define PLATFORM_LINUX   ///< Linux platform
#else
    #define PLATFORM_UNKNOWN ///< Unknown platform
#endif
/** @} */ // End of platform detection macros

/** @name Memory Size Constants
 *  Defines memory size constants in bytes.
 *  @{
 */
constexpr std::size_t KB = 1024;         ///< 1 Kilobyte in bytes
constexpr std::size_t MB = 1024 * KB;    ///< 1 Megabyte in bytes
constexpr std::size_t GB = 1024 * MB;    ///< 1 Gigabyte in bytes
/** @} */ // End of memory size constants

/** @name Math Constants
 *  Useful mathematical constants.
 *  @{
 */
constexpr double PI = 3.141592653589793; ///< Approximate value of Pi
constexpr double EPSILON = 1e-9;         ///< Small value for floating-point comparison
/** @} */ // End of math constants

/** @name Logging Macros
 *  Simple macros for logging messages.
 *  @{
 */
#define LOG_INFO(msg) std::cout << "[INFO] " << msg << std::endl    ///< Logs an info message
#define LOG_WARN(msg) std::cerr << "[WARNING] " << msg << std::endl ///< Logs a warning message
#define LOG_ERROR(msg) std::cerr << "[ERROR] " << msg << std::endl  ///< Logs an error message
/** @} */ // End of logging macros

/**
 * @class Timer
 * @brief A simple utility class for measuring elapsed time.
 *
 * This class provides a high-resolution timer to measure execution times.
 */
class Timer {
public:
    /**
     * @brief Constructs a Timer and starts timing immediately.
     */
    Timer() { reset(); }

    /**
     * @brief Resets the timer to the current time.
     */
    void reset() { start_time = std::chrono::high_resolution_clock::now(); }

    /**
     * @brief Gets the elapsed time since the timer was last reset.
     * @return Elapsed time in seconds as a double.
     */
    double elapsed() const {
        return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start_time).count();
    }

private:
    std::chrono::high_resolution_clock::time_point start_time; ///< Stores the start time
};

/**
 * @brief Converts a byte value into a human-readable format.
 *
 * This function converts a size in bytes into a more readable format
 * such as KB, MB, or GB.
 *
 * @param bytes The size in bytes.
 * @return A formatted string representing the size in a readable format.
 */
inline std::string formatBytes(std::size_t bytes) {
    constexpr const char* suffixes[] = {"B", "KB", "MB", "GB", "TB"};
    int i = 0;
    double size = static_cast<double>(bytes);
    while (size >= 1024 && i < 4) {
        size /= 1024;
        ++i;
    }
    return std::to_string(size) + " " + suffixes[i];
}
