#pragma once
#include "Comparator.h"
class DoubleComparator :
    public Comparator<double>
{
public: int compare(double a, double b) {
    return a - b;
}
};

