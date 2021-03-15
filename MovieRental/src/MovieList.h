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
			int videoID;
			string movieTitle;
			string movieGenre;
			string movieProduction;
			int numberOfCopies;
			string movieImageFileName;
			struct videoNode* next;
		} *videoNodePtr;

		// added node pointers
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
		void showVideoDetails ();
		void displayVideos ();
		void checkVideoAvailability (int givenVideoID);
		void searchVideoID (int givenID);
		string getTitleByID (int givenID);
		void writeMovieListToFile();
		void readMovieListFromFile();
};

#endif

