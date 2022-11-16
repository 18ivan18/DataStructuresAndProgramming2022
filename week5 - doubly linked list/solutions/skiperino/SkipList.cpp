#include "SkipList.h"
#include <cmath>
#include <cassert>

template <typename T>
void SkipList<T>::copy(const SkipList &other)
{
	if (!other.head)
	{
		this->head = nullptr;
		return;
	}

	Node *otherIndex = other.head;
	Node *index = this->head = otherIndex;
	Node *prevSpeedup = nullptr;
	while (otherIndex->next)
	{
		if (otherIndex->skip && !prevSpeedup)
		{
			prevSpeedup = index;
		}
		else if (otherIndex->skip && prevSpeedup)
		{
			prevSpeedup->skip = index;
			prevSpeedup = index;
		}
		index->next = new Node{otherIndex->next->data};
		otherIndex = otherIndex->next;
	}
}

template <typename T>
void SkipList<T>::erase()
{
	Node *toDelete;
	while (head)
	{
		toDelete = head;
		head = head->next;
		delete toDelete;
	}
}

template <typename T>
SkipList<T>::SkipList() : head(nullptr), length(0)
{
}

template <typename T>
SkipList<T>::SkipList(const SkipList &other)
{
	copy(other);
}

template <typename T>
SkipList<T> &SkipList<T>::operator=(const SkipList &other)
{
	if (*this->head != *other.head)
	{
		erase();
		copy(other);
	}
	return *this;
}

template <typename T>
size_t SkipList<T>::size() const
{
	return length;
}

template <typename T>
void SkipList<T>::insertSorted(const T &element)
{
	Node *index = head;
	if (!index)
	{
		head = new Node{element};
		return;
	}
	while (index && index->next)
	{
		if (index->skip)
		{
			index = index->skip;
		}
		else
		{
			index = index->next;
		}
	}
	assert(index->data < element);
	index->next = new Node{element};
	length++;
}

template <typename T>
void SkipList<T>::speedUp() const
{
	int counter = 0;
	Node *index = head;
	Node *save = head;
	while (index)
	{
		if (counter == round(sqrt(this->length)))
		{
			save->skip = index;
			save = index;
			counter = 0;
			index = index->next;
		}
		else
		{
			counter++;
			index = index->next;
		}
	}
}

template <typename T>
int SkipList<T>::find(const T &element, bool (*comparator)(T a, T b))
{
	Node *index = head;
	int counter = 0;

	while (index)
	{
		if (index->data == element)
		{
			return counter;
		}
		if (index->skip && comparator(index->next->data, element) && comparator(index->skip->data, element))
		{
			index = index->skip;
			counter += round(sqrt(length)) + 1;
		}
		else if (index->skip && !comparator(index->next->data, element))
		{
			return -1;
		}
		else if (index->skip && index->skip->data == element)
		{
			return counter + round(sqrt(length));
		}
		else
		{
			index = index->next;
			counter++;
		}
	}

	return -1;
}
