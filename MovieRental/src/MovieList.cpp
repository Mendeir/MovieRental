#include "MovieList.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Constructors and Destructors
MovieList::MovieList ()
{
	headNode = nullptr;
	currentNode = nullptr;
	tailNode = nullptr;
}

int MovieList::movieCounter = 0;

//~MovieList::MovieList () { }


//-------------------------------
//			 METHODS				
//-------------------------------

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieList::newVideo (string title, string genre, string production, int copies)
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
void MovieList::showVideoDetails ()
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

			while (currentNode != nullptr)
			{
				cout << "\n";
			
				cout << "Video ID:\t\t" << currentNode->videoID << "\n";
				cout << "Movie Title:\t\t" << currentNode->movieTitle << "\n";
				cout << "Genre :\t\t\t" << currentNode->movieGenre << "\n";
				cout << "Production :\t\t" << currentNode->movieProduction << "\n";
				cout << "Number of Copies :\t" << currentNode->numberOfCopies << "\n";


				currentNode = currentNode->next;
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
	//check if the list is empty
	if (headNode == nullptr)
	{
		cout << "No movie details to be displayed yet...\n";
		cin.get();
	}	
	else
	{

		currentNode = headNode;

		while (givenVideoID == currentNode->videoID)
		{
			cout << "\n";
			cout << "Movie Title:\t\t" << currentNode->movieTitle << "\n";
			cout << "Genre :\t\t\t" << currentNode->movieGenre << "\n";
			cout << "Production :\t\t" << currentNode->movieProduction << "\n";
			cout << "Number of Copies :\t" << currentNode->numberOfCopies << "\n";
			currentNode = currentNode->next;

			if (currentNode->numberOfCopies == 0)
			{
				cout << "\n";
				cout << "NOT AVAILABLE";
			}
			else
			{
				cout << "\n";
				cout << "AVAILABLE";
				currentNode = currentNode->next;
			}

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


