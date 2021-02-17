#pragma once
class UserInterface
{
	public:
		void start ();
		void displayMenuCommands();
		int getUserCommand ();
		void proccessUserCommand (int givenCommand);

};

