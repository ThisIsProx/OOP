#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"

class Package;

class Package {
private:
    PackageStruct* package;
    long int size_struct;

public:
    /* Constructors */
    Package() {};
    Package(PackageStruct* p, int size_str) {
        package = new PackageStruct[size_struct];
        package = p;
        size_struct = size_str;
    };
    /* End Constructors */

    /* Getters and Setters */

    /* End Getters and Setters */

    /* Methods */

    /* Methods */
};