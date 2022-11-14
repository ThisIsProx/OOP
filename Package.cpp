#include "structs.h"
#include "Package.h"

void setPackage(PackageStruct* package) {
    this->package = package;
}
PackageStruct* getPackage() {
    return this->package;
}

void setSizeStruct(int _size) {
    this->size_struct = _size;
}
int getSizeStruct() {
    return this->size_struct;
}