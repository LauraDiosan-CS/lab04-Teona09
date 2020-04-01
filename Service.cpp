#include"Service.h"
#include"Project.h"
#include<iostream>
using namespace std;

Service::Service()
{
	sizeUndo = 0;
}

Service::Service(const RepositoryArray& r)
{
	repo = r;
	sizeUndo = 0;
}

void Service::setRepo(const RepositoryArray& r)
{
	repo = r;
	sizeUndo = 0;
}

void Service::addProject(const char* path, int branch, int commit)
{
	undo[sizeUndo++] = repo;
	Project p(path, branch, commit);
	repo.addElem(p);
}

void Service::delProject(const char *path, int branch, int commit)
{
	undo[sizeUndo++] = repo;
	Project p(path, branch, commit);
	repo.delElem(p);
}

void Service::updateProject(const char* path, int branch, int commit, const char* path1, int branch1, int commit1)
{
	undo[sizeUndo++] = repo;
	Project p(path, branch, commit);
	repo.updateElem(p, path1, branch1, commit1);
}

Project* Service::getProjects()
{
	return repo.getAll();
}
 
int Service::getSize()
{
	return repo.dim();
}

Project Service::getProjectFromPos(int pos)
{
	return repo.getItemFromPos(pos);
}

int Service::findProject(const char* path, int branch, int commit)
{
	Project p(path, branch, commit);
	return repo.findElem(p);
}

Service::~Service()
{

}

void Service::repoArrayFindProjectsWithAtLeastKBranchesAndLCommits(int k, int l, Project found[], int& m)
{
	m = 0;
	for (int i = 0; i < repo.dim(); i++)
	{
		Project crrProject = repo.getItemFromPos(i);
		if (crrProject.getNoOfBranches() >= k and crrProject.getTotalNoOfCommits() >= l)
		{
			found[m] = crrProject;
			m++;
		}
	}
}

void Service::repoArrayDeleteProjectsWithZeroBranchesOrCommits()
{	
	for (int i = 0; i < repo.dim(); i++)
	{
		Project crrProject = repo.getItemFromPos(i);
		if (crrProject.getNoOfBranches() == 0 or crrProject.getTotalNoOfCommits() == 0)
		{
			undo[sizeUndo++] = repo;
			repo.delElem(crrProject);
			i--;
		}
	}
}

int Service::undoList()
{
	if (sizeUndo == 0)
		return 1;
	else
	{
		repo = undo[sizeUndo-1];
		sizeUndo--;
		return 0;
	}
}