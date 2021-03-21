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
		//Constructors and Destructor
		Customer ();
		Customer (int givenID, string givenName, string givenAddress);
		
		static int customerIdCounter;
		
		//Getters and Setters
		int getCustomerId ();
		string getCustomerName ();
		string getCustomerAddress ();
		void setCustomerId (int id);
		void setCustomerName (string name);
		void setCustomerAddress (string address);

};

#endif // !_CUSTOMER_H_


