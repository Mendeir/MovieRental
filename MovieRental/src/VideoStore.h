#ifndef _VIDEOSTORE_H_
#define _VIDEOSTORE_H_

#include <string>

using namespace std;

class VideoStore
{
	private:
		//Linked List ADT
		typedef struct videoeNode
		{
			//Elements of the linked list
			int videoID;
			string movietitle;
			string genre;
			string production;
			int numberOfCopies;
			string movieImageFileName;

		} *videoNodePtr;

	public:
		//Constructors
		VideoStore ();
		~VideoStore ();

		//Methods
		void insertNewVideo ();
		void rentAVideo ();
		void returnAVideo ();
		void showVideoDetails ();
		void displayVideos ();
		void checkVideoAvailability ();

};

#endif

