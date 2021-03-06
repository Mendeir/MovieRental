#include "MovieRental.h"
#include <iostream>
#include <limits>

using namespace std;


//***************************
//*		   METHODS          *
//***************************

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::newVideo (string title, string genre, string production, int copies)
{
	movieList.newVideo(title, genre, production, copies);
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::rentAVideo ()
{
	//Initialize Variables
	char choice;
	int givenCustomerID = getCustomerID ();

	customerList.showCustomerDetails (givenCustomerID);
	cout << '\n';

	//Collect video ID's to be rented
	while (true)
	{
		int givenVideoID = 0;
		cout << "Enter the video ID to be rented: ";
		cin >> givenVideoID;

		//Reduce number of copies and put videoID on stack
		if (movieList.rentAVideo (givenVideoID)) 
			rentedVideoIDs.push (givenVideoID);

		//Ask user if continue
		cout << "Rent another video? (Y/N): ";
		cin >> choice;

		cout << '\n';

		//Terminating statement
		if (choice == 'N')
			break;
	}

	//Put customerID(int) as key and rentedVideoIDs(stack) as value in the unordered map
	rentedVideos.insert ({ givenCustomerID, rentedVideoIDs });	
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::returnVideo ()
{
	//Initialize variables
	int givenVideoID = 0;
	int givenCustomerID = getCustomerID ();;

	customerList.showCustomerDetails (givenCustomerID);
	cout << '\n';

	//Check if a key has been made for the id
	if (rentedVideos.find (givenCustomerID) == rentedVideos.end ())
	{
		cout << "Customer ID not found / Customer hasn't rented videos." << '\n';
		cin.get ();
		return;
	}

	//Pop the stack value of the given id until empty
	while (!rentedVideos.at(givenCustomerID).empty ())
	{
		movieList.returnAVideo (rentedVideos.at(givenCustomerID).top ());
		rentedVideos.at(givenCustomerID).pop ();
	}

	//Remove the key and value pair from the unordered map
	rentedVideos.erase (givenCustomerID);
	cout << "Videos successfully returned" << '\n';
	cin.get ();
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void showVideoDetails ();

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::displayAllVideos()
{
	movieList.displayVideos();
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void checkVideoAvailability ();

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::addNewCustomer (Customer givenCustomer)
{
	customerList.addCustomer(givenCustomer);
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::showCustomerDetails ()
{
	int givenCustomerID = getCustomerID ();

	customerList.showCustomerDetails (givenCustomerID);
	cin.get ();

}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::listVideosRentedByCustomer ()
{
	//Initialize variables
	int givenCustomerID = getCustomerID ();

	customerList.showCustomerDetails (givenCustomerID);
	cout << '\n';

	//Check if a key has been made for the id
	if (rentedVideos.find (givenCustomerID) == rentedVideos.end ())
	{
		cout << "Customer ID not found / Customer hasn't rented videos." << '\n';
		cin.get ();
		return;
	}

	//Make a copy of the customer's stack
	stack<int> videoIDsCopy = rentedVideos.at (givenCustomerID);

	//List videos rented by customer
	cout << "List of videos rented: " << "\n\n";
	cout << "Video ID" << "\t" << "Movie Title" << '\n';
	while (!videoIDsCopy.empty ())
	{
		//Display the stack's top and pops it
		cout << videoIDsCopy.top () << "\t\t" << movieList.getTitleByID (videoIDsCopy.top ()) << '\n';
		videoIDsCopy.pop ();
	}

	cin.get ();
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::showAllCustomers ()
{
	customerList.showAllCustomer ();
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
int MovieRental::getCustomerID ()
{
	//Initialize variables
	int customerID = 0;

	//Loop until correct value has been given
	while (true)
	{
		cout << "Customer ID: " << '\t';
		cin >> customerID;

		//Value must be a positive integer
		if (cin.fail () || customerID < 0)
		{
			cin.clear ();
			cin.ignore (numeric_limits<streamsize>::max (), '\n');
			cerr << "Invalid customer ID" << '\n';
			continue;
		}
		
		return customerID;
	}
}