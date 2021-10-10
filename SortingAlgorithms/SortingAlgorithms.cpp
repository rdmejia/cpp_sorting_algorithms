#include "pch.h"
#include "List.h"
#include "Contact.h"
#include <string>
#include "ContactSalaryComparator.h"
#include "ContactNameComparator.h"

using namespace System;
using std::string;

void MarshalString(String^ s, string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}

List<Contact>* readContacts(String^ filePath) {
    List<Contact>* contacts = new List<Contact>();

    array<System::String ^> ^lines = System::IO::File::ReadAllLines(filePath);

    for (int i = 0; i < lines->Length; i++) {
        array<String^> ^line = lines[i]->Split(',');
        
        string name;
        MarshalString(line[0], name);

        double salary = Double::Parse(line[1]);

        Contact* contact = new Contact(i, name, salary);

        contacts->add(contact);
    }

    return contacts;
}

void showContacts(List<Contact>* contacts) {
    Console::WriteLine("id\tName\t\tSalary");

    for (int i = 0; i < contacts->getSize(); i++) {
        Contact* contact = contacts->get(i);

        String^ name = gcnew String(contact->getName().c_str());

        Console::WriteLine("{0}\t{1}\t{2}", contact->getId(), name, contact->getSalary());
    }
}

int main(array<System::String ^> ^args)
{
    List<Contact>* contacts = readContacts("contacts.csv");

    Console::WriteLine("Contacts original sort:\n");
    showContacts(contacts);

    contacts = contacts->bubbleSort(new ContactSalaryComparator());
    Console::WriteLine("\nContacts sorted by salary:\n");
    showContacts(contacts);

    contacts = contacts->bubbleSort(new ContactNameComparator());
    Console::WriteLine("\nContacts sorted by name:\n");
    showContacts(contacts);

    return 0;
}
