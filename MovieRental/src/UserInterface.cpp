#include "UserInterface.h"
#include <iostream>

using namespace std;

void UserInterface::start () {
	displayMenuCommands ();
}

void UserInterface::displayMenuCommands () {
	cout << "========================================" << '\n';
	cout << "      DAVE AND FRIENDS VIDEO STORE      " << '\n';
	cout << "========================================" << '\n';
}