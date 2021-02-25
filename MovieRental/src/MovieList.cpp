#include "MovieList.h"
#include <iostream>

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
void MovieList::insertNewVideo (string title, string genre, string production, int copies)
{
	// initialization for node
	videoNodePtr newVideo = new videoNode();
	videoNodePtr tempNode;

	++movieCounter;
	cout << movieCounter << '\n';
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
		//while (currentNode != nullptr && currentNode->videoID < id)
		//{
		//	tempNode = currentNode;
		//	currentNode = currentNode->next;
		//}

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
void MovieList::rentAVideo ()
{

}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieList::returnAVideo ()
{

}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieList::showVideoDetails ()
{

}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieList::displayVideos ()
{

}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieList::checkVideoAvailability ()
{

}

