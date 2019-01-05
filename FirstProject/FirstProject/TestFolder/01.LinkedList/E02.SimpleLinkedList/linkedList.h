/* Node를 이용한 LinkedList  */

#ifndef _LINKEDLIST_DEF_
#define _LINKEDLIST_DEF_

typedef struct LinkedListNodeType
{
	int data;
	struct LinkedListNodeType *pLink; /* Point Next Node */
} LINKEDLISTNODE, *PLINKEDLISTNODE;

typedef struct LinkedListType
{
	int currentNodeCount;		/* How many connected on LinkedList */
	LINKEDLISTNODE headerNode;
	
} LINKEDLIST, *PLINKEDLIST;

PLINKEDLIST createLinkedList();
int addNode(PLINKEDLIST PLinked, int position, LINKEDLISTNODE newNodeElement);
int removeNode(PLINKEDLIST pLinked, int position);

void displayList(PLINKEDLIST PLinked);
void deleteLinkedList(PLINKEDLIST PLinked);

#endif

#ifndef _COMMON_DEF_
#define _COMMON_DEF_
enum { FALSE = 0, TRUE = 1};
#include "../../commonFunc.h"
#define SafeFree(p) saferFree((void **)(&p))
#endif