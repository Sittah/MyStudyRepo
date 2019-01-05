#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

PLINKEDLIST createLinkedList()
{
	PLINKEDLIST pNewLinkedList = (PLINKEDLIST)malloc(sizeof(LINKEDLIST));
	
	if (NULL != pNewLinkedList)
	{
		memset(pNewLinkedList, 0, sizeof(LINKEDLIST));
	}
	else
	{
		puts("Allocation is Failed , Please check Func(createLinkedList())");
	}
	return pNewLinkedList;
}

int addNode(PLINKEDLIST pLinked, int position, LINKEDLISTNODE newNodeElement)
{
	int ret = FALSE, i;
	PLINKEDLISTNODE pPreNode = NULL, pNewNode = NULL;
	if (NULL == pLinked) return FALSE;

	if (position >= 0 && position <= pLinked->currentNodeCount)
	{
		pNewNode = (PLINKEDLISTNODE)malloc(sizeof(LINKEDLISTNODE));
		if (NULL == pNewNode)
		{
			puts("Error, Allocation is failed -- addElement()");
			return FALSE;
		}
		*pNewNode = newNodeElement;
		pNewNode->pLink = NULL; // �ʱ�ȭ
		pPreNode = &(pLinked->headerNode);

		for (i = 0; i < position; i++)
		{
			pPreNode = pPreNode->pLink;
		}
		pNewNode->pLink = pPreNode->pLink;  //H -> A -> B -> C //H -> A -> D - > B - > C
		pPreNode->pLink = pNewNode;
		pLinked->currentNodeCount++;
		ret = TRUE;
	}
	return ret;
}
int removeNode(PLINKEDLIST pLinked, int position)
{
	int ret = FALSE;
	int i;
	PLINKEDLISTNODE pPreNode = NULL, pDelNode = NULL;

	if (NULL == pLinked) return FALSE;

	if (position >= 0 && position < pLinked->currentNodeCount)
	{
		pPreNode = &(pLinked->headerNode);
		for (i = 0; i < position; i++)
		{
			pPreNode = pPreNode->pLink;
		}
		pDelNode = pPreNode->pLink;
		pPreNode->pLink = pDelNode->pLink;
		SafeFree(pDelNode);
		pLinked->currentNodeCount--;
		ret = TRUE;
	}
	else
	{
		puts("Error, range of position exceeded !! :) -- removeNode() ");
	}
	return ret;
}

void displayList(PLINKEDLIST pLinked)
{
	if (NULL == pLinked) return NULL;

	int NodeCount = pLinked->currentNodeCount;
	int i;
	PLINKEDLISTNODE pNode;

	if (NodeCount)
	{
		printf("���� ����� ���� : %d \n", NodeCount);
		pNode = &(pLinked->headerNode);

		for (i = 0; i < NodeCount; i++)
		{
			pNode = pNode->pLink;
			printf("[%d] ��° ��� : %d \n", i, pNode->data);
		}
	}
}

void deleteLinkedList(PLINKEDLIST pLinked)
{
	if (NULL == pLinked) return NULL;

	PLINKEDLISTNODE pNode = NULL, pDelNode = NULL;

	pNode = pLinked->headerNode.pLink;
	printf("��尳�� : %d \n", pLinked->currentNodeCount);
	for (int i = 0; i < pLinked->currentNodeCount; i++)
	{
		removeNode(pLinked, 0);
	}

	SafeFree(pLinked);

}