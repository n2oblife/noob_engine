/**
* @file app.cpp
* @brief Main entry point for the application.
*
* This is a generic template for initializing and running a C++ application.
*/

// Include project-specific headers
#include "common.h"
#include "lib.h"
#include "GenericClass.h"


/**
 * @brief Main application logic.
 */
void runApp() {
    LOG_INFO("Starting " + std::string(PROJECT_NAME) + " v" + PROJECT_VERSION);

    // Example: Simulate work for 3 seconds
    for (int i = 0; i < 3; ++i) {
    LOG_INFO("Running... (" + std::to_string(i + 1) + "/3)");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    LOG_INFO("Application finished successfully.");
}

/**
 * @brief Entry point of the application.
 */
int main(int argc, char* argv[]) {
    if (!parseArguments(argc, argv)) {
        return 0; // Exit early if help/version was requested
    }

    runApp();

    return 0;
}
