#include "structs.h"
#include "Order.h"

void setFullNameOrd(string fullname) {
    this->fullname = fullname;
};
string getFullNameOrd() {
    return this->fullname;
};

void setOrder(OrderStruct ordr_struct) {
    this->ordr.push_back(ordr_struct);
};
void changeOrder(OrderStruct ordr, int number) {
    this->ordr[number] = ordr;
};
vector<OrderStruct> getOrder() {
    return this->ordr;
};

void setPackage(Package package) {
    this->package_ordr = package;
};

void setCountry(Countries countries) {
    this->countries_ordr = countries;
};

void setVehicle(Vehicle vehicle) {
    this->vehicle_ordr = vehicle;
};

Client* getClient() {
    return this->client_ordr;
}
void setClient(Client* client) {
    this->client_ordr = client;
}