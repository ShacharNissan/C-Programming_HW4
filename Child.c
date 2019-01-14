#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Child.h"
#include "General.h"
#define ID_BITS 0x1fff
#define ID_NUM_OF_BITS 13

/**************************************************/
/*             Read a Child from a file           */
/**************************************************/
void readChild(FILE* fp, Child* pChild, int fileType)
{
	if (fileType == TEXT_FILE)
	{
		fscanf(fp, "%d", &pChild->id);
		fscanf(fp, "%d", &pChild->age);
	}
	else if (fileType == BINARY_FILE)
	{
		unsigned int data = 0;
		fread(&data, 2, 1, fp);
		pChild->id = data & ID_BITS;
		pChild->age = data >> ID_NUM_OF_BITS;
	}
}


/**************************************************/
/*            show a Child				           */
/**************************************************/
void showChild(const Child* pChild)
{
	printf("\nID:%d  ", pChild->id);
	printf("Age:%d  ", pChild->age);
}


/**************************************************/
void getChildFromUser(Child* pChild, int id)
/**************************************************/
/**************************************************/
{
	int age;
	pChild->id = id;
	
	puts("\nAge:\t");
	scanf("%d", &age);
	pChild->age = age;
}


/**************************************************/
/*Write a Child to the open file				*/
/**************************************************/
void writeChild(FILE* fp,const Child* pChild, int fileType)
{
	if (fileType == TEXT_FILE)
		fprintf(fp, "%d %d\n", pChild->id, pChild->age);
	else if (fileType == BINARY_FILE)
	{
		unsigned int data = 0;
		data = pChild->age << ID_NUM_OF_BITS;
		data = data | pChild->id;
		fwrite(&data, 2, 1, fp);
	}
}

//linear search
Child*	findChildById(Child** pChildList, int count, int id)
{
	Child** result;
	Child key = { id,0 };
	Child* keyPath = &key;
	qsort(pChildList, count, sizeof(Child*), cmpById);
	result = (Child**)bsearch(&keyPath, pChildList, count, sizeof(Child*), cmpById);
	if (result)
		return *result;
	return NULL;
}

void	birthday(Child* pChild)
{
	pChild->age++;
}

int		cmpById(void* kid1, void* kid2)
{
	Child *a = *((Child**)kid1), *b = *((Child**)kid2);
	return (a->id) - (b->id);
}

//void	releaseChild(Child* pChild)
//{
//	//nothing to release
//}
