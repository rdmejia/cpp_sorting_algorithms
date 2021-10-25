#pragma once
#include "List.h"
#include "Comparator.h"
#include "List.h"

template <typename T>
class SortedList : public List<T>
{
    Comparator<T>* comparator;

public:
    SortedList(Comparator<T>* comparator) {
        this->comparator = comparator;
    }

	virtual void add(T* item) {
		Node* node = new Node(item);

		if (this->isEmpty()) {
			this->head = node;
		}
		else {
			Node** iterator = &this->head;

			while (*iterator != nullptr &&
				comparator->compare(*node->item, *(*iterator)->item) > 0) {
				iterator = &(*iterator)->next;
			}

			node->next = *iterator;
			*iterator = node;
		}

		this->size++;
	}
};

