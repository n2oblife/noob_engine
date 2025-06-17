/**
* @file lib.cpp
* @brief Definition of the library used.
*
* This is a generic template for utilities for a C++ application.
*/

// Include project-specific headers
#include "common.h"


void printUsage(const std::string& appName) {
    std::cout << "Usage: " << appName << " [options]\n"
            << "Options:\n"
            << "  -h, --help       Show this help message\n"
            << "  -v, --version    Show application version\n";
}


bool parseArguments(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            printUsage(argv[0]);
            return false;
        }
        else if (arg == "-v" || arg == "--version") {
            std::cout << PROJECT_NAME << " version " << PROJECT_VERSION << "\n";
            return false;
        }
        else {
        LOG_WARN("Unknown argument: " + arg);
        }
    }
    return true;
}