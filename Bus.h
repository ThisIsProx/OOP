#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"
#include "Vehicle.h"
class Bus;
class Bus : public Vehicle {
private:
    float speed = 500;
    int cost = 500;
public:
    /* Constructors */

    /* End Constructors */

    /* Getters and Setters */

    /* End Getters and Setters */

    /* Methods */
    void aboutVehicle() {
        cout << "Great choice! Cheap and fast. Thank you for your choice." << endl;
    }
    /* Methods */
};