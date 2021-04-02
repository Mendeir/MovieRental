#include "MovieList.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>


using namespace std;
using namespace cv;

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


//***************************
//*		   METHODS          *
//***************************

/**
	Author: Dave Bornilla
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

	//Add the additional directory for the fileName
	string filePath = "C:/images/" + fileName;
	
	newVideo->videoID = movieCounter;
	newVideo->movieTitle = title;
	newVideo->movieGenre = genre;
	newVideo->movieProduction = production;
	newVideo->numberOfCopies = copies;
	newVideo->movieImageFilePath = filePath;
	newVideo->next = nullptr;

	// if movie list is created already
	if (!headNode)
	{
		// if there are no list yet
		headNode = newVideo;
		newVideo->next = nullptr;

		// if the movie detail is successfully added
		cout << title << " has successfully added " << '\n';
		//cin.get();
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
		//cin.get();
	}
}

/**
	Author: Adrianne Magracia
	Description:  Traverses to the list and decrements numberOfCopies 
				  if the givenId is in the list
	Precondition: givenID is an integer and the list is not empty
	Postcondtion: It decrements the numberOfCopies if ID is found and return true or 
				  prompts the user if the list is empty or ID is not on the list and 
				  return false
*/
bool MovieList::rentAVideo (int givenID)
{
	//Check if list is empty
	if (headNode == nullptr) 
	{
		cout << "No movies has been added yet. " << '\n';
		return true;
	}
	
	//Initiliaze variables
	currentNode = headNode;

	//Look for the node to rented
	while (currentNode != nullptr && currentNode->videoID != givenID)
		currentNode = currentNode->next;

	//If found reduce the number of copies and return
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
	Author: Adrianne Magracia
	Description:  Traverses to the list and increments numberOfCopies
				  if the givenId is in the list
	Precondition: givenID is an integer and the list is not empty
	Postcondtion: It increments the numberOfCopies if ID is found or prompts 
				  the user if the list is empty or ID is not on the list
*/
void MovieList::returnAVideo (int givenID)
{
	//Check if list is empty
	if (headNode == nullptr)
	{
		cout << "No movies has been added yet. " << '\n';
		return;
	}
	
	//Initiliaze variables
	currentNode = headNode;

	//Look for the video to be returned
	while (currentNode != nullptr && currentNode->videoID != givenID)
		currentNode = currentNode->next;
	
	//If found increase the number of copies
	if (currentNode != nullptr)
	{
		++currentNode->numberOfCopies;
		cout << "Video ID " << currentNode->videoID << " has been returned" << '\n';
		return;
	}

	//If video id not found
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
		
			while ( currentNode != nullptr && currentNode->videoID != givenVidID)
			{
				tempNode = currentNode;
				currentNode = currentNode->next;
				
			}
			if (currentNode  == nullptr)
			{
				cout << "NO MOVIE DETAILS FOUND\n\n";
				return;
			}
		
			if (givenVidID == currentNode->videoID)
			{

				cout << "Movie Title:\t\t" << currentNode->movieTitle << "\n";
				cout << "Genre :\t\t\t" << currentNode->movieGenre << "\n";
				cout << "Production :\t\t" << currentNode->movieProduction << "\n";
				cout << "Number of Copies :\t" << currentNode->numberOfCopies << "\n\n";
				
				//Displaying image
				Mat movieIMG = imread (currentNode->movieImageFilePath);

				//Check if image is empty or not
				if (movieIMG.empty ()) 
				{
					cout << currentNode->movieImageFilePath << " not found." << '\n';
					return;
				}

				imshow (currentNode->movieTitle, movieIMG);
				waitKey (0);
				

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
		cout << "Video ID" << "\t" << setw(19) << "Movie Title" << setw(26) << "Genre" << "\t\t" << setw(20) << "Production \n";
		currentNode = headNode;
		while (currentNode != nullptr)
		{
			cout << currentNode->videoID << "\t\t\t" << setw(25) << left << currentNode->movieTitle;
			cout << "\t" << setw(20) << left << currentNode->movieGenre << "\t" << setw(20) << left << currentNode->movieProduction << "\n";
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

		while (currentNode != nullptr && currentNode->videoID != givenVideoID)
		{
			tempNode = currentNode;
			currentNode = currentNode->next;
		}
		if (currentNode == nullptr)
		{
			cout << "No movies has been added yet. \n";
			return;
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
		
			cout << "NOT AVAILABLE\n\n";
		}
		else
		{
			
			cout << "AVAILABLE\n\n";
		}
		
		
		cin.get();
	}
}
 
//****************************
//*	 ADDITIONAL OPERATIONS   *
//****************************
/**
	Author: Adrianne Magracia
	Description:  Gives the movie title given an ID
	Precondition: givenID is an integer and the list is not empty
	Postcondtion: It returns the movieTitle in string type or returns
				  the string that indicates the error
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

	//Look for the node to be displayed by title
	while (currentNode != nullptr && currentNode->videoID != givenID)
		currentNode = currentNode->next;

	//If found return the movie title
	if (currentNode != nullptr)
	{
		movieTitle = currentNode->movieTitle;
		return movieTitle;
	}

	//If node not found
	movieTitle = "missing title - node missing";
	return movieTitle;
}

//***************************
//*	    FILE HANDLING       *
//***************************
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
		videoOutStream << currentNode->videoID << ","
			<< currentNode->movieTitle << ","
			<< currentNode->movieGenre << ","
			<< currentNode->movieProduction << ","
			<< currentNode->numberOfCopies << ","
			<< currentNode->movieImageFilePath << "\n";
						
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
		int readId;
		string readTitle;
		string readGenre;
		string readProduction;
		int readCopies;
		string readFilename;
		vector <string> splitLine;

		while (getline(fileStream, lineElements, ','))
			splitLine.push_back(lineElements);
		
		readTitle = splitLine[1];
		readGenre = splitLine[2];
		readProduction = splitLine[3];
		readCopies = stoi(splitLine[4]);
		readFilename = splitLine[5];

		newVideo(readTitle, readGenre, readProduction, readCopies, readFilename);

	}
}

