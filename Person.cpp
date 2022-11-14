#include "structs.h"
#include "Person.h"

string getPassword() {
    return this->password;
};
string getFullName() {
    return this->name + " " + this->surname;
};

void setNamae(string name) {
    this->name = name;
};
void setSurname(string surname) {
    this->surname = surname;
};
void setPassword(string password) {
    this->password = password;
};
long int getMoney() {
    return this->money;
};
void setMoney(long int money) {
    this->money = money;
};