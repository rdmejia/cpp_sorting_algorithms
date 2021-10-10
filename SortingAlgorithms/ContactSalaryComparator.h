#pragma once
#include "Comparator.h"
#include "Contact.h"

class ContactSalaryComparator :
    public Comparator<Contact>
{
    // Inherited via Comparator
    virtual int compare(Contact a, Contact b) override;
};

