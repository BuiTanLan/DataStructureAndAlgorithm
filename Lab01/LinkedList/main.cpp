#include <iostream>
using namespace std;

struct NODE {
	int key;
	NODE* pNext;
};
struct List {
	NODE* pHead;
	NODE* pTail;
};

// Cau 1
List* createList()
{
	List *list = new List();
	list->pHead = nullptr;
	list->pTail = nullptr;
	return list;
}


// Cau 2:
NODE* createNode(int data)
{
	NODE *pNode = new NODE;
	if (pNode != nullptr)
	{
		pNode->key = data;
		pNode->pNext = nullptr;
		return pNode;
	}
	return nullptr;
}


//Cau 3:
bool addHead(List* &L, int data)
{
	NODE *pNode;
	pNode = createNode(data);
	if(pNode == nullptr) return false;
	if( L->pHead == nullptr)
	{
		L->pHead = pNode;
		L->pTail = pNode;
	}
	else
	{
		pNode->pNext = L->pHead;
		L->pHead = pNode;
	}
	return true;
} 


// Cau 4:
bool addTail(List *&L, int data)
{
	NODE *pNode;
	pNode = createNode(data);
	if (pNode == nullptr)
		return false;
	if(L->pTail == nullptr)
	{
		L->pHead = pNode;
		L->pTail = pNode;
	}
	else
	{
		L->pTail->pNext = pNode;
		L->pTail = pNode;
	}
	return true;
}


// Cau 5:
void removeHead(List *&L)
{
	NODE *pNode;
	pNode = L->pHead;
	L->pHead = L->pHead->pNext;
	delete pNode;
}


// Cau 6
void removeTail(List *&L)
{
	NODE *pNode, *qNode;
	pNode = L->pHead;
	int count = 0;
	while (pNode->pNext != nullptr)
	{
		qNode = pNode;
		pNode = pNode->pNext;
		count++;
	}
	if (count == 0)
	{
		pNode = L->pHead = nullptr;
	}
	else
	{
		qNode->pNext = nullptr;
		delete pNode;
	}
}