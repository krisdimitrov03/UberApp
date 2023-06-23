#include "../../include/app/UberApp.h"
#include "../../include/services/UserManager.h"
#include "../../include/services/OrderManager.h"
#include "../../include/helper/Console.h"
#include "../../include/services/UIManager.h"
#include "../../include/services/MenuManager.h"
#include <fstream>
#include "../../include/ui/Messages.h"

void UberApp::readFromFile()
{
	std::ifstream file(globals::DB_FILE_NAME, std::ios::in | std::ios::binary);

	if (!file.is_open()) {
		UIManager::printErrorMessage(error::FILE_NOT_OPENNING);
		return;
	}

	UIManager::getInstance().getTheme().readFromBinaryFile(file);

	UserManager::getInstance().readFromBinaryFile(file);
	OrderManager::getInstance().readFromBinaryFile(file);

	file.close();
}

void UberApp::saveToFile() const
{
	std::ofstream file(globals::DB_FILE_NAME, std::ios::out | std::ios::binary);

	if (!file.is_open()) {
		UIManager::printErrorMessage(error::FILE_NOT_OPENNING);
		return;
	}

	UIManager::getInstance()
		.getTheme()
		.writeToBinaryFile(file);

	UserManager::getInstance()
		.writeToBinaryFile(file);

	OrderManager::getInstance()
		.finishAll();

	OrderManager::getInstance()
		.writeToBinaryFile(file);

	file.close();
}

void UberApp::run()
{
	readFromFile();

	while (1) {
		Console::clear();
		UIManager::printLogo();
		String name = UserManager::getInstance().getCurrentUserName();

		UIManager::printLandingPage(
			UserManager::getInstance().getCurrentUserType(),
			UserManager::getInstance().getCurrentUserName(),
			UserManager::getInstance().getCurrentUserIsInOrder()
		);

		char input = Console::read<char>();
		std::cin.ignore();

		if (input < '0' || input > '9') {
			UIManager::printErrorMessage(error::INVALID_OPTION_NUMBER);
			continue;
		}

		int option = input - '0';
		bool exit = false;

		switch (UserManager::getInstance().getCurrentUserType()) {
		case UserType::Guest:
			MenuManager::runGuestMenu(option, exit);
			break;
		case UserType::Client:
			MenuManager::runClientMenu(option, exit,
				UserManager::getInstance()
				.getCurrentUserIsInOrder());
			break;
		case UserType::Driver:
			MenuManager::runDriverMenu(option, exit,
				UserManager::getInstance()
				.getCurrentUserIsInOrder());
			break;
		}

		if (exit) {
			Console::clear();
			UIManager::printExitMessage();
			saveToFile();
			return;
		}
	}
}
