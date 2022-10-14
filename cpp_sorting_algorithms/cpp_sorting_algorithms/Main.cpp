#include "pch.h"

#include "List.h"
#include "LinkedList.h"
#include "Contact.h"
#include "ContactNameComparator.h"

using namespace System;

using std::string;

static int id = 0;

List<Contact>* contacts = new LinkedList<Contact>();
List<Contact>* contacts_by_salary = new LinkedList<Contact>();
List<Contact>* contacts_by_name = new LinkedList<Contact>();

void marshal_string(String^ s, string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}

int compare_contact_by_salary(Contact* contactA, Contact* contactB) {
    return contactA->get_salary() - contactB->get_salary();
}

void read_contacts(String^ file_path) {
	array<System::String^>^ lines = System::IO::File::ReadAllLines(file_path);

    for (int i = 0; i < lines->Length; i++) {
        array<String^>^ line = lines[i]->Split(',');

        string name;
        
        marshal_string(line[0], name);

        double salary = Double::Parse(line[1]);

        Contact* contact = new Contact(id, name, salary);

        contacts->add(contact);
        contacts_by_salary->add(contact);
        contacts_by_name->add(contact);

        id++;
    }

    contacts_by_salary->bubble_sort(compare_contact_by_salary);
    contacts_by_name->merge_sort(new ContactNameComparator());
}

void show_contact(Contact* contact) {
    String^ name = gcnew String(contact->get_name().c_str());

    Console::WriteLine("{0}\t{1}\t{2}", contact->get_id(), name, contact->get_salary());
}

void show_contacts(List<Contact>* contacts) {
    Console::WriteLine("id\tName\t\tSalary");
    Console::WriteLine("------------------------------------------");

    contacts->for_each(show_contact);
}

int main(array<System::String^>^ args) {

    read_contacts("contacts.csv");

    Console::WriteLine("\n===============All Contacts===============");
    show_contacts(contacts);
    Console::WriteLine("\n===============By Salary==================");
    show_contacts(contacts_by_salary);
    Console::WriteLine("\n===============By Name====================");
    show_contacts(contacts_by_name);

    Console::WriteLine("\n======Setting name to Lionel Messi========\n");
    contacts->get(0)->set_name("Lionel Messi");

    Console::WriteLine("\n===============All Contacts===============");
    show_contacts(contacts);
    Console::WriteLine("\n===============By Salary==================");
    show_contacts(contacts_by_salary);
    Console::WriteLine("\n===============By Name====================");
    show_contacts(contacts_by_name);

	return 0;
}