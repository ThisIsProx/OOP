#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"

class Vehicle;

class Vehicle {
private:
    VehicleStruct* vehicle;
    long int size_struct;
    string name;

public:
    /* Constructors */
    Vehicle() {};
    Vehicle(VehicleStruct* v, int size_str) {
        vehicle = new VehicleStruct[size_struct];
        vehicle = v;
        size_struct = size_str;
    };
    /* End Constructors */

    /* Getters and Setters */

    /* End Getters and Setters */

    /* Methods */
    virtual void aboutVehicle() {
        cout << "You have not choose any vehicle." <<
            "The vehicles of our Tour Agency are very convenient and inexpensive, choose any" << endl;
    }
    void updateVehicle(VehicleStruct vehicle) {
        for (int i = 0; i < getSizeStruct(); i++)
        {
            if (vehicle.vehicle_id == this->vehicle[i].vehicle_id)
            {
                cout << "Updated";
                this->vehicle[i].vehicle_status = true;
            }
        }
    }
    /* Methods */
};