#include "../../include/Services/UIManager.h"
#include "../../include/Services/MenuManager.h"
#include "../../include/Services/CommandFactory.h"
#include "../../include/Helper/Console.h"
#include "../../include/UI/Messages.h"
#include "../../include/Services/Validator.h"
#include "../../include/Models/Address.h"
#include "../../include/Services/OrderManager.h"
#include "../../include/Commands/OrderCommand.h"

void MenuManager::runOrderedClientMenu(int option, bool& exit)
{
	switch (option) {
	case 1: {
		CommandFactory::getInstance()
			.createCheckOrderCommand()
			->execute();
		break;
	}
	case 2: {
		String orderId;
		Console::read(orderId);

		CommandFactory::getInstance()
			.createCancelOrderCommand(orderId)
			->execute();
		break;
	}
	case 3: {
		String orderId;
		Console::read(orderId);
		double amount = Console::read<double>();

		CommandFactory::getInstance()
			.createPayCommand(orderId, amount)
			->execute();
		break;
	}
	case 4: {
		String driverName;
		Console::read(driverName);
		double rating = Console::read<double>();

		CommandFactory::getInstance()
			.createRateCommand(driverName, rating)
			->execute();
		break;
	}
	case 5: {
		double amount = Console::read<double>();

		CommandFactory::getInstance()
			.createAddMoneyCommand(amount)
			->execute();
		break;
	}
	case 6: {
		CommandFactory::getInstance()
			.createLogoutCommand()
			->execute();
		break;
	}
	case 7:
		exit = true;
		return;
	}
}

void MenuManager::runNotOrderedClientMenu(int option, bool& exit)
{
	switch (option) {
	case 1: {
		Console::clear();
		UIManager::printOrderPage();
		String startName, destName, startAddInfo, destAddInfo;
		int sX = 0, sY = 0, dX = 0, dY = 0;

		Console::read(startName);
		Console::write(" -> ");
		sX = Console::read<int>();
		sY = Console::read<int>();
		std::cin.ignore();
		Console::write("Additional info? (Y/N):");
		char res = Console::read<char>();
		std::cin.ignore();
		switch (res) {
		case 'Y':
		case 'y':
			Console::write("Add info -> ");
			Console::read(startAddInfo);
			break;
		}

		Console::write(" -> ");
		Console::read(destName);
		Console::write(" -> ");
		dX = Console::read<int>();
		dY = Console::read<int>();
		std::cin.ignore();
		Console::write("Additional info? (Y/N):");
		res = Console::read<char>();
		std::cin.ignore();
		switch (res) {
		case 'Y':
		case 'y':
			Console::write("Add info -> ");
			Console::read(startAddInfo);
			break;
		}

		Console::write(" -> ");
		int passengersCount = Console::read<int>();
		std::cin.ignore();

		if (!Validator::validatePassengersCount(passengersCount)) {
			UIManager::printErrorMessage(error::INVALID_PASSENGERS_COUNT);
			return;
		}

		CommandFactory::getInstance()
			.createOrderCommand(
				startName,
				startAddInfo,
				destName,
				destAddInfo,
				{ sX, sY },
				{ dX, dY },
				passengersCount)
			->execute();
		break;
	}
	case 2: {
		Console::clear();
		UIManager::printAddMoneyPage();

		double amount = Console::read<double>();
		std::cin.ignore();

		CommandFactory::getInstance()
			.createAddMoneyCommand(amount)
			->execute();
		break;
	}
	case 3:
		CommandFactory::getInstance()
			.createLogoutCommand()
			->execute();
		break;
	case 4:
		exit = true;
		return;
	default:
		UIManager::printErrorMessage(error::INVALID_OPTION_NUMBER);
		break;
	}
}

void MenuManager::runDriverInOrderMenu(int option, bool& exit)
{
	switch (option) {
	case 6:
		exit = true;
		return;
	}
}

void MenuManager::runDriverNotInOrderMenu(int option, bool& exit)
{
	switch (option) {
	case 2:
		CommandFactory::getInstance()
			.createCheckMessagesCommand()
			->execute();
		break;
	case 6:
		exit = true;
		return;
	}
}

void MenuManager::runGuestMenu(int option, bool& exit)
{
	switch (option) {
	case 1: {
		Console::clear();
		UIManager::printLoginPage();

		String username, password;
		Console::read(username);
		Console::write(" -> ");
		Console::read(password);

		CommandFactory::getInstance()
			.createLoginCommand(username, password)
			->execute();
		break;
	}
	case 2: {
		Console::clear();
		UIManager::printTypePartial();
		int option = Console::read<int>();
		std::cin.ignore();
		Console::clear();

		UserType type = (UserType)option;
		UIManager::printRegisterPage(type);

		String username;
		String firstName;
		String lastName;
		String password;
		String carNumber;
		String phoneNumber;

		Console::read(username);
		Console::write(" -> ");
		Console::read(firstName);
		Console::write(" -> ");
		Console::read(lastName);
		Console::write(" -> ");
		Console::read(password);

		if (type == UserType::Driver) {
			Console::write(" -> ");
			Console::read(carNumber);
			Console::write(" -> ");
			Console::read(phoneNumber);
		}

		CommandFactory::getInstance()
			.createRegisterCommand(
				type,
				username,
				firstName,
				lastName,
				password,
				carNumber,
				phoneNumber)
			->execute();
		break;
	}
	case 3:
		UIManager::getInstance()
			.changeTheme();
		break;
	case 4:
		exit = true;
		return;
		break;
	default:
		UIManager::printErrorMessage(error::INVALID_OPTION_NUMBER);
		break;
	}
}

void MenuManager::runClientMenu(int option, bool& exit, bool isInOrder)
{
	isInOrder
		? runOrderedClientMenu(option, exit)
		: runNotOrderedClientMenu(option, exit);
}

void MenuManager::runDriverMenu(int option, bool& exit, bool isInOrder)
{
	isInOrder
		? runDriverInOrderMenu(option, exit)
		: runDriverNotInOrderMenu(option, exit);
}
