#include "UI.h"
#include <iostream>
using namespace std;

UI::UI(){}

UI::~UI(){}

void UI::printMenu()
{
	cout << '\n';
	cout << "Menu: "<< '\n';
	cout << "\t 1.Add Project" << '\n';
	cout << "\t 2.Delete Project" << '\n';
	cout << "\t 3.Update Project" << '\n';
	cout << "\t 4.Print All Projects" << '\n';
	//cout << "\t 5.Print Projects with at least k branches and l commits" << '\n';
	//cout << "\t 6.Delete Projects that have 0 branches or 0 commits" << '\n';
	//cout << "\t 7.Undo" << '\n';
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
	cout << "GitPath: " << '\n';
	char* p = new char[10];
	cin >> p;
	cout << "No of branches: " << '\n';
	int b;
	cin >> b;
	cout << "No of commits: " << '\n';
	int c;
	cin >> c;
	cout << "New datas: " << '\n';
	cout << "GitPath: " << '\n';
	char* newp = new char[10];
	cin >> newp;
	cout << "No of branches: " << '\n';
	int newb;
	cin >> newb;
	cout << "No of commits: " << '\n';
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

void UI::console()
{
	service.addProject("Notes", 2, 30);
	service.addProject("Alarms", 7, 23);
	service.addProject("Hey", 5, 17);
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