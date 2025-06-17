/**
* @file GenericClass.cpp
* @brief Implementation of the GenericClass.
*/

#include "common.h"
#include "GenericClass.h"


GenericClass::GenericClass() : name("Unnamed"), value(0) {}


GenericClass::GenericClass(const std::string& name, int value) : name(name), value(value) {}


GenericClass::~GenericClass() {
    // Destructor logic (if needed)
}


std::string GenericClass::getName() const {
    return name;
}


void GenericClass::setName(const std::string& name) {
    this->name = name;
}


int GenericClass::getValue() const {
    return value;
}


void GenericClass::setValue(int value) {
    this->value = value;
}


void GenericClass::displayInfo() const {
    std::cout << "Object Name: " << name << ", Value: " << value << std::endl;
}
