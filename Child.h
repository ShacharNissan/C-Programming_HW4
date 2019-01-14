#ifndef __CHILD__
#define __CHILD__


typedef struct
{
	int	 id;
	int  age;
}Child;

Child*	findChildById(Child** pChildList, int count, int id);
void	readChild(FILE* fp, Child* pChild, int fileType);
void	getChildFromUser(Child* pChild, int id);
void	showChild(const Child* pChild);
void	writeChild(FILE* fp,const Child* pChild,int fileType);
void	birthday(Child* pChild);
int		cmpById(void* kid1, void* kid2);
//void	releaseChild(Child* pChild);
#endif
