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
		videoNodePtr tailNode;
	public:
		static int movieCounter;

		//Constructors
		MovieList ();
		//~MovieList ();

		//Methods
		void newVideo (string title, string genre, string production, int copies);
		void rentAVideo ();
		void returnAVideo ();
		void showVideoDetails ();
		void displayVideos ();
		void checkVideoAvailability (int givenVideoID);

};

#endif

