#ifndef __KINDERGARTEN__
#define __KINDERGARTEN__

#include "Child.h"

typedef enum
{
	Chova,
	TromChova,
	TromTromChova,
	NofTypes
} GardenType;

const char* GardenTypeName[NofTypes];

typedef struct
{
	char* name;
	GardenType  type;
	Child** childPtrArr;
	int		childCount;
}Garden;

GardenType	getTypeOption();
Garden**	readAllGardensFromFile(char* fileName, int* pGardenCount, int fileType);
Garden**	addGarden(Garden** pGardenList, int* pGardenCount);
Garden*		getGardenAskForName(Garden** pGardenList, int count);
Garden*		findGardenByName(Garden** pGardenList, int count, const char* name);
Child*		getChildAskForId(Garden* pGarden);
void	showGardenFromGeneric(void* pGarden);
void	readGarden(FILE* fp, Garden* pGarden, int fileType);
void	showAllGardens(Garden** pGardenList, int count);
void	showGarden(const Garden* pGarden);
void	writeGardensToFile(Garden** pGardenList, int gardenCount, char* fileName, int fileType);
void	writeGarden(FILE* fp,const Garden* pGarden, int fileType);
void	addChildToGarden(Garden** pGardenList, int gardenCount);
void	showGardenMenu(Garden** pGardenList, int count);
void	getGardenFromUser(Garden* pGarden, Garden** pGardenList, int count);
void	getChildCheckIdFromUser(Child* pChild,const Garden* pGarden);
void	handleBirthdayToChild(Garden** pGardenList, int count);
void	release(Garden** pGardenList, int count);


#endif
