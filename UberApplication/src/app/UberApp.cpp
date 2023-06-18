#include "../../include/app/UberApp.h"
#include "../../include/services/UserManager.h"
#include "../../include/services/OrderManager.h"
#include <fstream>

void UberApp::readFromFile()
{
	std::ifstream file(globals::DB_FILE_NAME, std::ios::in | std::ios::binary);

	/*if (!file.is_open()) {
		UIManager::printErrorMessage(error::FILE_NOT_OPENNING);
		return;
	}

	UIManager::getInstance().getTheme().readFromBinaryFile(file);*/

	UserManager::getInstance().readFromBinaryFile(file);
	OrderManager::getInstance().readFromBinaryFile(file);

	file.close();
}

void UberApp::saveToFile() const
{
	std::ofstream file(globals::DB_FILE_NAME, std::ios::out | std::ios::binary);

	/*if (!file.is_open()) {
		UIManager::printErrorMessage(error::FILE_NOT_OPENNING);
		return;
	}

	UIManager::getInstance()
		.getTheme()
		.writeToBinaryFile(file);*/

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
}
