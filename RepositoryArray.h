#pragma once
#include"Project.h"

class RepositoryArray
{
private:
	Project elem[15];
	int size;
public:
	RepositoryArray();
	void addElem(Project);
	int findElem(Project);
	Project getItemFromPos(int);
	void delElem(Project);
	void updateElem(Project&,const char*, int, int);
	Project* getAll();
	int dim();
	~RepositoryArray();
};