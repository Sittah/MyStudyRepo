#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"

PARRAYLIST createList(int maxElement_Count)
{
	PARRAYLIST pNewArrayList = NULL;
	if (maxElement_Count > 0)
	{
		pNewArrayList = (PARRAYLIST)malloc(sizeof(ARRAYLIST));
		if (NULL == pNewArrayList)
		{
			puts("pNewArrayList allocation failed!! -- createList()");
			return NULL;
		}
		pNewArrayList->currentArray_Count = 0;
		pNewArrayList->maxArray_Count = maxElement_Count;
		pNewArrayList->pElement = (PARRAYLISTNODE)malloc(sizeof(ARRAYLISTNODE) * maxElement_Count);

		if (NULL == pNewArrayList->pElement)
		{
			puts("pNewArrayList->pElement allocation failed !! -- createList()");
			SafeFree(pNewArrayList);
		}
	}
	return pNewArrayList;
}
void deleteList(PARRAYLIST pArrayL)
{
	int i = 0;
	if (NULL == pArrayL)
	{
		puts("pArrayL is Empty -- deleteList()");
		return;
	}

	for (i = 0; i < pArrayL->currentArray_Count; i++)
	{
		pArrayL->pElement[i].data = 0;
	}
	SafeFree(pArrayL->pElement);
	SafeFree(pArrayL);
}

int addElement(PARRAYLIST pArrayL, int position, ARRAYLISTNODE element)
{
	int ret = FALSE;
	int i = 0;

	if (NULL == pArrayL)
	{
		puts("pArrayList is NULL");
		return FALSE;
	}
	if (FALSE == isArrayListFull(pArrayL))
	{
		if (position >= 0 && position <= pArrayL->currentArray_Count)
		{
			// move to the right Like if I want to put D in position 0 
			// A B C O O ==>  ? A B C 0 ==> D A B C O
			for (i = pArrayL->currentArray_Count - 1; i >= position; i--)
			{
				pArrayL->pElement[i + 1] = pArrayL->pElement[i];
			}

			pArrayL->pElement[position] = element;
			pArrayL->currentArray_Count++;
			ret = TRUE;
		}
		else
		{
			puts("out of range 'position' index ");
		}
	}
	else
	{
		puts("pArrayList is Full -- addElement()");
	}
}

int removeElement(PARRAYLIST pArrayL, int position)
{
	int i = 0;
	int ret = FALSE;
	if (NULL == pArrayL)
	{
		return FALSE;
	}
	// currentCount가 position 보다 작지는 않은지 확인
	
	if (position >= 0 && position < pArrayL->currentArray_Count)
	{
		printf("pElement[4] : %d , pElement[5] : %d \n", pArrayL->pElement[4].data, pArrayL->pElement[5].data);

		for (i = position; i < pArrayL->currentArray_Count; i++)
		{
			pArrayL->pElement[i] = pArrayL->pElement[i + 1];
		}
		pArrayL->currentArray_Count--;
		ret = TRUE;
	}
	else
	{
		puts("Error, range of position index is exceeded !! - removeElement() ");
	}
	return ret;

}
void displayArrayList(PARRAYLIST pArrayL)
{
	if (NULL == pArrayL)
	{
		puts("pArrayL is NULL -- displayArrayLis()");
		return;
	}

	int i = 0;
	ARRAYLISTNODE Node;

	printf("현재 노드의 개수 : %d \n", pArrayL->currentArray_Count);
	for (i = 0; i < pArrayL->currentArray_Count; i++)
	{
		printf("%d 번째 노드 : %d \n", i, pArrayL->pElement[i].data);
	}
	for (i = pArrayL->currentArray_Count; i < pArrayL->maxArray_Count; i++)
	{
		printf("%d 번째 노드 : Empty \n", i);
	}
}
int isArrayListFull(PARRAYLIST pArrayL)
{
	int ret = FALSE;
	if (pArrayL->currentArray_Count >= pArrayL->maxArray_Count)
	{
		ret = TRUE;
	}
	return ret;
}