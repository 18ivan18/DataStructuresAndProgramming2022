#include <iostream>

struct Node;

void printLinkedList(const Node* const lstHead, const Node* const lstTail);
void printLinkedListReversed(const Node* const lstHead, const Node* const lstTail);
void swapPointers(Node*& lstHead, Node*& lstTail);
void reversePart(Node*& lstHead, Node*& lstTail, Node* startingNode, Node* endingNode);
void reverse(Node*& lstHead, Node*& lstTail);
void swapListParts(Node*& lstHead, Node*& lstTail, Node* breakStart);
int getLength(Node* lstHead);
Node* getPointerToElement(Node*& lstHead, int index);
void shuffle(Node*& lstHead, Node*& lstTail);

void initializeList(Node*& head, Node*& tail);

struct Node
{
	int fData;
	Node* pNext = nullptr;
	Node* pPrev = nullptr;
};

int main()
{
	Node* head = nullptr;
	Node* tail = nullptr;

	initializeList(head, tail);

	printLinkedList(head, tail);
	std::cout << std::endl;

	//Problem 4 demonstration: reverses the elements on indexes 1 to 3
	//1 2 3 4 5 -> 1 4 3 2 5
	reversePart(head, tail, getPointerToElement(head, 1), getPointerToElement(head, 3)); 

	printLinkedList(head, tail);
	std::cout << std::endl;

	// More difficult problems: Problem 1 demonstration:
	// 1 4 3 2 5 -> 5 2 1 4 3
	shuffle(head, tail);

	printLinkedList(head, tail);
	std::cout << std::endl;
}

// More difficult problems: Problem 1 solution.
void shuffle(Node*& lstHead, Node*& lstTail)
{
	int shiftedElementsBeginning = ceil(((double)getLength(lstHead)) / 2);

	Node* shiftedPartBeginning = getPointerToElement(lstHead, shiftedElementsBeginning);

	Node* prevTail = lstTail;

	swapListParts(lstHead, lstTail, shiftedPartBeginning);

	reversePart(lstHead, lstTail, lstHead, prevTail);
}

// Problem 4 solution
void reversePart(Node*& lstHead, Node*& lstTail, Node* startingNode, Node* endingNode)
{
	Node* beforeRevesedPart = startingNode->pPrev;
	Node* afterReversedPart = endingNode->pNext;

	Node* current = endingNode;

	while (current != beforeRevesedPart)
	{
		Node* temp = current->pPrev;
		swapPointers(current->pNext, current->pPrev);
		current = temp;
	}

	if (beforeRevesedPart != nullptr)
	{
		beforeRevesedPart->pNext = endingNode;
	}
	else
	{
		lstHead = endingNode;
	}

	if (afterReversedPart != nullptr)
	{
		afterReversedPart->pPrev = startingNode;
	}
	else
	{
		lstTail = startingNode;
	}

	endingNode->pPrev = beforeRevesedPart;
	startingNode->pNext = afterReversedPart;
}

void printLinkedListReversed(const Node* const lstHead, const Node* const lstTail)
{
	const Node* current = lstTail;

	while (current != nullptr)
	{
		std::cout << current->fData << " ";
		current = current->pPrev;
	}
}

void printLinkedList(const Node* const lstHead, const Node* const lstTail)
{
	const Node* current = lstHead;

	while (current != nullptr)
	{
		std::cout << current->fData << " ";
		current = current->pNext;
	}
}

void reverse(Node*& lstHead, Node*& lstTail)
{
	swapPointers(lstHead, lstTail);

	Node* current = lstHead;

	while (current != lstTail)
	{
		Node* temp = current->pPrev;
		swapPointers(current->pNext, current->pPrev);
		current = temp;
	}

	swapPointers(current->pNext, current->pPrev);
}


void swapListParts(Node*& lstHead, Node*& lstTail, Node* breakStart)
{
	if (lstHead == breakStart)
	{
		return;
	}

	Node* prevTail = lstTail;
	Node* prevHead = lstHead;

	lstHead = breakStart;
	lstTail = breakStart->pPrev;

	lstHead->pPrev = nullptr;
	lstTail->pNext = nullptr;

	prevTail->pNext = prevHead;
	prevHead->pPrev = prevTail;
}

void swapPointers(Node*& lstHead, Node*& lstTail)
{
	Node* temp = lstHead;
	lstHead = lstTail;
	lstTail = temp;
}

void initializeList(Node*& head, Node*& tail)
{
	Node* list = new Node();
	list->fData = 1;
	list->pPrev = nullptr;

	list->pNext = new Node();
	list->pNext->fData = 2;
	list->pNext->pPrev = list;

	list->pNext->pNext = new Node();
	list->pNext->pNext->fData = 3;
	list->pNext->pNext->pPrev = list->pNext;

	list->pNext->pNext->pNext = new Node();
	list->pNext->pNext->pNext->fData = 4;
	list->pNext->pNext->pNext->pPrev = list->pNext->pNext;

	list->pNext->pNext->pNext->pNext = new Node();
	list->pNext->pNext->pNext->pNext->fData = 5;
	list->pNext->pNext->pNext->pNext->pPrev = list->pNext->pNext->pNext;
	list->pNext->pNext->pNext->pNext->pNext = nullptr;

	head = list;
	tail = list->pNext->pNext->pNext->pNext;
}

Node* getPointerToElement(Node*& lstHead, int index)
{
	Node* current = lstHead;

	for (int i = 0; i < index; i++)
	{
		current = current->pNext;
	}

	return current;
}

int getLength(Node* lstHead)
{
	Node* current = lstHead;

	int length = 0;

	while (current != nullptr)
	{
		length++;
		current = current->pNext;
	}

	return length;
}
