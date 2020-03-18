#pragma once
#include"Project.h"
#include"RepositoryArray.h"
#include"RepositorySTL.h"
using namespace std;

void repoArrayFindProjectsWithAtLeastKBranchesAndLCommits(RepositoryArray &projects, \
	int k, int l, Project found[], int& m);

void repoArrayDeleteProjectsWithZeroBranchesOrCommits(Project projects[], int& n);

void repoSTLFindProjectsWithAtLeastKBranchesAndLCommits(RepositorySTL& projects, \
	int k, int l, vector<Project> &foundProjects);

void repoSTLDeleteProjectsWithZeroBranchesOrCommits(RepositorySTL& projects);

