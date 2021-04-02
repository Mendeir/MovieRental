#ifndef _MOVIERENTAL_H_
#define _MOVIERENTAL_H_

#include "MovieList.h"
#include "CustomerList.h"
#include <stack>	
#include <unordered_map>

using namespace std;

class MovieRental
{
	private:
		//Instance Variables
		CustomerList customerList;
		MovieList movieList;
		stack<int> rentedVideoIDs;
		unordered_map<int, stack<int>> rentedVideos;

	public:
		//Methods
		void newVideo ();
		void rentAVideo ();
		void returnVideo ();
		void showVideoDetails ();
		void displayAllVideos ();
		void checkVideoAvailability ();
		void addNewCustomer ();
		void showCustomerDetails ();
		void listVideosRentedByCustomer ();
		int getCustomerID ();

		void promptUser ();

		//File Handling Methods
		void writeMovieListToFile();
		void readMovieListFromFile();
		void writeCustomerToFile ();
		void readCustomerToFile ();
		void writeCustomerRentToFile ();
		void readCustomerRentFromFile ();
		void testReadingFile ();
};



#endif // !_MOVIERENTAL_H_


