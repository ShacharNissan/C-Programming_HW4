#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "General.h"


const char* optionStr[NofOptions] =
{
	"Exit","Read City information from file",
	"Show all Kindergartens","Show a specific Kindergarten",
	"Save City information to file","Add a Kindergarten",
	"Add a Child","Birthday to a Child",
	"Count Hova childres", "Sort Kindergartens by name",
	"Sort Kindergartens by type and children numbers",
	"Sort children in a Kindergarten", "Kindergartens in Linked list"
};


/**************************************************/
int		menu()
/**************************************************/
/**************************************************/
{
	int option,i;

	printf("\n==========================");
	printf("\nSelect:\n");
	for(i = 0 ; i < NofOptions; i++)
		printf("\n\t%d. %s.",i, optionStr[i]);
	printf("\n");
	scanf("%d", &option);
	return option;
}

int		checkAllocation(const void* p)
{
	if (!p)
	{
		printf("ERROR! Not enough memory!");
		return 0;
	}
	return 1;
}

char*	getStrExactLength(char* inpStr)
{
	char* theStr = NULL;
	size_t len;

	len = strlen(inpStr) + 1;
	//allocate a place for the string in the right location in the array 
	theStr = (char*)malloc(len*sizeof(char));
	//Copy the string to the right location in the array 
	if (theStr != NULL)
		strcpy(theStr, inpStr);

	return theStr;
}

void	insertionSort(void* arr, int eleSize, int arrSize, int(*compare)(void*, void*))
{
	int i, j, cmp;
	void *temp, *key, *ele, *nextE;
	for (i = 1; i < arrSize; i++) {
		temp = (char *)arr + i * eleSize;
		key = malloc(eleSize);
		memcpy(key, temp, eleSize);
		for (j = i - 1; j >= 0; j--)
		{
			ele = (char *)arr + j * eleSize;
			cmp = (*compare)(key, ele);
			if (cmp >= 0)
				break;
			nextE = (char *)arr + (j + 1) * eleSize;
			memcpy(nextE, ele, eleSize);
		}
		nextE = (char *)arr + (j + 1) * eleSize;
		memcpy(nextE, key, eleSize);
		free(key);
	}
}

void	printPairs(char* firstName, ...) {
	va_list data;
	char* name = firstName;
	va_start(data, firstName);

	while (name) {
		printf("%s ---->  %d\n", name, va_arg(data, int));
		name = va_arg(data, char*);
	}
	va_end(data);
}

LIST*	init(LIST* list) {
	NODE *temp;
	if (list)
		releaseList(list);

	list = (LIST*)malloc(sizeof(LIST));
	temp = (NODE*)malloc(sizeof(NODE));
	temp->next = NULL;
	temp->key = 0;
	list->head = *temp;
	return list;
}

void	insert(NODE* node, DATA value) {

	NODE* newNode;

	if (!node)
		return;

	newNode = (NODE*)malloc(sizeof(NODE));
	if (!newNode)
		return;

	newNode->key = value;
	newNode->next = node->next;
	node->next = newNode;
}

void	delete(NODE* node) {
	NODE* temp;

	if (!node || !node->next)
		return;
	temp = node->next;
	node->next = temp->next;
	free(temp);
}

void	releaseList(LIST* list) {

	if (!list)
		return;

	while (list->head.next)
		delete(&list->head);
	free(&list->head);
	free(list);
}

void	printList(LIST* list, void(*print)(void*)) 
{
	NODE* temp;

	if (!list)
		return;

	temp = list->head.next;
	while (temp)
	{
		printf("\n");
		print(temp->key);
		temp = temp->next;
	}
}