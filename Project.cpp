#include "Project.h"
#include<string.h>

Project::Project()
{
	gitPath = NULL;
	noOfBranches = 0;
	totalNoOfCommits = 0;
}

Project::Project(const char *path, int branches, int commits)
{
	this->gitPath = new char[strlen(path) + 1];	
	strcpy_s(this->gitPath, strlen(path) + 1, path); 
	this->noOfBranches = branches;
	this->totalNoOfCommits = commits;
}

Project::Project(const Project& p)
{
	this->gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	this->noOfBranches = p.noOfBranches;
	this->totalNoOfCommits = p.totalNoOfCommits;
}

char* Project::getGitPath()
{
	return gitPath;
}

void Project::setGitPath(const char* path)
{
	if (gitPath) delete[]gitPath;
	gitPath = new char[strlen(path) + 1];
	strcpy_s(gitPath, strlen(path) + 1, path);
}

int Project::getNoOfBranches()
{
	return noOfBranches;
}

int Project::getTotalNoOfCommits()
{
	return totalNoOfCommits;
}

void Project::setNoOfBranches(int b)
{
	noOfBranches = b;
}

void Project::setTotalNoOfCommits(int c)
{
	totalNoOfCommits = c;
}

Project::~Project()
{
	if (gitPath) delete[]gitPath;
	gitPath = NULL;
	noOfBranches = -1;
	totalNoOfCommits = -1;
}

Project& Project::operator=(const Project& p)
{
	if (this == &p) return *this; //self-assignment
	if (gitPath) delete[] gitPath;
	if (p.gitPath)
	{
		gitPath = new char[strlen(p.gitPath) + 1];
		strcpy_s(gitPath, strlen(p.gitPath) + 1, p.gitPath);
	}
	noOfBranches = p.noOfBranches;
	totalNoOfCommits = p.totalNoOfCommits;
	return *this;
}

bool Project::operator==(const Project& p)
{
	return(strcmp(gitPath, p.gitPath) == 0) and \
		(noOfBranches == p.noOfBranches) and (totalNoOfCommits == p.totalNoOfCommits);
}