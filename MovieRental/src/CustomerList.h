#ifndef _CUSTOMERLIST_H_
#define _CUSTOMERLIST_H_

#include "Customer.h"
#include <vector>
#include <string>

class CustomerList
{
	private:
		//Variables for customerList to be stored from the user
		vector<Customer> customerCollection;

	public:
		//Methods
		void addCustomer (Customer givenCustomer);
		bool showCustomerDetails (int givenId);

		//File Handling
		void writeCustomerToFile ();
		void readCustomerToFile ();
};

#endif


