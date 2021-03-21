#include "MovieRental.h"
#include <iostream>
#include <limits>
#include <fstream>

using namespace std;


//***************************
//*		   METHODS          *
//***************************

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::newVideo (string title, string genre, string production, int copies, string fileName)
{
	movieList.newVideo(title, genre, production, copies, fileName);
	cout << '\n';
	promptUser ();
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

	if (!customerList.showCustomerDetails (givenCustomerID))
	{
		promptUser ();
		return;
	}

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
	promptUser ();
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

	if (!customerList.showCustomerDetails (givenCustomerID))
	{
		promptUser ();
		return;
	}
	
	cout << '\n';

	//Check if a key has been made for the id
	if (rentedVideos.find (givenCustomerID) == rentedVideos.end ())
	{
		cout << "Customer ID not found / Customer hasn't rented videos." << '\n';
		promptUser ();
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
	promptUser ();
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::showVideoDetails ()
{
	int givenVidID = 0;
	cout << "\n";
	cout << "Video ID: \t\t";
	cin >> givenVidID;

	
	movieList.showVideoDetails(givenVidID);
	promptUser();

}

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
void MovieRental::checkVideoAvailability()
{
	int givenVideoID = 0;
	cout << "\n";
	cout << "Video ID: \t\t";
	cin >> givenVideoID;
	movieList.checkVideoAvailability(givenVideoID);
	promptUser();

}


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
	promptUser ();

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

	if (!customerList.showCustomerDetails (givenCustomerID))
	{
		promptUser ();
		return;
	}

	cout << '\n';

	//Check if a key has been made for the id
	if (rentedVideos.find (givenCustomerID) == rentedVideos.end ())
	{
		cout << "Customer ID not found / Customer hasn't rented videos." << '\n';
		promptUser ();
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
		
	promptUser ();
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

void MovieRental::promptUser ()
{
	cout << "Press enter to continue ";
	cin.get ();
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::writeCustomerToFile ()
{
	customerList.writeCustomerToFile ();
}

void MovieRental::readCustomerToFile ()
{
	customerList.readCustomerToFile ();
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::writeCustomerRentToFile ()
{
	//Initialize variable
	string filePath = "src/CustomerRent.txt";
	ofstream customerRentOutStream;

	//Open file and check if successful
	customerRentOutStream.open (filePath);
	if (customerRentOutStream.fail ())
		cout << filePath << ": Opening failed. \n";

	//Put Map values into the file
	for (pair<int, stack<int>> contents : rentedVideos)
	{
		customerRentOutStream << contents.first << " ";
		while (!contents.second.empty ())
		{
			customerRentOutStream << contents.second.top ();
			contents.second.pop ();

			if (contents.second.size() != 0)
				customerRentOutStream << ",";
		}

		customerRentOutStream << '\n';
	}

	customerRentOutStream.close ();
}

void MovieRental::readCustomerRentFromFile () 
{
	//Initialize variable
	string fileLine = "";
	string filePath = "src/CustomerRent.txt";
	ifstream customerRentInStream;
	int mapKey;
	

	//Open file and check if successful
	customerRentInStream.open (filePath);
	if (customerRentInStream.fail ())
		cout << filePath << ": Opening failed. \n";

	//Put file values into Map
	
	while (getline (customerRentInStream, fileLine))
	{
		int stringCounter = 0;
		string mapKeyString = "";
		stack<int> tempStack;

		if (fileLine.size() > 0)
		{
			while (fileLine [stringCounter] != ' ')
			{
				mapKeyString += fileLine [stringCounter];
				++stringCounter;
			}

			mapKey = stoi (mapKeyString);

			while (stringCounter < fileLine.size ())
			{
				string stackValueString = "";
				++stringCounter;
				while (fileLine[stringCounter] != ',')
				{
					stackValueString += fileLine [stringCounter];
					++stringCounter;

					if (fileLine.size () == stringCounter)
						break;
				}

				tempStack.push (stoi(stackValueString));
				
			}

			rentedVideos.insert ({ mapKey, tempStack});
		}
	}

	//cout << "File read successful!" << '\n';
}


