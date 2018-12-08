#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
int main()
{
	PARRAYLIST pArrayList1 = createList(5);
	if (NULL != pArrayList1)
	{
		displayArrayList(pArrayList1);
		ARRAYLISTNODE ALNode1;
		ALNode1.data = 1;
		addElement(pArrayList1, 0, ALNode1);
		displayArrayList(pArrayList1);
		ALNode1.data = 2;
		addElement(pArrayList1, 1, ALNode1);
		ALNode1.data = 3;
		addElement(pArrayList1, 2, ALNode1);
		displayArrayList(pArrayList1);

		ALNode1.data = 4;
		addElement(pArrayList1, 3, ALNode1);
		displayArrayList(pArrayList1);


		deleteList(pArrayList1);
		pArrayList1 = NULL;
		puts("delete");
		displayArrayList(pArrayList1);
	}
	return 0;
}