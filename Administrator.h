#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"
#include "Person.h"
#include "EmployeeAgency.h"
#include "Client.h"

class Administrator;
class Administrator : public Person, private EmployeeAgency {
private:
    EmployeeAgency employee;
    int wage = 4000;
public:
    /* Constructors */
    Administrator() {};
    Administrator(string name, string surname, string password) : Person(name, surname, password) {};
    /* End Constructors */


    /* Getters and Setters */
   
    /*End Getters and Setters */

    /* Methods */
    void showOrder(Order* ord)
    {
        for (int i = 0; i < ord->getOrder().size(); i++)
        {
            ord->getOrder()[i].print_order();
        }
    };
    void changeStatus(int number_app, string status_ordr, Client* cl, Order* ord)
    {
        vector<OrderStruct> orders = ord->getOrder();
        if (status_ordr == "Aprove") {
            for (int i = 0; i < orders.size(); i++)
            {
                if (orders[i]._id == number_app)
                {
                    orders[i].status = status_ordr;
                    ord->changeOrder(orders[i], i);
                    cl->setMoney(cl->getMoney() - orders[i].price);
                    return;
                }
            }
        }
        else if (status_ordr == "Reject")
        {
            for (int i = 0; i < orders.size(); i++)
            {
                if (orders[i]._id == number_app)
                {
                    orders[i].status = status_ordr;
                    ord->changeOrder(orders[i], i);
                    return;
                }
            }
        }
    };
    Administrator operator--() {
        this->wage = wage - 500;
        return (*this);
        cout << this->employeeName << " wage was reduced" << endl;
    }

    Administrator operator + (Administrator& adm) {
        Administrator temp;
        temp.wage = (this->wage + adm.wage) / 2;
        return temp;
        cout << "Medium wage is " << temp.wage << endl;
    }
    Administrator operator++() {
        this->wage += 1000;
        return (*this);
        cout << "WOW! You raised wage" << endl;
    }
    Administrator operator - (Administrator& adm) {
        Administrator temp;
        temp.wage = (this->wage - adm.wage);
        return temp;
        cout << "The wage difference is " << temp.wage << endl;
    }
    /* End Methods */
};