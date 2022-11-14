#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"
#include "Vehicle.h"
#include "Countries.h"
#include "Package.h"


class Order;

class Order {
private:
    string fullname;
    string pasport_id;
    Package package_ordr;
    Countries countries_ordr;
    Vehicle vehicle_ordr;
    Client* client_ordr;
    vector<OrderStruct> ordr;

public:
    /* Constructors */
    Order() {};
    Order(string fullname, string pasp_id) {
        this->fullname = fullname;
        this->pasport_id = pasp_id;
    };
    /* End Constructors */

    /* Getters and Setters */


    /* End Getters and Setters , const string filepath*/

    /* Methods */
    void file_txt(OrderStruct order, const string filepath)
    {
        ofstream file(filepath, ios::app);
        file
            << "Order ID: " << order._id << endl
            << "Your full name: " << order.fullname << endl
            << "Your passport ID: " << order.pasport_id << endl
            << "Trip information" << endl
            << "Country: " << order.countries.country << endl
            << "Hotel: " << order.package.hotel << endl
            << "Meal type: " << order.package.meal_type << endl
            << "Vehicle type: " << order.vehicle.vehicle_type << endl
            << "Total price: " << order.price << endl
            << "Number days in trip: " << order.package.days << endl
            << "------------------------------" << endl;
        file.close();
    }
    void file_dat(OrderStruct order, const string filepath)
    {
        ofstream file(filepath, ios::out | ios::binary | ios::app);
        for (int i = 0; i < this->ordr.size(); i++)
        {
            file << setw(12) <<
                this->ordr[i]._id << setw(10) <<
                this->ordr[i].fullname << setw(10) <<
                this->ordr[i].pasport_id << setw(10) << endl;
        }
        file.close();
    }
    void read_file(string fullname, const string filepath) {
        ifstream read(filepath, ios::app);
        try
        {
            if (read.is_open())
            {
                read >> fullname;
            }
            else if (!read.is_open())
            {
                throw "ERROR";
            }
        }
        catch (string warning)
        {
            cout << warning << endl;
        }
        read.close();
    }
    void createOrder(OrderStruct order) {
        file_txt(order, "order.txt");
        file_dat(order, "order.dat");
        setOrder(order);
    };
    /* End Methods */
};