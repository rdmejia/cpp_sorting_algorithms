#pragma once
#include "List.h"
#include "SortedList.h"
#include "Comparator.h"

template<typename T>
class SortedListMerger
{
public:
	static List<T>* mergeLists(List<T>* listA, List<T>* listB, Comparator<T>* comparator) {
		List<T>::Node* i = listA->getHead();
		List<T>::Node* j = listB->getHead();

		List<T>* result = new List<T>();

		while (i != nullptr && j != nullptr) {
			if (comparator->compare(*(i->item), *(j->item)) < 0) {
				result->add(i->item);
				i = i->next;
			}
			else {
				result->add(j->item);
				j = j->next;
			}
		}

		while (i != nullptr) {
			result->add(i->item);
			i = i->next;
		}

		while (j != nullptr) {
			result->add(j->item);
			j = j->next;
		}

		return result;
	}
};

