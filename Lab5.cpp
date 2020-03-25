// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Test.h"
#include"RepositoryArray.h"
#include"Service.h"
#include"UI.h"
using namespace std;

int main()
{
    cout << "testing...."<<'\n';
    testDomain();
    testRepositoryArray();
    testService();
    cout << "everything is fine :)"<<'\n';
    /*RepositoryArray repo;
    Service serv(repo);
    serv.addProject("Notes", 2, 30);
    serv.addProject("Alarms", 7, 23);
    serv.addProject("Hey", 5, 17);*/
    UI user;
    user.console();
    return 0;
}