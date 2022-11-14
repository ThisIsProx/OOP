#include "structs.h"
#include "EmployeeAgency.h"

void setEmployeeName(string name)
{
    this->employeeName = name;
}

string getEmployeeName()
{
    return string(this->employeeName);
}