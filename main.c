#include <stdio.h>
#include <stdlib.h>

#include "General.h"
#include "Kindergarten.h"
#include "Child.h"
#include "City.h"




int main(int argc, char* argv[])
{
	City utz = { NULL,0 };
	int uReq;
	int fileType;
	sscanf(argv[1], "%d", &fileType);
	if (argc < 1)
		return -1;
	readCity(&utz, fileType);
	do
	{
		uReq = menu();
		switch (uReq)
		{
		case  READ_CITY:
			readCity(&utz, fileType);
			break;

		case  SHOW_CITY:
			showCityGardens(&utz);
			break;

		case  SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case  WRITE_CITY:
			saveCity(&utz, fileType);
			break;

		case  ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case  ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case  CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n",countChova(&utz));
			break;

		case SORT_BY_NAME:
			sortBy(&utz, SORT_BY_NAME);
			break;

		case SORT_BY_TYPE_AND_COUNT:
			sortBy(&utz, SORT_BY_TYPE_AND_COUNT);
			break;

		case SORT_BY_ID:
			sortBy(&utz, SORT_BY_ID);
			break;

		case KINDER_LINKEDLIST:
			makeLinkedList(&utz);
			break;
		}
	}while (uReq!=EXIT);
	
	releaseCity(&utz);//free all allocations
	
	return EXIT_SUCCESS;
}

