#pragma once
#include "Service.h"
class UI
{
private:
	Service service;
	void printMenu();
	void addProject();
	void deleteProject();
	void updateProject();
	void printProjects();
public:
	UI();
	~UI();
	void console();
};

