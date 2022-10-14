#pragma once
#include "Comparator.h"

class IntComparator : public Comparator<int>
{
	virtual int compare(int* a, int* b) {
		return *b - *a;
	}
};

