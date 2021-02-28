#include "CustomerList.h"
#include <iostream>

using namespace std;

/**	
	Description:
	Precondition:
	Postcondtion:
*/	
void CustomerList::addCustomer (Customer givenCustomer);
{
	customerCollection.add(givenCustomer);
}

void CustomerList::showAllCustomer () 
{
	for (Customer customers : customerCollection) 
	{
		cout << customers;
	}
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void showCustomerDetails();

/**
	Description:
	Precondition:
	Postcondtion:
*/
void printCustomerList ();