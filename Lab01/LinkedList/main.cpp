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
	if (L->pHead == nullptr) L->pTail = nullptr;
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
		L->pTail = L->pHead = nullptr;
	}
	else
	{
		qNode->pNext = nullptr;
		L->pTail = qNode;
		delete pNode;
	}
}


// Cau 7 
void removeAll(List* &L)
{
	NODE *pNode;
	while (L->pHead != nullptr)
	{
		pNode = L->pHead;
		L->pHead = L->pHead->pNext;
		delete pNode;
	}
	L->pTail = L->pHead;
}


// Cau 8:
void printList(List* L)
{
	NODE *pNode;
	pNode = L->pHead;
	while (pNode != nullptr)
	{
		cout<<pNode->key<<" ";
		pNode = pNode->pNext;
	}
}


// Cau 9
int countElements(List* L)
{
	NODE *pNode;
	int count = 0;
	pNode = L->pHead;
	while (pNode != nullptr)
	{
		count++;
		pNode = pNode->pNext;
	}
	return count;
}


//Cau 10
List* reverseList(List* L)
{
	List* reverseList = new List(*L);
	NODE *pCurrent = reverseList->pHead;
	NODE *reverseTail = reverseList->pHead;
	NODE *pNext = nullptr;
	NODE *pPrev = nullptr;
	while (pCurrent != nullptr)
	{
		pNext = pCurrent->pNext;
		pCurrent->pNext = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;
	}
	reverseList->pHead = pPrev;
	reverseList->pTail = reverseTail;
	return reverseList;
}

// Cau 11
void removeDuplicate(List *&L)
{
	NODE *pNode, *qNode, *pDuplicate;
	pNode = L->pHead;

	while (pNode != nullptr &&  pNode->pNext != nullptr)
	{
		qNode = pNode;
		while(qNode != nullptr)
		{
			if(pNode->key == qNode->pNext->key)
			{
				pDuplicate = qNode->pNext;
				qNode->pNext = qNode->pNext->pNext;
				delete (pDuplicate);				
			}
			else
			{
				qNode = pNode->pNext;
			}
		}

		pNode = pNode->pNext;
	}
}


// Cau 12
bool removeElement(List *&L, int key)
{
	bool isExist = false;
	NODE *pNode = L->pHead;
	NODE *pPrev = nullptr;

	if(pNode != nullptr && pNode->key == key)
	{
		removeHead(L);
		return true;
	}
	while( pNode != nullptr && pNode->key != key)
	{
		pPrev = pNode;
		pNode = pNode->pNext;
	}
	if(pNode == nullptr) return false;
	if(pNode->key == key)
	{
		pPrev->pNext = pNode->pNext;
		return true;
	}
	return false;
}
