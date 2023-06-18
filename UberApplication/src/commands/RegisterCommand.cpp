#include "../../include/commands/RegisterCommand.h"
#include "../../include/services/UserManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/ui/Messages.h"
#include "../../include/helper/Console.h"

RegisterCommand::RegisterCommand(
	UserType _type,
	const String& _username,
	const String& _firstName,
	const String& _lastName,
	const String& _password,
	const String& _carNumber,
	const String& _phoneNumber)
	: type(_type),
	username(_username),
	firstName(_firstName),
	lastName(_lastName),
	password(_password),
	carNumber(_carNumber),
	phoneNumber(_phoneNumber)
{
}

void RegisterCommand::execute() const
{
	int result = UserManager::getInstance()
		.registerUser(
			type,
			username,
			firstName,
			lastName,
			password,
			carNumber,
			phoneNumber);

	switch (result) {
	case 0:
		UIManager::printSuccessMessage(success::REGISTERED);
		Console::writeLine("Press <Enter> to continue...");
		Console::readKey();
		break;
	case -1:
		UIManager::printErrorMessage(error::INVALID_USERNAME);
		Console::writeLine("Press <Enter> to continue...");
		Console::readKey();
		break;
	case -2:
		UIManager::printErrorMessage(error::INVALID_F_NAME);
		Console::writeLine("Press <Enter> to continue...");
		Console::readKey();
		break;
	case -3:
		UIManager::printErrorMessage(error::INVALID_L_NAME);
		Console::writeLine("Press <Enter> to continue...");
		Console::readKey();
		break;
	case -4:
		UIManager::printErrorMessage(error::INVALID_PASSWORD);
		Console::writeLine("Press <Enter> to continue...");
		Console::readKey();
		break;
	}
}