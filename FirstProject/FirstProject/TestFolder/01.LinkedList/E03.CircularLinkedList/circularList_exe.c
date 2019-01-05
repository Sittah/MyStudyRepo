/*
원형연결 리스트의 구현

원형연결리스트 : 단방향으로 연결 되어 있는 형식을 띈 연결리스트 이지만 마지막노드의 다음 노드는 첫 노드이다 !

ㅁ - ㅁ - ㅁ - ㅁ   --> 단 방향 이동
^			   |
|______________v

*/

#include "circularList.h";
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	// createCircularList()
	PCIRCULARLIST pCList = NULL;
	CIRCULARNODE pElementNode;
	pCList = createCircularList();
	if (NULL == pCList)
	{
		puts("allocation is failed !! -- main()");
		return FALSE;
	}
	// addElement()
	pElementNode.data = 1;
	addElement(pCList, 0, pElementNode);
	pElementNode.data = 2;
	addElement(pCList, 1, pElementNode);
	pElementNode.data = 3;
	addElement(pCList, 1, pElementNode);
	pElementNode.data = 4;
	addElement(pCList, 0, pElementNode);

	displayList(pCList);

	// removeElement
	puts("\n remove --");
	removeElement(pCList, 1);
	removeElement(pCList, 0);
	displayList(pCList);

	// deleteElement
	puts("\n delete --");
	deleteElement(pCList);
	pCList = NULL;
	
	
	//displayList(pCList);
	return 0;
}