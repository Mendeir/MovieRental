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
		customerOutStream << customer.getCustomerId () << ", "
						  << customer.getCustomerName () << ", " 
						  << customer.getCustomerAddress ()	<< '\n';
	}

	customerOutStream.close ();
}

void CustomerList::readCustomerToFile ()
{
	//Initialize variable
	string fileLine = "";
	string filePath = "src/Customer.txt";
	ifstream customerInStream;

	customerInStream.open (filePath);
	//Open file and check if successful
	if (customerInStream.fail ())
		cout << filePath << ": Opening failed. \n";

	//Put file values into vector
	while (getline (customerInStream, fileLine)) 
	{
		//Initialize variables
		const int SPLIT_SIZE = 3;
		
		stringstream fileLineStream(fileLine);
		string splitLine;
		char delimeter = ',';
		
		string storeLine [SPLIT_SIZE];
		int lineCounter = 0;

		while (getline (fileLineStream, splitLine, delimeter))
		{
			cout << splitLine << '\n';
			storeLine [lineCounter] = splitLine;
			++lineCounter;
		}
		cout << "Debug: " << ":" << storeLine [0] << ":"  << storeLine [1] << ":"  << storeLine [2] << '\n';

		//Initialize into proper variables
		int customerId = stoi(storeLine [0]);
		string customerName = storeLine [1];
		string customerAddress = storeLine [2];

		//Assign the proper variables to customer class and put into variables
		Customer newFileCustomer;
		newFileCustomer.setCustomerId (customerId);
		newFileCustomer.setCustomerName (customerName);
		newFileCustomer.setCustomerAddress (customerAddress);
		customerCollection.push_back (newFileCustomer);
	}
}