#include "UserInterface.h"
#include <iostream>

using namespace std;

void UserInterface::start () 
{
	displayMenuCommands ();
	
}

void UserInterface::displayMainMenuCommands () 
{
	cout << "========================================" << '\n';
	cout << "      DAVE AND FRIENDS VIDEO STORE      " << '\n';
	cout << "========================================" << '\n';
	cout << "[1] New Video" << '\n';
	cout << "[2] Rent a Video" << '\n';
	cout << "[3] Return a Video" << '\n';
	cout << "[4] Show Video Details" << '\n';
	cout << "[5] Display All Videos" << '\n';
	cout << "[6] Check Video Availability" << '\n';
	cout << "[7] Customer Maintenance" << '\n';
	cout << "[8] Exit Program" << '\n';
}

int UserInterface::getUserCommand () 
{
	int command = 0;

	//Prompt User
	cout << "Enter command: ";
	cin >> command;
}

void UserInterface::processCommandMainMenu (int command) 
{
	switch (command)
	{
		case 1:
			cout << "New Video" << '\n';
			break;

		case 2:
			cout << "Rent a Video" << '\n';
			break;

		case 3:
			cout << "Return a Video" << '\n';
			break;

		case 4:
			cout << "Show Video Details" << '\n';
			break;

		case 5:
			cout << "Display All Videos" << '\n';
			break;

		case 6:
			cout << "Check Video Availability" << '\n';
			break;

		case 7:
			cout << "Customer Maintenance" << '\n';
			break;

		case 8:
			exit (1);
			break;

		default:
			cout << "Invalid Command" << '\n';

	}
}