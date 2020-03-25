#include"Service.h"
#include"Project.h"
#include<iostream>
using namespace std;

Service::Service()
{
}

Service::Service(const RepositoryArray& r)
{
	repo = r;
}

void Service::addProject(const char* path, int branch, int commit)
{
	Project p(path, branch, commit);
	repo.addElem(p);
}

void Service::delProject(const char *path, int branch, int commit)
{
	Project p(path, branch, commit);
	repo.delElem(p);
}

void Service::updateProject(const char* path, int branch, int commit, const char* path1, int branch1, int commit1)
{
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

void Service::repoArrayFindProjectsWithAtLeastKBranchesAndLCommits(RepositoryArray& projects, \
	int k, int l, Project found[], int& m)
{
	m = 0;
	for (int i = 0; i < projects.dim(); i++)
	{
		Project crrProject = projects.getItemFromPos(i);
		if (crrProject.getNoOfBranches() >= k and crrProject.getTotalNoOfCommits() >= l)
		{
			found[m] = crrProject;
			m++;
		}
	}
}

void repoArrayDeleteProjectsWithZeroBranchesOrCommits(Project projects[], int& n)
{

}

/*
//	creates a list with the projects that have at least k branches and l commits
//	IN:	an array of projects, the minimum number of branches(int) and commits(int)
//	OUT: an array of the required projects

void repoSTLFindProjectsWithAtLeastKBranchesAndLCommits(RepositorySTL& projects, \
	int k, int l, vector<Project>& foundProjects)
{
	for (int i = 0; i < projects.dim(); i++)
	{
		Project crrProject = projects.getItemFromPos(i);
		if (crrProject.getNoOfBranches() >= k and crrProject.getTotalNoOfCommits() >= l)
		{
			foundProjects.push_back(projects.getItemFromPos(i));
		}
	}
}


//	deletes from the repository all the projects that don't have any branches or commits
//	IN: an array of projects
//	OUT: -

void repoSTLDeleteProjectsWithZeroBranchesOrCommits(RepositorySTL& projects)
{
	for (int i = 0; i < projects.dim(); i++)
	{
		Project crrProject = projects.getItemFromPos(i);
		if (crrProject.getNoOfBranches() == 0 or crrProject.getTotalNoOfCommits() == 0)
		{
			projects.delElem(projects.getItemFromPos(i));
			i--;
		}
	}
}
*/
