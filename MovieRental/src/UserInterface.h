#pragma once
class UserInterface
{
	public:
		void start ();
		void displayMainMenuCommands ();
		int getUserCommand ();
		void processCommandMainMenu (int givenCommand);

};

