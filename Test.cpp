#include"Test.h"
#include"assert.h"
#include"Service.h"
#include"RepositoryArray.h"
#include"RepositorySTL.h"
#include"Project.h"
#include<iostream>
#include<string.h>
using namespace std;

void testDomain()
{	
	Project p1("Hello there", 3, 7); //parameterized constructor
	assert(strcmp(p1.getGitPath(),"Hello there")==0);
	assert(p1.getNoOfBranches() == 3);
	assert(p1.getTotalNoOfCommits() == 7);

	p1.setNoOfBranches(5); //setters
	assert(p1.getNoOfBranches() == 5);
	p1.setTotalNoOfCommits(12);
	assert(p1.getTotalNoOfCommits() == 12);
	
	Project p2 = p1; //copy constructor
	assert(p2 == p1);

	Project p3; //default constructor
	assert(p3.getGitPath() == NULL);
	assert(p3.getNoOfBranches() == 0);
	assert(p3.getTotalNoOfCommits() == 0);
}
//--------------------------------------------------------------------
void testRepositoryArray()
{	
	Project p1("Abracadabra", 5, 34);
	Project p2("Hello world", 2, 3);
	Project p3("Mario", 6, 45);
	Project p4("Plants vs Zombies", 8, 31);
	RepositoryArray proj;
	proj.addElem(p1); //add elements
	proj.addElem(p2);
	proj.addElem(p3);
	assert(proj.dim() == 3);
	assert(proj.getAll()[0] == p1);
	assert(proj.getAll()[1] == p2);
	assert(proj.getAll()[2] == p3);

	assert(proj.findElem(p1) == 0); //find element
	assert(proj.findElem(p4) == -1);
	
	proj.delElem(p3); //delete element
	assert(proj.dim() == 2);
	assert(proj.findElem(p3) == -1);

	assert(strcmp(p2.getGitPath(), "Hello world") == 0); //update element
	proj.updateElem(p2, "Hello there", 2, 7);
	assert(strcmp(proj.getItemFromPos(1).getGitPath(), "Hello there") == 0);
	assert(proj.getItemFromPos(1).getTotalNoOfCommits() == 7);

}
//--------------------------------------------------------------------
void testRepositorySTL()
{
	Project p1("Abracadabra", 5, 34);
	Project p2("Hello world", 2, 3);
	Project p3("Mario", 6, 45);
	Project p4("Plants vs Zombies", 8, 31);
	RepositorySTL proj;

	proj.addElem(p1); //add elements
	proj.addElem(p2);
	proj.addElem(p3);
	proj.getAll() = { p1,p2,p3 }; 
	
	assert(proj.findElem(p1) == true);
	assert(proj.findElem(p4) == false);

	assert(proj.dim() == 3); //delete element
	proj.delElem(p3);
	assert(proj.dim() == 2);
	assert(proj.findElem(p3) == false);

	assert(strcmp(p2.getGitPath(), "Hello world")==0); //update element
	proj.updateElem(p2, "Hello there", 2, 7);
	// - pt teste folosesc p2 sau proj.getItemFromPos(1)?
	assert(strcmp(proj.getItemFromPos(1).getGitPath(), "Hello there") == 0);
	assert(proj.getItemFromPos(1).getTotalNoOfCommits() == 7);
}
//--------------------------------------------------------------------
void testService()
{
	testRepoArrayFindProjectsWithAtLeastKBranchesAndLCommits();
	testRepoArrayDeleteProjectsWithZeroBranchesOrCommits();
	testRepoSTLFindProjectsWithAtLeastKBranchesAndLCommits();
	testRepoSTLDeleteProjectsWithZeroBranchesOrCommits();
}
//--------------------------------------------------------------------
void testRepoArrayFindProjectsWithAtLeastKBranchesAndLCommits()
{
	Project p1("Abracadabra", 5, 34);
	Project p2("Hello world", 2, 3);
	Project p3("Mario", 6, 45);
	Project p4("Plants vs Zombies", 8, 31);
	Project p5("Lab5", 0, 0);
	Project p6("New Idea", 1, 0);
	RepositoryArray pro;
	pro.addElem(p1);
	pro.addElem(p2);
	pro.addElem(p3);
	pro.addElem(p4);
	pro.addElem(p5);
	pro.addElem(p6);
	assert(pro.dim() == 6);
	Project found[10];
	int m = 0;
	repoArrayFindProjectsWithAtLeastKBranchesAndLCommits(pro, 5, 33, found,m);
	assert(m == 2);
	assert(found[0] == p1);
	assert(found[1] == p3);
}
//--------------------------------------------------------------------
void testRepoArrayDeleteProjectsWithZeroBranchesOrCommits()
{

}
//--------------------------------------------------------------------
void testRepoSTLFindProjectsWithAtLeastKBranchesAndLCommits()
{
	Project p1("Abracadabra", 5, 34);
	Project p2("Hello world", 2, 3);
	Project p3("Mario", 6, 45);
	Project p4("Plants vs Zombies", 8, 31);
	Project p5("Lab5", 0, 0);
	Project p6("New Idea", 1, 0);
	RepositorySTL proj;
	proj.addElem(p1);
	proj.addElem(p2);
	proj.addElem(p3);
	proj.addElem(p4);
	proj.addElem(p5);
	proj.addElem(p6);
	vector<Project>found;
	repoSTLFindProjectsWithAtLeastKBranchesAndLCommits(proj, 5, 33, found);
	assert(found.size() == 2);
	assert(found[0] == p1);
	assert(found[1] == p3);
}
//--------------------------------------------------------------------
void testRepoSTLDeleteProjectsWithZeroBranchesOrCommits()
{
	Project p1("Abracadabra", 5, 34);
	Project p2("Hello world", 2, 3);
	Project p3("Mario", 6, 45);
	Project p4("Plants vs Zombies", 8, 31);
	Project p5("Lab5", 0, 0);
	Project p6("New Idea", 1, 0);
	RepositorySTL proj;
	proj.addElem(p1);
	proj.addElem(p2);
	proj.addElem(p3);
	proj.addElem(p4);
	proj.addElem(p5);
	proj.addElem(p6);
	repoSTLDeleteProjectsWithZeroBranchesOrCommits(proj);
	assert(proj.dim() == 4);
	assert(proj.findElem(p1)==true);
	assert(proj.findElem(p2)==true);
	assert(proj.findElem(p3)==true);
	assert(proj.findElem(p4)==true);
	assert(proj.findElem(p5)==false);
	assert(proj.findElem(p6)==false);

}