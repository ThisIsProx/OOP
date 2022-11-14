#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"
class Person;


class Person {
private:
    string name;
    string surname;
    string password;
    string adminpass = "admin";
    string better_adminpass = "adminadmin";
    long int money = 20000;

public:
    /* Constructors */
    Person() {};
    Person(string name, string surname, string password) {
        this->name = name;
        this->surname = surname;
        this->password = password;
    };
    /* End Constructors */

    /* Getters and Setters */

    /* End Getters and Setters */

    /* Methods */
    bool is_admin() {
        return this->password == this->adminpass;
    };
    bool is_better_admin() {
        return this->password == this->better_adminpass;
    };
    /* End Methods */
};