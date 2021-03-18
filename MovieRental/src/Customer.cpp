#include "Customer.h"
#include <string>

using namespace std;

//Constructor
Customer::Customer ()
{
	++customerIdCounter;
	customerId = customerIdCounter;
	customerName = "Unkown";
	customerAddress = "Unkown";
}

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