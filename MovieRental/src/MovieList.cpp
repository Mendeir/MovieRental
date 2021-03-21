#include "MovieList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>


using namespace std;

//Constructors and Destructors
MovieList::MovieList ()
{
	headNode = nullptr;
	currentNode = nullptr;
	tempNode = nullptr;
}

int MovieList::movieCounter = 0;

MovieList::~MovieList () 
{
	// Delete movieList if exist
	currentNode = headNode;
	while (currentNode != nullptr)
	{
		tempNode = currentNode->next;
		delete currentNode;
		currentNode = tempNode;
	}
}


//-------------------------------
//			 METHODS				
//-------------------------------

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieList::newVideo (string title, string genre, string production, int copies, string fileName)
{	
	// initialization for node
	videoNodePtr newVideo = new videoNode();
	videoNodePtr tempNode;

	++movieCounter;
	
	newVideo->videoID = movieCounter;
	newVideo->movieTitle = title;
	newVideo->movieGenre = genre;
	newVideo->movieProduction = production;
	newVideo->numberOfCopies = copies;
	newVideo->movieImageFileName = fileName;
	newVideo->next = nullptr;

	// if movie list is created already
	if (!headNode)
	{
		// if there are no list yet
		headNode = newVideo;
		newVideo->next = nullptr;

		// if the movie detail is successfully added
		cout << title << " has successfully added " << '\n';
		cin.get();
	}
	else // inserting a movie details
	{
		// Initialization
		currentNode = headNode;
		tempNode = nullptr;

		// Inserting nodes in order
		while (currentNode != nullptr && currentNode->videoID < newVideo->videoID)
		{
			tempNode = currentNode;
			currentNode = currentNode->next;
		}

		// node inserting at the first node
		if (tempNode == nullptr) {
			headNode = newVideo;
			newVideo->next = currentNode;
		}
		else
		{
			tempNode->next = newVideo;
			newVideo->next = currentNode;
		}
		// if the movie detail is successfully added
		cout << title << " has successfully added " << '\n';
		cin.get();

	}
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
bool MovieList::rentAVideo (int givenID)
{
	//Initialize node
	videoNodePtr previousNode;

	//Check if list is empty
	if (headNode == nullptr) 
	{
		cout << "No movies has been added yet. " << '\n';
		return true;
	}
	
	//Initiliaze variables
	currentNode = headNode;
	previousNode = nullptr;

	//Look for the node to rented
	while (currentNode != nullptr && currentNode->videoID != givenID)
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	//If found reduce the number of copies
	if (currentNode != nullptr)
	{
		--currentNode->numberOfCopies;
		cout << "Video ID " << currentNode->videoID << " has been rented successfully!" << '\n';
		return true;
	}
	
	//If node not found
	cout << "Video ID " << givenID  << " is not found on the list" << '\n';
	return false;
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieList::returnAVideo (int givenID)
{
	if (headNode == nullptr)
	{
		cout << "No movies has been added yet. " << '\n';
		return;
	}
	
	//Initiliaze variables
	videoNodePtr previousNode = nullptr;
	currentNode = headNode;

	//Look for the video to be returned
	while (currentNode != nullptr && currentNode->videoID != givenID)
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	//If found increase the number of copies
	if (currentNode != nullptr)
	{
		++currentNode->numberOfCopies;
		cout << "Video ID " << currentNode->videoID << " has been returned" << '\n';
		return;
	}

	//If node not found
	cout << "Video ID " << givenID << " is not found on the list" << '\n';

}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieList::showVideoDetails (int givenVidID)
{
	
	{
		// CHECK IF THE LIST IS EMPTY, IF NOT SHOW THE DETAILS
		if (headNode == nullptr)
		{
			cout << "No movie details to be displayed yet...\n";
			cin.get();
		}
		//SHOWING ALL THE DETAILS OF THE MOVIE

		else
		{
		
			currentNode = headNode;
			//TRAVERSING EACH NODE TO FIND THE GIVEN VIDEO ID
		
			while (currentNode -> videoID != givenVidID && currentNode != nullptr )
			{
				tempNode = currentNode;
				currentNode = currentNode->next;

				if (currentNode == nullptr) {
					cout << "Video ID is not on the list \n";
				}
				
			}
			

			if (givenVidID == currentNode->videoID )
			{

				cout << "Movie Title:\t\t" << currentNode->movieTitle << "\n";
				cout << "Genre :\t\t\t" << currentNode->movieGenre << "\n";
				cout << "Production :\t\t" << currentNode->movieProduction << "\n";
				cout << "Number of Copies :\t" << currentNode->numberOfCopies << "\n";

			}
	
			cin.get();
		}
	}

}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieList::displayVideos ()
{

	// check if the list is empty
	if(headNode == nullptr)
	{
		cout << "No movies has been added yet. \n";
		cin.get();
	}
	// displaying all videos
	else
	{
		cout << "Video ID" << "\t" << setw(10) << "Movie Title" << "\t\t" << setw(10) << "Genre" << "\t\t" << setw(10) << "Production \n";
		currentNode = headNode;
		while (currentNode != nullptr)
		{
			cout << currentNode->videoID << "\t\t" << setw(10) << currentNode->movieTitle;
			cout << "\t" << setw(10) << currentNode->movieGenre << "\t\t" << setw(10) << currentNode->movieProduction << "\n";
			currentNode = currentNode->next;
		}
		cin.get();
	}
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieList::checkVideoAvailability (int givenVideoID)
{

	// CHECK IF THE LIST IS EMPTY, IF NOT SHOW THE DETAILS
	if (headNode == nullptr)
	{
		cout << "No movie details to be displayed yet...\n";
		cin.get();
	}
	//SHOWING ALL THE DETAILS OF THE MOVIE

	else
	{

		currentNode = headNode;
		//TRAVERSING EACH NODE TO FIND THE GIVEN VIDEO ID



		while (currentNode->videoID != givenVideoID &&currentNode != nullptr)
		{
			tempNode = currentNode;
			currentNode = currentNode->next;

			if (currentNode == nullptr) {
				cout << "Video ID is not on the list\n";
			}

		}


		if (givenVideoID == currentNode -> videoID)
		{

			cout << "Movie Title:\t\t" << currentNode->movieTitle << "\n";
			cout << "Genre :\t\t\t" << currentNode->movieGenre << "\n";
			cout << "Production :\t\t" << currentNode->movieProduction << "\n";
			cout << "Number of Copies :\t" << currentNode->numberOfCopies << "\n";
			cout << "Availability: \t\t";
		}



		if (currentNode->numberOfCopies == 0)
		{
		
			cout << "NOT AVAILABLE\n";
		}
		else
		{
			
			cout << "AVAILABLE\n";
		}
		
		
		cin.get();
	}
}
  
/**
	Description:
	Precondition:
	Postcondtion:
*/
string MovieList::getTitleByID (int givenID)
{
	//Initialize string
	string movieTitle = " ";
	
	//Check if empty 
	if (headNode == nullptr)
	{
		movieTitle = "missing title - null headnode";
		return movieTitle;
	}

	//Initiliaze variables
	currentNode = headNode;
	videoNodePtr previousNode = nullptr;

	//Look for the node to rented
	while (currentNode != nullptr && currentNode->videoID != givenID)
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	//If found reduce the number of copies
	if (currentNode != nullptr)
	{
		movieTitle = currentNode->movieTitle;
		return movieTitle;
	}

	//If node not found
	movieTitle = "missing title - node missing";
	return movieTitle;
}
void MovieList::writeMovieListToFile()
{
	// Initialize Variable
	string filePath = "src/Movies.txt";
	ofstream videoOutStream;

	videoOutStream.open(filePath);
	// Check if file was successful
	if (videoOutStream.fail())
		cout << filePath << ": Opening failed. \n";

	currentNode = headNode;
	while (currentNode != nullptr)
	{
		videoOutStream	<< currentNode->videoID << ","
						<< currentNode->movieTitle << ","
						<< currentNode->movieGenre << ","
						<< currentNode->movieProduction << '\n';
		currentNode = currentNode->next;
	}
	videoOutStream.close();
}
void MovieList::readMovieListFromFile()
{
	string fileLine;
	string filePath = "src/Movies.txt";
	ifstream videoIfStream;

	videoIfStream.open(filePath);
	//Check for error
	if (videoIfStream.fail())
		cout << filePath << "Opening Failed. \n";
	
	while (getline(videoIfStream, fileLine))
	{
		// initializing variables
		istringstream fileStream(fileLine);
		string lineElements;
		vector <string> splitLine;

		while (getline(fileStream, lineElements, ','))
			splitLine.push_back(lineElements);
		

	}
}

/*
currentNode = headNode;
	while (currentNode != nullptr)
	{
		videoIfStream >> currentNode->videoID
					  >> currentNode->movieTitle
					  >> currentNode->movieGenre
					  >> currentNode->movieProduction;
		currentNode = currentNode->next;
	}

*/