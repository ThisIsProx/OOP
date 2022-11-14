#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"
#include "Order.h"

class Catalogue;
class Catalogue {
private:
    Package package;
    Countries countries;
public:
    Catalogue(Countries cntries, Package pckg) {
        this->countries = cntries;
        this->package = pckg;
    }
    void showCountries() {
        CountriesStruct* c = countries.getCountries();
        cout << "\nChoice countries: \n";
        for (int i = 0; i < countries.getSizeStruct(); i++) {
            c[i].country_selected();
        };
    };
    void showPackage() {
        PackageStruct* p = package.getPackage();
        cout << "\nChoice package: \n";
        for (int i = 0; i < package.getSizeStruct(); i++) {
            p[i].service_package();
        };
    };
};