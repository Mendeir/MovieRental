#include "CustomerList.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//***************************
//*		   METHODS          *
//***************************
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
	Author : Padilla, Joshua Matthew C.
	Description: Show the following details of the customer such as name, address and the video rented.
	Precondition: The givenID atleast must satisfy any value in the video ID to display the details of 
					the following customer
	Postcondtion:  Display the whole details of customer on the screen.
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

//***************************
//*     FILE HANDLING       *
//***************************
/**
	Author: Adrianne Magracia
	Description:  Adds the contents of the vector into the file.
	Precondition: Vector to be processed is a Customer Object.
	Postcondtion: The vector contents is written in the file following the format
				  customerId,customerName,customerAddress with the file name decided by 
				  the filePath.
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
	Author: Adrianne Magracia
	Description:  Reads the file and puts it in the vector of Customer object.
	Precondition: filePath is an existing file and vectors is existing
				  and initialized.
	Postcondtion: The file contents is created into a Custoemr Object and 
				  inserted in the vector of Customer.
*/
void CustomerList::readCustomerToFile ()
{
	//Initialize variables
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

		//Inserts a single line in the file into the stream
		//and splits the line through commma and inserts it into vector
		while (getline (fileStream, lineElements, ','))
			splitLine.push_back (lineElements);
		
		//Creates a Customer object and adding it to the vector
		int customerId = stoi (splitLine [0]);
		Customer newCustomer (customerId, splitLine [1], splitLine [2]);
		customerCollection.push_back (newCustomer);
	}
}