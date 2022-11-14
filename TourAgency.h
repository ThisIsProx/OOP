#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"
#include "Administrator.h"

class TourAgency;
class TourAgency {
private:
    Administrator* admin;
    string name_tours;
    string lastname_tours;
public:
    TourAgency(Administrator* admin = nullptr) :admin(admin) {}
};