#pragma once
class UserInterface
{
	public:
		//Methods
		void clear ();
		void start ();
		void mainMenu ();

		//Input Methods
		int getUserCommand ();

		//Main Menu Methods
		void newVideo ();
		void rentVideo ();
		void returnVideo ();
		void showVideoDetails ();
		void displayAllVideos ();
		void checkVideoAvailability ();
		void customerMaintenance ();
		void customerMaintenanceSubMenu ();

		//Processing Methods
		void processCommandMainMenu (int givenCommand);
		void processCustomerMaintenance (int givenCommand);

};

