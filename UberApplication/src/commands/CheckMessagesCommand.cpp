#include "../../include/commands/CheckMessagesCommand.h"
#include "../../include/services/UserManager.h"
#include "../../include/services/OrderManager.h"

void CheckMessagesCommand::execute() const
{
	const List<OrderMessageDto>& messages = UserManager::getInstance()
		.getMessages();

	//print messages
}