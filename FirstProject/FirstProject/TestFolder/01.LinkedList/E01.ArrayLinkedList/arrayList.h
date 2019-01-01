/* Array 형식의 연결리스트 */

#ifndef _ARRAYLIST_DEF_
#define _ARRAYLIST_DEF_

typedef struct ArrayListNodeType
{
	int data;
} ARRAYLISTNODE, *PARRAYLISTNODE;

typedef struct ArrayListType
{
	int maxArray_Count;
	int currentArray_Count;
	PARRAYLISTNODE pElement;
} ARRAYLIST, *PARRAYLIST;
PARRAYLIST createList(int maxElement_Count);
void deleteList(PARRAYLIST pArrayL);
int addElement(PARRAYLIST pArrayL, int position, ARRAYLISTNODE pElement);
void displayArrayList(PARRAYLIST pArrayL);
int removeElement(PARRAYLIST pArrayL, int position);

int isArrayListFull(PARRAYLIST pArrayL);


#endif

#ifndef _COMMON_DEF_
enum { FALSE = 0, TRUE = 1};
#include "../../commonFunc.h"
#define SafeFree(p) saferFree((void **) &(p))
#endif