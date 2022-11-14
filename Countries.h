#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"

class Countries;

class Countries {
private:
    CountriesStruct* countries;
    long int size_struct;

public:
    /* Constructors */
    Countries() {};
    Countries(CountriesStruct* c, int size_str) {
        countries = new CountriesStruct[size_struct];
        countries = c;
        size_struct = size_str;
    };
    /* End Constructors */

    /* Getters and Setters */
    
    /* End Getters and Setters */

    /* Methods */

    /* Methods */
};