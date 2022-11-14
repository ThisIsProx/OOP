#pragma once
#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"
#include "Vehicle.h"
class Boat;
class Boat : public Vehicle {
private:
    float speed = 1500;
    int cost = 1500;
public:
    /* Constructors */

    /* End Constructors */

    /* Getters and Setters */

    /* End Getters and Setters */

    /* Methods */
    void aboutVehicle() {
        cout << "Wow, you are richþ. Thank you for your choice" << endl;
    }
    /* Methods */
};