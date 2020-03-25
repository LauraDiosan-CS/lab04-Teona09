#include"RepositoryArray.h"

RepositoryArray::RepositoryArray()
{
	size = 0;
}

void RepositoryArray::addElem(Project p)
{
	elem[size++] = p;
}

int RepositoryArray::findElem(Project p)
{
	int i = 0;
	while (i < size)
	{
		if (elem[i] == p)
			return i;
		i++;
	}
	return -1;
}

void RepositoryArray::delElem(Project p)
{
	int i = findElem(p);
	if (i != -1)
	{
		elem[i] = elem[size - 1];
		size--;
	}
}

void RepositoryArray::updateElem(Project &p,const char* path, int branches, int commits)
{
	int i = findElem(p);
	if (i != -1)
	{
		elem[i].setGitPath(path);
		elem[i].setNoOfBranches(branches);
		elem[i].setTotalNoOfCommits(commits);
	}
}

Project* RepositoryArray::getAll()
{
	return elem;
}

int RepositoryArray::dim()
{
	return size;
}

RepositoryArray::~RepositoryArray(){}

Project RepositoryArray::getItemFromPos(int i)
{
	return elem[i];
}