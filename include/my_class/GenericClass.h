/**
* @file GenericClass.h
* @brief A generic C++ class template.
*
* This file defines a basic class structure with private attributes,
* constructors, getters, setters, and a utility function.
*/

#pragma once

#include <iostream>
#include <string>

/**
 * @class GenericClass
 * @brief A simple example of a generic C++ class.
 *
 * This class demonstrates encapsulation, constructors, and utility methods.
 */
class GenericClass {
public:
    /**
     * @brief Default constructor.
     * Initializes the object with default values.
     */
    GenericClass();

    /**
     * @brief Parameterized constructor.
     * Initializes the object with given values.
     * @param name The name of the object.
     * @param value An integer value associated with the object.
     */
    GenericClass(const std::string& name, int value);

    /**
     * @brief Destructor.
     * Cleans up any allocated resources.
     */
    ~GenericClass();

    /**
     * @brief Gets the name of the object.
     * @return The name as a string.
     */
    std::string getName() const;

    /**
     * @brief Sets the name of the object.
     * @param name The new name.
     */
    void setName(const std::string& name);

    /**
     * @brief Gets the integer value of the object.
     * @return The stored integer value.
     */
    int getValue() const;

    /**
     * @brief Sets the integer value of the object.
     * @param value The new integer value.
     */
    void setValue(int value);

    /**
     * @brief Displays the object's information.
     */
    void displayInfo() const;

private:
    std::string name; ///< The name of the object.
    int value; ///< An integer value associated with the object.
};
