#pragma once

#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "structs.h"

class Transport;

class Transport : public Vehicle {
private:
    string name;

public:
    /* Constructors */
    Transport() {};
    Transport(string name) {
        this->name;
    }
    /* End Constructors */

    /* Getters and Setters */

    /* End Getters and Setters */

    /* Methods */

    /* Methods */
};