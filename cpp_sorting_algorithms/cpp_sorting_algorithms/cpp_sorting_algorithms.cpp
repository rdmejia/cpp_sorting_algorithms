#include "pch.h"

#include <iostream>
#include "List.h"
#include "LinkedList.h"
#include <string.h>
#include "Comparator.h"
#include "IntComparator.h"

using namespace System;

using std::cout;

void print_number(int* x) {
    Console::WriteLine(*x);
}

int compare(int* a, int* b) {
    return *a - *b;
}

int main(array<System::String ^> ^args)
{
    List<int>* numbers = new LinkedList<int>();

    numbers->add(new int(5));
    numbers->add(new int(6));
    numbers->add(new int(7));
    numbers->add(new int(8));
    // numbers->add(new int(9));
    numbers->add(new int(4));
    numbers->add(new int(3));
    numbers->add(new int(2));
    numbers->add(new int(1));
    // numbers->add(new int(1));

    numbers->for_each(print_number);

    cout << "============================\n";

    // numbers->insert(0, new int(1));
    // numbers->insert(0, new int(2));
    // numbers->insert(5, new int(5));

    numbers->for_each(print_number);

    cout << "============================\n";

    Comparator<int>* comparator = new IntComparator();

    numbers->merge_sort(comparator);
    numbers->bubble_sort(compare);

    for (Iterator<int>* i = numbers->iterator(); i->has_next(); i = i->next()) {
        print_number(i->value());
    }

    return 0;
}
