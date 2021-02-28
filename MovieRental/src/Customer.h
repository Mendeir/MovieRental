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
		static int customerIdCounter;
		Customer (string name, string address);
		//~Customer ();
		

};

#endif // !_CUSTOMER_H_


