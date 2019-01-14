#include <stdio.h>
#include <string.h>
#include "City.h"
#include "Kindergarten.h"

LIST*	createLinkedListForKindergartenType(City* city, GardenType type)
{
	int i;
	LIST* myList = NULL;
	myList = init(myList);

	if (!myList || !city)
		return NULL;

	for (i = 0;i < city->count;i++) 
		if (city->pGardenList[i]->type == type)
			insert(&myList->head, city->pGardenList[i]);
	
	return myList;
}

void	displayKindergartensFromList(LIST* list)
{
	printf("Kindergartens list:\n");
	printList(list, showGardenFromGeneric);
}

void	makeLinkedList(City* pCity)
{
	int type = getTypeOption();
	LIST* mylist = createLinkedListForKindergartenType(pCity, type);
	displayKindergartensFromList(mylist);
}

void	readCity(City* pCity, int fileType)
{
	if (pCity->pGardenList != NULL) {
		releaseCity(pCity);
		pCity->count = 0;
	}
	if (fileType == TEXT_FILE)
		pCity->pGardenList = readAllGardensFromFile(TEXT_DATA_FILE, &pCity->count, fileType);
	else if (fileType == BINARY_FILE)
		pCity->pGardenList = readAllGardensFromFile(BINARY_DATA_FILE, &pCity->count, fileType);

	if (pCity->pGardenList == NULL)
		printf("Error reading city information\n");
}

void	showCityGardens(City* pCity)
{
	showAllGardens(pCity->pGardenList, pCity->count);
}

void	showSpecificGardenInCity(City* pCity)
{
	showGardenMenu(pCity->pGardenList, pCity->count);
}

void	saveCity(City* pCity, int fileType)
{
	if (fileType == TEXT_FILE)
		writeGardensToFile(pCity->pGardenList, pCity->count, TEXT_DATA_FILE, fileType);
	else if (fileType == BINARY_FILE)
		writeGardensToFile(pCity->pGardenList, pCity->count, BINARY_DATA_FILE, fileType);
}

void	cityAddGarden(City* pCity)
{
	int cCount= pCity->count;
	pCity->pGardenList = addGarden(pCity->pGardenList, &cCount);
	pCity->count = cCount;
	if (pCity->pGardenList == NULL)//Allocation error
		printf("Error adding kindergarten\n");
}

void	addChildToSpecificGardenInCity(City* pCity)
{
	addChildToGarden(pCity->pGardenList, pCity->count);
}

void	birthdayToChild(City* pCity)
{
	handleBirthdayToChild(pCity->pGardenList, pCity->count);
}

int		countChova(City* pCity)
{
	int i;
	int count = 0;
	for (i = 0; i < pCity->count; i++)
	{
		if (pCity->pGardenList[i]->type == Chova)
			count += pCity->pGardenList[i]->childCount;
	}
	return count;
}

void	releaseCity(City* pCity)
{
	release(pCity->pGardenList, pCity->count);
}

int		cmpByName(void* garden1, void* garden2) {
	Garden *a = *((Garden**)garden1), *b = *((Garden**)garden2);
	return strcmp(a->name, b->name);
}

int		cmpByType(void* garden1, void* garden2) {
	int cmp;
	Garden *a = *((Garden**)garden1), *b = *((Garden**)garden2);
	cmp = (a->type) - (b->type);
	if (cmp)
		return cmp;
	return (a->childCount) - (b->childCount);
}

void	sortBy(City* city, int sortType) {
	Garden *garden;
	switch (sortType)
	{
	case SORT_BY_NAME:
		insertionSort(city->pGardenList, sizeof(Garden*), city->count, cmpByName);
		break;

	case SORT_BY_TYPE_AND_COUNT:
		insertionSort(city->pGardenList, sizeof(Garden*), city->count, cmpByType);
		break;

	case SORT_BY_ID:
		garden = getGardenAskForName(city->pGardenList, city->count);
		insertionSort(garden->childPtrArr, sizeof(Child*), garden->childCount, cmpById);
		break;
	}
}