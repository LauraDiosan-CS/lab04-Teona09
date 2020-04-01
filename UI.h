#pragma once
#include "Service.h"
class UI
{
private:
	Service service;
public:
	UI();
	UI(const Service&);
	void printMenu();
	void addProject();
	void deleteProject();
	void updateProject();
	void printProjects();
	void undo();
	void filterProjectsWithCondition();
	void deleteProjectsWithCondition();
	void console();
	~UI();
};

