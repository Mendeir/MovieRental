#include "Customer.h"
#include <string>

using namespace std;

//***************************
//*	     Constructor        *
//***************************
Customer::Customer (int givenID, string givenName, string givenAddress)
{
	const int DEFAULT_ID = 0;

	//If given id is not from file, give generated customerID
	++customerIdCounter;
	if (givenID == DEFAULT_ID)
		customerId = customerIdCounter;
	else
		customerId = givenID;

	customerName = givenName;
	customerAddress = givenAddress;
}

Customer::Customer ()
	:Customer (0, "Unkown", "Unkown")
{}

//Description: Responsible for the auto generation of the CustomerID starts with 0
int Customer::customerIdCounter = 0;


//***************************
//*		   METHODS          *
//***************************

//Setters and Getters
int Customer::getCustomerId()
{
	return customerId;
}

string Customer::getCustomerName ()
{
	return customerName;
}

string Customer::getCustomerAddress ()
{
	return customerAddress;
}

void Customer::setCustomerId (int id)
{
	customerId = id;
}

void Customer::setCustomerName(string name)
{
	customerName = name;
}

void Customer::setCustomerAddress(string address)
{
	customerAddress = address;
}