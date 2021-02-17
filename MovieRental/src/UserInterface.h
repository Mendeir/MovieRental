#pragma once
class UserInterface
{
	public:
		void clear ();
		void start ();
		void mainMenu ();
		int getUserCommand ();
		void processCommandMainMenu (int givenCommand);
};

