#ifndef _MOVIELIST_H_
#define _MOVIELIST_H_

#include <string>

using namespace std;

class MovieList
{
	private:
		//Linked List ADT
		typedef struct videoNode
		{
			//Elements of the linked list
			int videoID = 0;
			string movieTitle;
			string movieGenre;
			string movieProduction;
			int numberOfCopies = 0;
			string movieImageFileName;
			struct videoNode* next = nullptr;
		} *videoNodePtr;

		//Node Pointers
		videoNodePtr headNode;
		videoNodePtr currentNode;
		videoNodePtr tempNode;
	public:
		static int movieCounter;

		//Constructors
		MovieList ();
		~MovieList ();

		//Methods
		void newVideo (string title, string genre, string production, int copies, string fileName);
		bool rentAVideo (int givenID);
		void returnAVideo (int givenID);
		void showVideoDetails (int givenVidID);
		void displayVideos ();
		void checkVideoAvailability (int givenVideoID);

		//Additional Operations
		string getTitleByID (int givenID);

		//File Handling
		void writeMovieListToFile();
		void readMovieListFromFile();
};

#endif

