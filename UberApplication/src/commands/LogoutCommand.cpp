#include "../../include/commands/LogoutCommand.h"
#include "../../include/services/UserManager.h"

void LogoutCommand::execute() const
{
	UserManager::getInstance()
		.logoutUser();
}