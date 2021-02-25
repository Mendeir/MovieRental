#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <string>

using namespace std;

class Customer
{
	private:
		int customerId;
		string customerName;
		string customerAddress;

	public:
		Customer ();
		~Customer ();
		void addCustomer ();
		void showCustomerDetails ();
		void printCustomerList ();

};

#endif // !_CUSTOMER_H_


