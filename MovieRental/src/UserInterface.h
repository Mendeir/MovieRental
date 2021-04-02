#pragma once
#include "MovieList.h"
#include "CustomerList.h"
#include "Customer.h"
#include "MovieRental.h"

class UserInterface
{
	private:
		MovieRental movieRental;

	public:
		//Methods
		void clear();
		void start();
		void mainMenu();

		//Input Methods
		int getUserCommand();

		//Main Menu Methods
		void customerMaintenance();
		void customerMaintenanceSubMenu();

		//Processing Methods
		void processCommandMainMenu(int givenCommand);
		void processCustomerMaintenance(int givenCommand);

};

