#include "structs.h"
#include "Client.h"

string getPasportId() {
    return this->pasport_id;
};
void setPasportId(string pasport_id) {
    this->pasport_id = pasport_id;
};

void setOrdr(Order ord) {
    this->ordr = ord;
}
Order getOrdr() {
    return this->ordr;
}

PackageStruct getChoiceClientPackage() {
    return this->choice_client_package;
};
CountriesStruct getChoiceClientCountries() {
    return this->choice_client_countries;
};
VehicleStruct getChoiceClientVehicle() {
    return this->choice_client_vehicle;
};
void setChoiceClientPackage(PackageStruct choice_client_package) {
    this->choice_client_package = choice_client_package;
};
void setChoiceClientCountries(CountriesStruct choice_client_countries) {
    this->choice_client_countries = choice_client_countries;
};
void setChoiceClientVehicle(VehicleStruct choice_client_vehicle) {
    this->choice_client_vehicle = choice_client_vehicle;
};