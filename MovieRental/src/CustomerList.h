#ifndef _CUSTOMERLIST_H_
#define _CUSTOMERLIST_H_

#include "Customer.h"
#include <vector>
#include <string>

using namespace std;

class CustomerList 
{
	private:
		vector<Customer> customerCollection;
	public:
		void addCustomer (Customer givenCustomer);
		void showCustomerDetails ();
		void printCustomerList ();
}

#endif _CUSTOMERLIST_H_
