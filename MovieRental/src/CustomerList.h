#ifndef _CUSTOMERLIST_H_
#define _CUSTOMERLIST_H_

#include "Customer.h"
#include <vector>
#include <string>

class CustomerList
{
	private:
		vector<Customer> customerCollection;

	public:
		void addCustomer (Customer givenCustomer);
		void showCustomerDetails ();
		void printCustomerList ();

		void showAllCustomer ();
};

#endif


