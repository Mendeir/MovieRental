#include "UserInterface.h"
#include <iostream>

using namespace std;

//Methods
/**
	Description:
	Precondition:
	Postcondtion:
*/

void UserInterface::clear ()
{
	cout << "\033[H\033[J";
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void UserInterface::start () 
{
	while (true) 
	{
		
		mainMenu ();
		

	}
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void UserInterface::mainMenu () 
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
	cout << "[8] Exit Program" << "\n\n";

	processCommandMainMenu(getUserCommand ());
	clear ();
}

//Input Methods
/**
	Description:
	Precondition:
	Postcondtion:
*/
int UserInterface::getUserCommand ()
{
	int command = 0;

	//Prompt User
	cout << "Enter command: ";
	cin >> command;

	return command;
}

//Main Menu Methods
/**
	Description:
	Precondition:
	Postcondtion:
*/
void UserInterface::customerMaintenance ()
{
	cout << "========================================" << '\n';
	cout << "          CUSTOMER MAINTENANCE          " << '\n';
	cout << "========================================" << '\n';
	customerMaintenanceSubMenu ();
	processCustomerMaintenance (getUserCommand ());

}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void UserInterface::customerMaintenanceSubMenu ()
{
	cout << "[1] Add New Customer" << '\n';
	cout << "[2] Show Customer Details" << '\n';
	cout << "[3] List of Videos Rented by a Customer" << "\n\n";
}


/**
	Description:
	Precondition:
	Postcondtion:
*/
//Processing Methods
void UserInterface::processCommandMainMenu (int command) 
{
	clear ();
	switch (command)
	{
		case 1:
			//movieList.insertNewVideo("Buzzlightyear", "Cartoon", "Disney", 10);
			//movieList.insertNewVideo("The Incredibles", "Cartoon", "Disney", 10);
			cin.get();
			break;

		case 2:
			cout << "Rent a Video" << '\n';
			movieRental.rentAVideo();
			cin.get ();
			break;

		case 3:
			cout << "Return a Video" << '\n';
			break;

		case 4:
			cout << "Show Video Details" << '\n';
			break;

		case 5:
			cout << "Display All Videos" << '\n';
			//movieList.displayVideos();
			cin.get();
			break;

		case 6:
			cout << "Check Video Availability" << '\n';
			break;

		case 7:
			customerMaintenance ();
			break;

		case 8:
			exit (1);
			break;

		default:
			cout << "Invalid Command" << '\n';

	}
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void UserInterface::processCustomerMaintenance (int command)
{
	clear ();

	switch (command)
	{
		case 1:
		{
			cout << "Add New Customer" << '\n';
			Customer mg;
			Customer dave;
			string name;

			cout << "MG ID: " << mg.getCustomerId () << '\n';
			mg.setCustomerName ("MG");
			mg.setCustomerAddress ("Mars");

			cout << "Dave ID: " << dave.getCustomerId () << '\n';
			dave.setCustomerName ("Dave");
			dave.setCustomerAddress ("Venus");

			cout << "---------------\n";
			movieRental.addNewCustomer (mg);
			movieRental.addNewCustomer (dave);
			movieRental.showAllCustomers();

			cin.get ();
			break;
		}

		case 2:
			cout << "Show Customer Details" << '\n';
			break;

		case 3:
			cout << "List of Videos Rented by a Customer" << '\n';
			break;

		default:
			cout << "Invalid Command" << '\n';
	}
}