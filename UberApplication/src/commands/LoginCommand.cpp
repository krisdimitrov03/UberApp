#include "../../include/commands/LoginCommand.h"
#include "../../include/services/UserManager.h"

LoginCommand::LoginCommand(const String& _username, const String& _password)
	: username(_username), password(_password)
{
}

void LoginCommand::execute() const
{
	UserManager::getInstance()
		.loginUser(username, password);
}