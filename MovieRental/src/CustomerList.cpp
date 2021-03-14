#include "CustomerList.h"
#include <vector>
#include <iostream>

using namespace std;

//Methods
/**
	Description:
	Precondition:
	Postcondtion:
*/
void CustomerList::addCustomer (Customer givenCustomer)
{
	customerCollection.push_back(givenCustomer);
}

/**
	Description:
	Precondition:
	Postcondtion:
*/

bool CustomerList::showCustomerDetails (int givenId)
{
	for (Customer customers : customerCollection)
	{
		// Searching for the given VIDEO ID by the user
		if (customers.getCustomerId() == givenId)
		{
			// IF THE GIVENCUSTOMER ID IS EQUAL TO GIVEN ID BY THE USER IT WILL GOING TO PRINT THE DETAILS
			cout << "Name: "  << "\t\t" << customers.getCustomerName () << '\n';
			cout << "Address: " << '\t' << customers.getCustomerAddress () << '\n';
			return true;
		}
	}

	cout << "Customer not found." << '\n';
	return false;
}

/**
	Description:
	Precondition:
	Postcondtion:
*/