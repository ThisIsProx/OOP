#pragma once
#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"
#include "Vehicle.h"
class Airplane;
class Airplane : public Vehicle {
private:
    float speed = 1000;
    int cost = 100;
public:
    /* Constructors */

    /* End Constructors */

    /* Getters and Setters */

    /* End Getters and Setters */

    /* Methods */
    void aboutVehicle() {
        cout << "The plane is the best for tours. Thank you for your choice." << endl;
    }
    /* Methods */
};