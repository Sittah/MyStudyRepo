#ifndef _CIRCULARLIST_DEF_
#define _CIRCULARLIST_DEF_

typedef struct CircularListNodeType
{
	int data;
	struct CircularListNodeType *pList;
} CIRCULARNODE, *PCIRCULARNODE;

typedef struct CircularListType
{
	int currentNodeCount;
	PCIRCULARNODE headPointer;
} CIRCULARLIST, *PCIRCULARLIST;
PCIRCULARLIST createCircularList();
int addElement(PCIRCULARLIST pCList, int position, CIRCULARNODE element);
int removeElement(PCIRCULARLIST pCList, int position);
void displayList(PCIRCULARLIST pCList);
void deleteElement(PCIRCULARLIST pCList);

#endif

#ifndef _COMMON_DEF_
#define _COMMON_DEF_
enum { FALSE = 0 , TRUE = 1};
#include "../../commonFunc.h"
#define SafeFree(p) saferFree((void **)(&p));
#endif