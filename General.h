#ifndef __PROTOTYPE__
#define __PROTOTYPE__

#define TEXT_FILE 0
#define BINARY_FILE 1
#pragma warning(disable:4996)
typedef unsigned char Byte;

typedef enum
{
	EXIT,
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,
	ADD_GARDEN,
	ADD_CHILD,
	CHILD_BIRTHDAY,
	COUNT_GRADUATE,
	SORT_BY_NAME,
	SORT_BY_TYPE_AND_COUNT,
	SORT_BY_ID,
	KINDER_LINKEDLIST,
	NofOptions
} MenuOptions;

typedef void* DATA;
typedef struct node {
	DATA key;
	struct node* next;
} NODE;

typedef struct {
	NODE head;
} LIST;

int		menu();
int		checkAllocation(const void* p);
char*	getStrExactLength(char* inpStr);
void	insertionSort(void* arr, int eleSize, int arrSize, int(*compare)(void*, void*));
void	printPairs(char* firstName, ...);
LIST*	init(LIST* list);
void	insert(NODE* node, DATA value);
void	delete(NODE* node);
void	releaseList(LIST* list);
void	printList(LIST* list, void(*print)(void*));

#endif
