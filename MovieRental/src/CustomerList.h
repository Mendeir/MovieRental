#ifndef _CUSTOMERLIST_H_
#define _CUSTOMERLIST_H_

#include "Customer.h"
#include <vector>
#include <string>

class CustomerList
{
	private:
		//Variables
		vector<Customer> customerCollection;

	public:
		//Methods
		void addCustomer (Customer givenCustomer);
		void showCustomerDetails (int givenId);
		void printCustomerList ();

		void showAllCustomer ();
};

#endif


