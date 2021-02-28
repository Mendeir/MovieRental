#include "CustomerList.h"
#include <vector>
#include <iostream>

using namespace std;

/**
	Description:
	Precondition:
	Postcondtion:
*/
void CustomerList::addCustomer (Customer givenCustomer)
{
	customerCollection.push_back(givenCustomer);
}

void CustomerList::showAllCustomer ()
{
	for (Customer customers : customerCollection)
	{
		cout << customers.getCustomerId() << '\n';
		cout << customers.getCustomerName () << '\n';
		cout << customers.getCustomerAddress () << '\n';
	}

	cin.get ();
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
void printCustomerList ();