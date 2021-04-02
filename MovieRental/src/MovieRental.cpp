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
void MovieRental::newVideo ()
{
	string title;
	string genre;
	string production;
	int numCopies;
	string userFile;
	MovieList movieItem;

	cout << "Video ID: " << movieItem.movieCounter + 1 << '\n';

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Movie Title: ";
	getline(cin, title);

	cout << "Genre: ";
	getline(cin, genre);

	cout << "Production: ";
	getline(cin, production);

	cout << "Numbers of copies: ";
	cin >> numCopies;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "File Name: ";
	getline(cin, userFile);

	movieList.newVideo(title, genre, production, numCopies, userFile);
	cout << '\n';
	promptUser ();
}

/**
	Author: Adrianne Magracia
	Description:  Gets the customerID first and asks the user on what videos will the 
				  customer rent which is then inserted into the unordered_map with the
				  customerID as the key and the movieID's as the values.
	Precondition: The stack for the video id values and the map for the rented videos 
				  should exists. givenCustomerID should also exist from the list and 
				  the videos to be rented should also exist. 
	Postcondtion: The input given by the user is inserted in the map.
*/
void MovieRental::rentAVideo ()
{
	//Initialize Variables
	char choice;
	int givenCustomerID = getCustomerID ();

	//If the customerID is not found on the list end method and prompt user
	if (!customerList.showCustomerDetails (givenCustomerID))
	{
		promptUser ();
		return;
	}

	cout << '\n';

	//Collect video ID's to be rented
	while (true)
	{
		//Initialize variable and prompt the user for ID
		int givenVideoID = 0;
		cout << "Enter the video ID to be rented: ";
		cin >> givenVideoID;

		//Reduce number of copies and put videoID on stack if
		//the given movie is on the linked list
		if (movieList.rentAVideo (givenVideoID)) 
			rentedVideoIDs.push (givenVideoID);

		//Ask user if continue
		cout << "Input Y or y to continue renting a movie: ";
		cin >> choice;

		cout << '\n';

		//Terminating statement
		if (choice != 'y' && choice != 'Y')
			break;
	}

	//Put customerID(int) as key and rentedVideoIDs(stack) as value in the unordered map
	rentedVideos.insert ({ givenCustomerID, rentedVideoIDs });	
	promptUser ();
}

/**
	Author: Adrianne Magracia
	Description:  Gets the customerID that will return the videos in which the stack
				  will be emptied and the map will be then deleted for the said customer.
	Precondition: The given customerID must exist within the list and the customer has atleast
				  rented 1 videos meaning that a key and value pair must exist within the map.
	Postcondtion: The key and value pair must not exist within the map.
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
void MovieRental::addNewCustomer ()
{
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
	cin.get();
	customerList.addCustomer(newCustomer);
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
	Author: Adrianne Magracia
	Description:  Gets the customerID and display the title of the movies 
				  rented by the user.
	Precondition: The given customerID must exist within the list and the customer has atleast
				  rented 1 videos meaning that a key and value pair must exist within the map.
	Postcondtion: The videos rented must be displayed on the screen.
*/
void MovieRental::listVideosRentedByCustomer ()
{
	//Initialize variables
	int givenCustomerID = getCustomerID ();

	//If the customerID is not found on the list end method and prompt user
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

	//Make a copy of the customer's stack so that the original stack will not be empty
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

void MovieRental::writeMovieListToFile()
{
	movieList.writeMovieListToFile();
}

void MovieRental::readMovieListFromFile()
{
	movieList.readMovieListFromFile();
}

