#include "pch.h"
#include "ContactSalaryComparator.h"

int ContactSalaryComparator::compare(Contact a, Contact b)
{
    return a.getSalary() - b.getSalary();
}
