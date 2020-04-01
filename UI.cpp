#include "UI.h"
#include <iostream>
using namespace std;

UI::UI(){}

UI::UI(const Service &serv)
{
	service = serv;
}

UI::~UI(){}

void UI::printMenu()
{
	cout << '\n';
	cout << "Menu: "<< '\n';
	cout << "\t 1.Add Project" << '\n';
	cout << "\t 2.Delete Project" << '\n';
	cout << "\t 3.Update Project" << '\n';
	cout << "\t 4.Print All Projects" << '\n';
	cout << "\t 5.Print Projects with at least k branches and l commits" << '\n';
	cout << "\t 6.Delete Projects that have 0 branches or 0 commits" << '\n';
	cout << "\t 7.Undo" << '\n';
	cout << "\t 0.Exit" << '\n'<<'\n';
	cout << "Choose option: " ;
}

void UI::addProject()
{
	cout << "GitPath: ";
	char* p = new char[10];
	cin >> p;
	cout << "No of branches: ";
	int b;
	cin >> b;
	cout << "No of commits: ";
	int c;
	cin >> c;
	service.addProject(p, b, c);
}

void UI::deleteProject()
{
	cout << "GitPath: ";
	char* p = new char[10];
	cin >> p;
	cout << "No of branches: ";
	int b;
	cin >> b;
	cout << "No of commits: ";
	int c;
	cin >> c;
	service.delProject(p, b, c);
	delete[]p;
}

void UI::updateProject()
{
	cout << "Current datas: "<<'\n';
	cout << "GitPath: " ;
	char* p = new char[10];
	cin >> p;
	cout << "No of branches: " ;
	int b;
	cin >> b;
	cout << "No of commits: ";
	int c;
	cin >> c;
	cout << "New datas: " << '\n';
	cout << "GitPath: " ;
	char* newp = new char[10];
	cin >> newp;
	cout << "No of branches: ";
	int newb;
	cin >> newb;
	cout << "No of commits: ";
	int newc;
	cin >> newc;
	service.updateProject(p, b, c, newp, newb, newc);
	delete[]p;
	delete[]newp;
}

void UI::printProjects()
{
	int i = 0;
	Project* projects = service.getProjects();
	while (i < service.getSize())
	{
		cout << projects[i].getGitPath() << ' ';
		cout << projects[i].getNoOfBranches() << ' ';
		cout << projects[i].getTotalNoOfCommits() << endl;
		i++;
	}
}

void UI::undo()
{
	int done = service.undoList();
	if (done == 1)
		cout << "no undo posible";
	else
	{
		cout << "undo done";
		printProjects();
	}
}

void UI::filterProjectsWithCondition()
{
	cout << "minimum number of branches: ";
	int k;
	cin >> k;
	cout << "minimum number of commits: ";
	int l;
	cin >> l;
	Project found[10];
	int m=0;
	service.repoArrayFindProjectsWithAtLeastKBranchesAndLCommits(k, l, found, m);
	for (int i = 0; i < m; i++)
	{
		cout << found[i].getGitPath() << ' ';
		cout << found[i].getNoOfBranches() << ' ';
		cout << found[i].getTotalNoOfCommits() << endl;
	}
}

void UI::deleteProjectsWithCondition()
{
	service.repoArrayDeleteProjectsWithZeroBranchesOrCommits();
}


void UI::console()
{
	int option;
	bool ok = 1;
	while (ok)
	{
		printMenu();
		cin >> option;
		cout << '\n';
		switch (option)
		{
			case 1:
			{
				addProject();
				break;
			}
			case 2:
			{
				deleteProject();
				break;
			}
			case 3:
			{
				updateProject();
				break;
			}
			case 4:
			{
				printProjects();
				break;
			}
			case 5:
			{
				filterProjectsWithCondition();
				break;
			}
			case 6:
			{
				deleteProjectsWithCondition();
				break;
			}
			case 7:
			{
				undo();
				break;
			}
			case 0:
			{
				cout << "See you next time :)\n";
				ok = 0;
				break;
			}
			default:
			{
				cout << "Not an option" << '\n';
				break;
			}
		}
	}
}