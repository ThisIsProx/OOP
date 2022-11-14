#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"
#include "Person.h"
#include "Order.h"

class Client;

class Client : public Person {
private:
    string pasport_id;
    PackageStruct choice_client_package;
    CountriesStruct choice_client_countries;
    VehicleStruct choice_client_vehicle;
    Package package_client_side;
    Countries countries_client_side;
    Vehicle vehicle_client_side;
    Order ordr;

public:
    Client() {};
    /* Constructors */
    Client(string name, string surname, string password, Package package, Countries countries) : Person(name, surname, password) {
        this->package_client_side = package;
        this->countries_client_side = countries;
    };
    /* End Constructors */

    /* Getters and Setters */
    
    /* End Getters and Setters */

    /* Methods */
    PackageStruct getPackageByNumber(int number) {
        PackageStruct* p = package_client_side.getPackage();
        for (int i = 0; i < package_client_side.getSizeStruct(); i++) {
            if (p[i].package_id == number) {
                return p[i];
            };
        };
    };
    CountriesStruct getCountriesByNumber(int number) {
        CountriesStruct* c = countries_client_side.getCountries();
        for (int i = 0; i < countries_client_side.getSizeStruct(); i++) {
            if (c[i].country_id == number) {
                return c[i];
            };
        };
    };
    VehicleStruct getVehicleByNumber(int number) {
        VehicleStruct* v = vehicle_client_side.getVehicle();
        for (int i = 0; i < vehicle_client_side.getSizeStruct(); i++) {
            if (v[i].vehicle_id == number) {
                return v[i];
            };
        };
    };
    void showPackage() {
        PackageStruct* p = package_client_side.getPackage();
        for (int i = 0; i < package_client_side.getSizeStruct(); i++) {
            p[i].service_package();
        };
    };
    void showCountries() {
        CountriesStruct* c = countries_client_side.getCountries();
        for (int i = 0; i < countries_client_side.getSizeStruct(); i++) {
            c[i].country_selected();
        };
    };
    void showOrder() {
        for (int i = 0; i < this->ordr.getOrder().size(); i++)
        {
            this->ordr.getOrder()[i].print_order();
        }
    }
    /* End Methods */
};