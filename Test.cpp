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
	assert(p2 == p1); // == operator

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
void testService()
{	Service rep;

	//ADD
	rep.addProject("Abracadabra", 5, 34);
	rep.addProject("Mario", 6, 45);
	rep.addProject("Plants vs Zombies", 8, 31);
	rep.addProject("Lab5", 0, 0);
	rep.addProject("New Idea", 1, 0);
	rep.addProject("Hello world", 2, 3);

	//DELETE
	assert(rep.getSize() == 6);
	rep.delProject("Hello world", 2, 3);
	assert(rep.getSize() == 5);

	//GET PROJECTS
	Project p1("Abracadabra", 5, 34);
	Project p2("Mario", 6, 45);
	Project p3("Plants vs Zombies", 8, 31);
	Project p4("Lab5", 0, 0);
	Project p5("New Idea", 1, 0);
	assert(rep.getProjects()[0] == p1);
	assert(rep.getProjects()[1] == p2);
	assert(rep.getProjects()[2] == p3);

	//GET PROJECT FROM POS
	assert(rep.getProjectFromPos(0) == p1);

	//FIND PROJECT
	assert(rep.findProject("Plants vs Zombies", 8, 31) == 2);
	assert(rep.findProject("Hello world", 2, 3) == -1);

	//UPDATE
	rep.updateProject("Abracadabra", 5, 34, "Abracadabra", 3, 11);
	assert(rep.getProjects()[0].getNoOfBranches() == 3);
	assert(rep.getProjects()[0].getTotalNoOfCommits() == 11);
	
	//OTHER TESTS
	//repoArrayFindProjectsWithAtLeastKBranchesAndLCommits
	Project found[10];
	int m = 0;
	rep.repoArrayFindProjectsWithAtLeastKBranchesAndLCommits(5, 30, found, m);
	assert(m == 2);
	assert(found[0] == p2);
	assert(found[1] == p3);

	//repoArrayDeleteProjectsWithZeroBranchesOrCommits
	assert(rep.getSize() == 5);
	rep.repoArrayDeleteProjectsWithZeroBranchesOrCommits();
	assert(rep.getSize() == 3);
	assert(rep.findProject("Plants vs Zombies", 8, 31) == 2);
	assert(rep.findProject("New Idea", 1, 0) == -1);

	//UNDO
	assert(rep.getSize() == 3);
	//in array are 3 elements from position 0 to 2
	assert(rep.findProject("Hello world", 2, 3) == -1);
	rep.addProject("Hello world", 2, 3);
	assert(rep.findProject("Hello world", 2, 3) == 3);
	rep.undoList();
	assert(rep.findProject("Hello world", 2, 3) == -1);
	
}