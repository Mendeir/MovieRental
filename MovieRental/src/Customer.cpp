#include "Customer.h"
#include <string>

using namespace std;

//Constructor
Customer::Customer (string name, string address)
{
	++customerIdCounter;
	customerId = customerIdCounter;
	customerName = name;
	customerAddress = address;
}

int Customer::customerIdCounter = 0;
//~Customer::Customer () {}

//Methods

