#include "Customer.h"
#include <string>

using namespace std;

//Constructor
Customer::Customer (int givenID, string givenName, string givenAddress)
{
	++customerIdCounter;
	if (customerIdCounter == givenID || givenID == 0) 
		customerId = customerIdCounter;
	else
		customerId = givenID;

	customerName = givenName;
	customerAddress = givenAddress;
}

Customer::Customer ()
	:Customer (0, "Unkown", "Unkown")
{}


int Customer::customerIdCounter = 0;
//~Customer::Customer () {}

//Methods

//Getters
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