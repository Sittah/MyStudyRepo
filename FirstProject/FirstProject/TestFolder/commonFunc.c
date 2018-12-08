#include <stdio.h>
#include <stdlib.h>

void saferFree(void **pp)
{
	/*
		 ( pp != NULL )		Is valid this pointer that received
		 ( *pp != NULL )	Is the pointer has valid target

	*/
	if (pp != NULL && *pp != NULL)
	{
		free(*pp);
		*pp = NULL;
	}
}