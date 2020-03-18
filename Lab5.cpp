// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Test.h"
using namespace std;

int main()
{
    cout << "testing...."<<'\n';
    testDomain();
    testRepositoryArray();
    testRepositorySTL();
    testService();
    cout << "everything is fine :)"<<'\n';
    return 0;
}