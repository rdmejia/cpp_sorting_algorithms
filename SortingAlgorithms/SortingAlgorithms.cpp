#include "pch.h"
#include "List.h"
#include "Contact.h"
#include <string>
#include "ContactSalaryComparator.h"
#include "ContactNameComparator.h"
#include "SortedList.h"
#include "IntComparator.h"
#include "SortedListMerger.h"

using namespace System;
using std::string;

void MarshalString(String^ s, string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}

List<Contact>* readContacts(List<Contact>* contacts, String^ filePath) {
    array<System::String^>^ lines = System::IO::File::ReadAllLines(filePath);

    for (int i = 0; i < lines->Length; i++) {
        array<String^>^ line = lines[i]->Split(',');

        string name;
        MarshalString(line[0], name);

        double salary = Double::Parse(line[1]);

        Contact* contact = new Contact(i, name, salary);

        contacts->add(contact);
    }

    return contacts;
}

List<Contact>* readContacts(String^ filePath) {
    List<Contact>* contacts = new List<Contact>();

    return readContacts(contacts, filePath);
}

List<Contact>* readContacts(String^ filePath, Comparator<Contact>* comparator) {
    List<Contact>* contacts = new SortedList<Contact>(comparator);

    return readContacts(contacts, filePath);
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
    Comparator<Contact>* comparator = new ContactSalaryComparator();

    List<Contact>* contactsA = readContacts("contacts.csv", comparator);
    List<Contact>* contactsB = readContacts("contacts2.csv", comparator);

    Console::WriteLine("\nContacts A sorted by salary:\n");
    showContacts(contactsA);

    Console::WriteLine("\nContacts B sorted by salary:\n");
    showContacts(contactsB);
    
    List<Contact>* mergedList = SortedListMerger<Contact>::mergeLists(contactsB, contactsA, comparator);

    Console::WriteLine("\nContacts A and Contacts B merged and sorted by salary:\n");
    showContacts(mergedList);

    return 0;
}
