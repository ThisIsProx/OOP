#include "structs.h"
#include "Administrator.h"

void setEmployee(EmployeeAgency empl)
{
    this->employee = empl;
}
EmployeeAgency getEmployee()
{
    return EmployeeAgency(this->employee);
}