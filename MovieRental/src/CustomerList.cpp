#include "CustomerList.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

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
void CustomerList::writeCustomerToFile ()
{
	//Initialize variable
	string filePath = "src/Customer.txt";
	ofstream customerOutStream;

	customerOutStream.open (filePath);
	//Open file and check if successful
	if (customerOutStream.fail ())
		cout << filePath << ": Opening failed. \n";

	//Put vector value of Customer object into file
	for (Customer customer : customerCollection)
	{
		customerOutStream << customer.getCustomerId () << ","
						  << customer.getCustomerName () << "," 
						  << customer.getCustomerAddress ()	<< '\n';
	}

	customerOutStream.close ();
}

/**
	Description:
	Precondition:
	Postcondtion:
*/
void CustomerList::readCustomerToFile ()
{
	//Initialize variable
	string fileLine;
	string filePath = "src/Customer.txt";
	ifstream customerInStream;

	//Open file and check if successful
	customerInStream.open (filePath);
	if (customerInStream.fail ())
		cout << filePath << ": Opening failed. \n";

	//Put file values into vector
	while (getline (customerInStream, fileLine))
	{
		//Initialize variables
		istringstream fileStream (fileLine);
		string lineElements;
		vector<string> splitLine;

		//The line is separated by comma with the following order
		//customerID, customerName, customerAddress
		while (getline (fileStream, lineElements, ','))
			splitLine.push_back (lineElements);
		
		//Adding the customer to the vector
		int customerId = stoi (splitLine [0]);
		Customer newCustomer (customerId, splitLine [1], splitLine [2]);
		customerCollection.push_back (newCustomer);
	}
}