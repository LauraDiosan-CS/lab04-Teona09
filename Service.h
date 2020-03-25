#pragma once
#include"Project.h"
#include"RepositoryArray.h"
//#include"RepositorySTL.h"

void repoArrayDeleteProjectsWithZeroBranchesOrCommits(Project, int&);


class Service
{
private:
	RepositoryArray repo;
public:
	Service();
	Service(const RepositoryArray&);
	void setRepo(const RepositoryArray&);
	void addProject(const char *, int, int);
	bool findProject(Project);
	void delProject(const char*, int, int);
	void updateProject(const char*, int, int, const char*, int, int);
	Project getProjectFromPos(int);
	Project* getProjects();
	int findProject(const char*, int, int);
	void getAll();
	int getSize();
	void repoArrayFindProjectsWithAtLeastKBranchesAndLCommits(RepositoryArray&,\
		int, int, Project*, int&);
	void repoArrayDeleteProjectsWithZeroBranchesOrCommits(Project , int&);
	~Service();
};

