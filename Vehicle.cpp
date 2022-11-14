#include "structs.h"
#include "Vehicle.h"

/* Getters and Setters */
void setVehicle(VehicleStruct* vehicle) {
    this->vehicle = vehicle;
}
VehicleStruct* getVehicle() {
    return this->vehicle;
}
void setSizeStruct(int _size) {
    this->size_struct = _size;
}
int getSizeStruct() {
    return this->size_struct;
}
/* End Getters and Setters */