#include "structs.h"
#include "Countries.h"

void setCountries(CountriesStruct* countries) {
    this->countries = countries;
}
CountriesStruct* getCountries() {
    return this->countries;
}

void setSizeStruct(int _size) {
    this->size_struct = _size;
}
int getSizeStruct() {
    return this->size_struct;
}