#include "MovieRental.h"
#include <iostream>
#include <limits>
#include <fstream>

using namespace std;


//***************************
//*		   METHODS          *
//***************************

/**
*	Author:  Dave Bornilla
	Description: Adding new video and its infomations from the user.
				 The program will add if the linked list is empty and
				 if the linked list is not empty it will insert the 
				 informations.
	Precondition: The title, genre, production, number of copies and
				  filename of the image are waiting to be stored and 
				  video Id will automatically generate and start at 1.
	Postcondtion: The input given by the user will automatically be 
				  stored in the linked list. 
*/
void MovieRental::newVideo ()
{
	//Initializing Variables
	string title;
	string genre;
	string production;
	int numCopies;
	string userFile;
	MovieList movieItem;

	// Video ID auto generated
	cout << "Video ID: " << movieItem.movieCounter + 1 << '\n';
	// For users input format
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Asking the user for informations and inputs
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

	// Calling the function of newVideo in the movielist class
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
		int givenVideoID = getVideoID ();
		movieList.checkVideoAvailability (givenVideoID);

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
	//Initialize variable
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
	int givenVidID = getVideoID ();
	movieList.showVideoDetails(givenVidID);
	promptUser();

}

/**
*	Author:  Dave Bornilla
	Description: Display all the informations about the movies
				 stored by the user.
	Precondition: The videoID, movie title, genre and production 
				  will be displayed according to the users input
	Postcondtion: It will display the user's all the movies and 
				  and is ID, title, genre and production in order. 
*/
void MovieRental::displayAllVideos()
{
	// Calling the displayVideos in the movilist class
	movieList.displayVideos();
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::checkVideoAvailability()
{
	int givenVideoID = getVideoID ();
	movieList.checkVideoAvailability(givenVideoID);
	promptUser();

}


/**
*	Author: Dave Bornilla
	Description: Ask the user its detailed customer name and
				 address and will call the addCustomer in
				 customerList class. 
	Precondition: The customer name and the address will be 
				  ask the user and the customer ID is autogenerated.
	Postcondtion: The customer name and address will be stored based
				  on the user's input and will be added automatically
				  to the list.
*/
void MovieRental::addNewCustomer ()
{
	// Initializing variables
	Customer newCustomer;
	string userName;
	string userAddress;

	// Autogenerated ID
	cout << "Customer ID: " << newCustomer.getCustomerId() << '\n';

	cin.ignore(32767, '\n');

	// Ask the user's for name and address and inputs
	cout << "Name: ";
	getline(cin, userName);
	
	// Setting the customer name by the user's input
	newCustomer.setCustomerName(userName);
	cout << "Address: ";
	getline(cin, userAddress);

	// Setting the customer address by the user's input
	newCustomer.setCustomerAddress(userAddress);
	cin.get();
	// Calling the addCustomer method in the customerList class.
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

int MovieRental::getVideoID ()
{
	//Initialize variables
	int movieID = 0;

	//Loop until correct value has been given
	while (true)
	{
		cout << "Movie ID: " << '\t';
		cin >> movieID;

		//Value must be a positive integer
		if (cin.fail () || movieID < 0)
		{
			cin.clear ();
			cin.ignore (numeric_limits<streamsize>::max (), '\n');
			cerr << "Invalid movie ID" << '\n';
			continue;
		}

		return movieID;
	}
}

/**
	Author: Adrianne Magracia
	Description:  Gets the customerID with error checking 
	Precondition: N/A
	Postcondtion: The customerID being returned must be an integer
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

/**
	Author: Adrianne Magraica
	Description:  Pauses the program and waits for a key input
	Precondition: N/A
	Postcondtion: The cout must be displayed and the program must wait for a key input
*/
void MovieRental::promptUser ()
{
	cout << "Press enter to continue ";
	cin.get ();
}

/**
    Author: Adrianne Magracia
	Description:  Calls the filehandling function of the customerList
	Precondition: N/A
	Postcondtion: Must be able to call the filehandling function of the customerList
*/
void MovieRental::writeCustomerToFile ()
{
	customerList.writeCustomerToFile ();
}

/**
	Author: Adrianne Magracia
	Description:  Calls the filehandling function of the customerList
	Precondition: N/A
	Postcondtion: Must be able to call the filehandling function of the customerList
*/
void MovieRental::readCustomerToFile ()
{
	customerList.readCustomerToFile ();
}

/**
	Author: Adrianne Magracia
	Description:  Writes the unordered map contents to the file
	Precondition: Unordered map to be processed has a integer as key and the value
				  is a stack
	Postcondtion: The unordered map contents is written in the following format
				   customerID movieID,movieID,...,movieID
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


/**
	Author: Adrianne Magracia
	Description:  Reads the file and inserts it into the unordered map with
				  the customerID as the key value and the movieID as the 
				  stack value.
	Precondition: filePath is an existing file and the unordered is existing
				  and initialized
	Postcondtion: The file contents is inserted into the unordered map following the
				  customerID key and the movieID value format.
*/
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
		//Initialize variables
		int stringCounter = 0;
		string mapKeyString = "";
		stack<int> tempStack;

		//Check if the fileLine has content
		if (fileLine.size() > 0)
		{
			//Gets the customerID in the file until it reads a whitespace
			//The whitespace was included to separate the customerID and movieID
			while (fileLine [stringCounter] != ' ')
			{
				mapKeyString += fileLine [stringCounter];
				++stringCounter;
			}

			//Converts the string key to and integer key
			mapKey = stoi (mapKeyString);

			//Reads the remaining line going on until the end of line
			while (stringCounter < fileLine.size ())
			{
				//Initialize variable
				string stackValueString = "";
				++stringCounter;

				//Gets the movieID in the file until it reads a comma
				//The comma separates each movieID
				while (fileLine[stringCounter] != ',')
				{
					stackValueString += fileLine [stringCounter];
					++stringCounter;

					//Terminating statement if the end of the line is reached
					if (fileLine.size () == stringCounter)
						break;
				}

				//Converts the string value of stack into integer then pushes it
				//Into the stack.
				tempStack.push (stoi(stackValueString));
				
			}
			//Insert the key value pair into the map
			rentedVideos.insert ({ mapKey, tempStack});
		}
	}
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::writeMovieListToFile()
{
	// Calling the writeMovieListToFile method for writing data to the file.
	movieList.writeMovieListToFile();
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::readMovieListFromFile()
{
	// Calling the readMovieListFromFile method for reading data from a the file.
	movieList.readMovieListFromFile();
}

