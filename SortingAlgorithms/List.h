#pragma once
#include "Comparator.h"

template <typename T>
class List
{
public:
	static struct Node {
		T* item;
		Node* next;

		Node(T* item) {
			this->item = item;
			this->next = nullptr;
		}
	};

protected:
	Node* head;
	Node* tail;

	int size = 0;

public:
	List<T>::Node* getHead() {
		return this->head;
	}

	int getSize() {
		return this->size;
	}

	bool isEmpty() {
		return this->size == 0;
	}

	virtual void add(T* item) {
		Node* node = new Node(item);

		if (this->isEmpty()) {
			this->head = this->tail = node;
		}
		else {
			this->tail->next = node;
			this->tail = this->tail->next;
		}

		this->size++;
	}

	T* get(int index) {
		if (index >= this->size || index < 0) {
			return nullptr;
		}

		Node* iterator = this->head;

		int i = 0;
		while (i < index) {
			iterator = iterator->next;
			i++;
		}

		return iterator->item;
	}

	T* remove(int index) {
		if (index >= this->size || index < 0) {
			return nullptr;
		}

		Node** iterator = &this->head;
		Node* previous = nullptr;

		int i = 0;

		while (i < index) {
			previous = *iterator;
			iterator = &((*iterator)->next);
			i++;
		}

		if (this->size - 1 == index) {
			this->tail = previous;
		}

		*iterator = (*iterator)->next;
		this->size--;
	}

	List<T>* bubbleSort(Comparator<T>* comparator) {
		Node** i = &(this->head);

		while (*i != nullptr) {

			Node** j = &(*i)->next;

			while (*j != nullptr) {
				T** itemA = &(*i)->item;
				T** itemB = &(*j)->item;

				if (comparator->compare(**itemA, **itemB) > 0) {
					T* aux = *itemA;
					*itemA = *itemB;
					*itemB = aux;
				}

				j = &(*j)->next;
			}

			i = &(*i)->next;
		}

		return this;
	}
};

