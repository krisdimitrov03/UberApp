#include "../../include/commands/LoginCommand.h"
#include "../../include/services/UserManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/ui/Messages.h"
#include "../../include/helper/Console.h"

LoginCommand::LoginCommand(const String& _username, const String& _password)
	: username(_username), password(_password)
{
}

void LoginCommand::execute() const
{
	bool result = UserManager::getInstance()
		.loginUser(username, password);

	if (!result) {
		UIManager::printErrorMessage(error::INVALID_LOGIN);
		Console::writeLine("Press <Enter> to continue...");
		Console::readKey();
	}
}