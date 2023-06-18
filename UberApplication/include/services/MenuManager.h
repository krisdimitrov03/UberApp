#pragma once

class MenuManager
{
private:
	static void runOrderedClientMenu(int option, bool& exit);
	static void runNotOrderedClientMenu(int option, bool& exit);

	static void runDriverInOrderMenu(int option, bool& exit);
	static void runDriverNotInOrderMenu(int option, bool& exit);

public:
	static void runGuestMenu(int option, bool& exit);

	static void runClientMenu(int option, bool& exit, bool isOrdered);

	static void runDriverMenu(int option, bool& exit, bool inOrder);
};

