#ifndef __CITY__
#define __CITY__

#include "Kindergarten.h"
#include "General.h"
#define TEXT_DATA_FILE "DataFile.txt"
#define BINARY_DATA_FILE "DataFile.bin"

typedef struct
{
	Garden** pGardenList;
	int count;
}City;

LIST*	createLinkedListForKindergartenType(City* city, GardenType type);
void	displayKindergartensFromList(LIST* list);
void	makeLinkedList(City* pCity);
void	readCity(City* pCity, int fileType);
void	showCityGardens(City* pCity);
void	showSpecificGardenInCity(City* pCity);
void	saveCity(City* pCity,int fileType);
void	cityAddGarden(City* pCity);
void	addChildToSpecificGardenInCity(City* pCity);
void	birthdayToChild(City* pCity);
void	releaseCity(City* pCity);
void	sortBy(City* city, int sortType);
int		countChova(City* pCity);
int		cmpByType(void* garden1, void* garden2);
int		cmpByName(void* garden1, void* garden2);

#endif
