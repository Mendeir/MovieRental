#include "MovieRental.h"
#include <iostream>

using namespace std;



//***************************
//*		   METHODS          *
//***************************

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::newVideo ()
{

}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::rentAVideo ()
{
	customerList.searchCustomerId (2);
	customerList.searchCustomerId (3);
	cin.get ();
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void returnVideo ();

/**
	Description:
	Precondition:
	Postcondtion:
*/
void showVideoDetails ();

/**
	Description:
	Precondition:
	Postcondtion:
*/
void displayAllVideos ();

/**
	Description:
	Precondition:
	Postcondtion:
*/
void checkVideoAvailability ();

/**
	Description:
	Precondition:
	Postcondtion:
*/
void MovieRental::addNewCustomer (Customer givenCustomer)
{
	customerList.addCustomer (givenCustomer);
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void showCustomerDetails ();

/**
	Description:
	Precondition:
	Postcondtion:
*/
void listVideosRentedByCustomer ();


void MovieRental::showAllCustomers ()
{
	customerList.showAllCustomer ();
}