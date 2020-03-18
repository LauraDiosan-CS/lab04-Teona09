#include "RepositorySTL.h"
#include <iostream>
using namespace std;

RepositorySTL::RepositorySTL()
{}

void RepositorySTL::addElem(Project p)
{
	elem.push_back(p);
}

void RepositorySTL::delElem(Project s)
{
	std::vector<Project>::iterator it;
	it = find(elem.begin(), elem.end(), s); 
	if (it != elem.end()) elem.erase(it);

}

bool RepositorySTL::findElem(Project p)
{
	vector<Project>::iterator it;
	it = find(elem.begin(), elem.end(), p);
	if (it != elem.end()) return true;
	return false;

}

int RepositorySTL::dim()
{
	return elem.size();
}

Project RepositorySTL::getItemFromPos(int i)
{
	return elem[i];
}

RepositorySTL::~RepositorySTL()
{}

vector<Project> RepositorySTL::getAll()
{
	return elem;
}

void RepositorySTL::updateElem(Project &p,const char* path, int branches, int commits)
{
	for (int i = 0; i < elem.size(); i++)
	{
		if (elem[i] == p)
		{
			elem[i].setGitPath(path);
			elem[i].setNoOfBranches(branches);
			elem[i].setTotalNoOfCommits(commits);
			//p.setGitPath(path);
			//p.setNoOfBranches(branches);
			//p.setTotalNoOfCommits(commits);

		}
	}

}