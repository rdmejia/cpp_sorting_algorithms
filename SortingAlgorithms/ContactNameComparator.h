#pragma once
#include "Comparator.h"
#include "Contact.h"
#include <string>

using std::string;

class ContactNameComparator :
    public Comparator<Contact>
{
public:
    virtual int compare(Contact a, Contact b) {
        return a.getName().compare(b.getName());
    }
};

