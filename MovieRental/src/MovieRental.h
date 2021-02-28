#ifndef _MOVIERENTAL_H_
#define _MOVIERENTAL_H_

#include "MovieList.h"
#include "CustomerList.h"

class MovieRental
{
	private:
		//Instance Variables
		CustomerList customerList;
		MovieList movieList;

	public:
		//Methods
		void newVideo (string title, string genre, string production, int copies);
		void rentAVideo ();
		void returnVideo ();
		void showVideoDetails ();
		void displayAllVideos ();
		void checkVideoAvailability ();
		void addNewCustomer (Customer givenCustomer);
		void showCustomerDetails ();
		void listVideosRentedByCustomer ();
		void showAllCustomers ();
};



#endif // !_MOVIERENTAL_H_


