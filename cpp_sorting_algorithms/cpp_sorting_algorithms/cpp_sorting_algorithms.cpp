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

bool between_5_and_8(int* number) {
    return *number >= 5 && *number < 8;
}

int main(array<System::String^>^ args)
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
    numbers->add(new int(-1));
    // numbers->add(new int(1));

    numbers->for_each(print_number);

    cout << "============================\n";

    // numbers->insert(0, new int(1));
    // numbers->insert(0, new int(2));
    // numbers->insert(5, new int(5));

    numbers->for_each(print_number);

    cout << "=========>= 5 && < 8 ========\n";

    numbers
        ->filter(between_5_and_8)
        ->for_each(print_number);

    cout << "============================\n";

    Comparator<int>* comparator = new IntComparator();

    numbers->merge_sort(comparator);
    numbers->bubble_sort(compare);

    for (Iterator<int>* i = numbers->iterator(); i->has_next(); i = i->next()) {
        print_number(i->value());
    }

    int* negative_1 = numbers->binary_search([](int* x) {
        return -1 - *x;
    });

    if (negative_1) {
        cout << "Found -1: " << *negative_1 << "\n";
    }
    else {
        cout << "Did not found -1\n";
    }

    int* negative_2 = numbers->binary_search([](int* x) -> int {
        return -2 - *x;
    });

    if (negative_2) {
        cout << "Found -2: " << *negative_2 << "\n";
    }
    else {
        cout << "Did not found -2\n";
    }

    int* positive_7 = numbers->binary_search([](int* x) -> int {
        return 7 - *x;
    });

    if (positive_7) {
        cout << "Found 7: " << *positive_7 << "\n";
    }
    else {
        cout << "Did not found 7\n";
    }

    return 0;
}
