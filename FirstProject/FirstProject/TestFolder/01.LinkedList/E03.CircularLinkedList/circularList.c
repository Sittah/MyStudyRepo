#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularList.h"



PCIRCULARLIST createCircularList()
{
	PCIRCULARLIST pList = (PCIRCULARLIST) malloc(sizeof(CIRCULARLIST));
	if (NULL == pList)
	{
		puts("Allocation is failed -- createCircularList() ");
		return NULL;
	}
	else
	{
		memset(pList, 0, sizeof(CIRCULARLIST));
	}
	return pList;
}

int addElement(PCIRCULARLIST pCList, int position, CIRCULARNODE element)
{
	if (NULL == pCList) return FALSE;
	int ret = FALSE;
	int i;
	PCIRCULARNODE pNewNode = NULL, pHeadNode = NULL, pPreNode = NULL, pLastNode = NULL;
	if (position >= 0 && position <= pCList->currentNodeCount)
	{
		pNewNode = (PCIRCULARNODE)malloc(sizeof(CIRCULARNODE));
		if (NULL == pNewNode)
		{
			puts("pNewNode allocation failed!! -- addElement()");
			return FALSE;
		}
		
		*pNewNode = element;
		pNewNode->pList = NULL;

		if (position == 0)
		{
			if (pCList->currentNodeCount == 0)
			{
				pCList->headPointer = pNewNode;
				pNewNode->pList = pNewNode;
			}
			else
			{
				pHeadNode = pCList->headPointer;
				pLastNode = pHeadNode->pList;

				while (pLastNode->pList != pHeadNode)
				{
					pLastNode = pLastNode->pList;
				}
				pNewNode->pList = pHeadNode;
				pCList->headPointer = pNewNode;
				pLastNode->pList = pNewNode;
			}
		}
		// position != 0
		else
		{
			pPreNode = pCList->headPointer;

			/*
				position -1 이 붙는이유는 헤드포인터를 사용했기 때문이다.
				헤드노드(더미노드)가 있지 않기때문에 일단 실제 첫번째 노드값에 접근한 상태로 시작해야하기때문 !
				헤드노드가 있으면 실제 첫노드 접근하지 않은채로 시작할 수 있다 (pPrenode = pCList->headNode;)
			*/
			for (i = 0; i < position -1; i++)
			{
				pPreNode = pPreNode->pList;
			}
			pNewNode->pList = pPreNode->pList;
			pPreNode->pList = pNewNode;

		}
		pCList->currentNodeCount++;
		ret = TRUE;
	}
	// Out of range of position
	else
	{
		puts("Out of range of position -- addElement()");
	}
	return ret;
}

int removeElement(PCIRCULARLIST pCList, int position)
{
	int ret = FALSE;
	int i;
	PCIRCULARNODE pPreNode = NULL, pDelNode = NULL, pHeadNode = NULL, pLastNode = NULL;
	
	if (NULL == pCList) return FALSE;
	
	if (position >= 0 && position < pCList->currentNodeCount)
	{
		if (position == 0)
		{
			pDelNode = pCList->headPointer;
			if (pCList->currentNodeCount == 1)
			{
				pDelNode->pList = NULL;
				pCList->headPointer = NULL;
			}
			else
			{
				pHeadNode = pCList->headPointer;
				pLastNode = pHeadNode->pList;
				while (pLastNode->pList != pHeadNode)
				{
					pLastNode = pLastNode->pList;
				}
				pLastNode->pList = pDelNode->pList;
				pCList->headPointer = pDelNode->pList;
			}
		}
		// position > 0
		else
		{
			pPreNode = pCList->headPointer;

			for (i = 0; i < position - 1; i++)
			{
				pPreNode = pPreNode->pList;
			}
			pDelNode = pPreNode->pList;
			pPreNode->pList = pDelNode->pList;
			pDelNode->pList = NULL;
		}
		SafeFree(pDelNode);
		pCList->currentNodeCount--;
		ret = TRUE;
	}
	else
	{
		puts("Postion index is out of range -- removeElement() ");
	}

	return ret;
}

void displayList(PCIRCULARLIST pCList)
{
	if (NULL == pCList)
	{
		puts("There is Empty pCList -- displayList()");
		return NULL;
	}
	PCIRCULARNODE pHeadNode = NULL, pLastNode = NULL, pNode = NULL;
	int i, nodeCount = 0;
	pNode = pCList->headPointer;
	nodeCount = pCList->currentNodeCount;
	if (nodeCount)
	{
		printf("현재 노드의 개수 : %d \n", pCList->currentNodeCount);
		for (i = 0; i < pCList->currentNodeCount; i++)
		{
			printf("%d 번째 노드 : %d \n", i, pNode->data);
			pNode = pNode->pList;
		}
	}
	else
	{
		puts("there has not any node ! --display()");
	}
	
}

void deleteElement(PCIRCULARLIST pCList)
{
	if (NULL == pCList)
	{
		puts("pCList is Empty (NULL) -- deleteElement() ");
		return NULL;
	}

	int i, nodeCount = 0;
	nodeCount = pCList->currentNodeCount;
	for (i = 0; i < nodeCount; i++)
	{
		removeElement(pCList, 0);
	}
	SafeFree(pCList);

}