#pragma once
#include "Comparator.h"
#include "Contact.h"

class ContactNameComparator :
    public Comparator<Contact>
{
public: 
    int compare(Contact* contactA, Contact* contactB) {
        return contactB->get_name().compare(contactA->get_name());
    }
};

