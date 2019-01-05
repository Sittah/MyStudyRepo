#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
	// CreateLinkedList
	PLINKEDLIST pList = createLinkedList();
	// Set Node
	LINKEDLISTNODE Node;

	displayList(pList);

	// AddNode to LinkedList

	Node.data = 1;
	addNode(pList, 0, Node);
	Node.data = 2;
	addNode(pList, 1, Node);
	Node.data = 3;
	addNode(pList, 2, Node);
	Node.data = 4;
	addNode(pList, 3, Node);
	displayList(pList);

	// remove Node from LinkedList

	puts("\n Remove");
	removeNode(pList, 1);
	displayList(pList);

	// delete linkedList
	puts("\n Delete");
	deleteLinkedList(pList);
	pList = NULL;
	displayList(pList);
	return 0;
}