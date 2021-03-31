#include "UserInterface.h"
#include <iostream>
#include <string>
#include <limits>

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
	movieRental.readCustomerToFile ();
	movieRental.readCustomerRentFromFile ();
	movieRental.readMovieListFromFile();
	while (true) 
		mainMenu ();

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
		{
			cout << "=======================================" << '\n';
			cout << "               NEW VIDEO               " << '\n';
			cout << "=======================================" << '\n';
			cout << '\n';

			string title;
			string genre;
			string production;
			int numCopies;
			string userFile;
			MovieList movieItem;

			cout << "Video ID: " << movieItem.movieCounter + 1 << '\n';

			cin.ignore(numeric_limits<streamsize>::max (), '\n');
			cout << "Movie Title: ";
			getline(cin, title);

			cout << "Genre: ";
			getline (cin, genre);
			
			cout << "Production: ";
			getline(cin, production);
			
			cout << "Numbers of copies: ";
			cin >> numCopies;

			cin.ignore (numeric_limits<streamsize>::max (), '\n');
			cout << "File Name: ";
			getline(cin, userFile);
			movieRental.newVideo(title, genre, production, numCopies, userFile);
			break;
		}
			

		case 2:
			cout << "========================================" << '\n';
			cout << "              RENT A VIDEO              " << '\n';
			cout << "========================================" << '\n';
			cout << '\n';

			movieRental.rentAVideo();
			break;

		case 3:
			cout << "========================================" << '\n';
			cout << "             RETURN A VIDEO             " << '\n';
			cout << "========================================" << '\n';
			cout << '\n';

			movieRental.returnVideo();
			cin.get ();
			break;

		case 4:
			cout << "========================================" << '\n';
			cout << "           SHOW VIDEO DETAILS           " << '\n';
			cout << "========================================" << '\n';
			cout << '\n';

			movieRental.showVideoDetails();
			cin.get();
			break;

		case 5:
			cout << "========================================" << '\n';
			cout << "           DISPLAY ALL VIDEOS           " << '\n';
			cout << "========================================" << '\n';
			cout << '\n';

			movieRental.displayAllVideos();
			cin.get();
			break;

		case 6:
			cout << "========================================" << '\n';
			cout << "        CHECK VIDEO AVAILABILITY        " << '\n';
			cout << "========================================" << '\n';
			cout << '\n';

			movieRental.checkVideoAvailability();
			cin.get();

			break;
		
		case 7: 
			customerMaintenance();
			break;
		
		case 8:
			movieRental.writeMovieListToFile();
			movieRental.writeCustomerToFile ();
			movieRental.writeCustomerRentToFile ();
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
			cout << "========================================" << '\n';
			cout << "            ADD NEW CUSTOMER            " << '\n';
			cout << "========================================" << '\n';
			cout << '\n';

			Customer newCustomer;
			string userName;
			string userAddress;

			cout << "Customer ID: " << newCustomer.getCustomerId() << '\n';

			cin.ignore(32767, '\n');
			cout << "Name: ";
			getline(cin, userName);
			newCustomer.setCustomerName(userName);
			cout << "Address: ";
			getline(cin, userAddress);
			newCustomer.setCustomerAddress(userAddress);
			movieRental.addNewCustomer(newCustomer);
			cin.get ();
			break;
		}

		case 2:
			cout << "=========================================" << '\n';
			cout << "          SHOW CUSTOMER DETAILS          " << '\n';
			cout << "=========================================" << '\n';
			cout << '\n';

			movieRental.showCustomerDetails ();
			cin.get ();
			break;

		case 3:
			cout << "=========================================" << '\n';
			cout << "    LIST OF VIDEOS RENTED BY CUSTOMER    " << '\n';
			cout << "=========================================" << '\n';
			cout << '\n';

			movieRental.listVideosRentedByCustomer ();
			cin.get ();
			break;

		default:
			cout << "Invalid Command" << '\n';
	}
}