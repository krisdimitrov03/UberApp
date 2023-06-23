#include "../../include/commands/CheckMessagesCommand.h"
#include "../../include/services/UserManager.h"
#include "../../include/services/OrderManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/helper/Console.h"
#include "../../include/services/Parser.h"

void CheckMessagesCommand::execute() const
{
	const List<OrderMessageDto>& messages = UserManager::getInstance()
		.getMessages();

	Console::writeLine(
		"You have " + 
		Parser::intToString(messages.length()) + 
		" new message(s):");

	for (size_t i = 0; i < messages.length(); i++)
		UIManager::printOrderMessage(messages[i], i + 1);

	//to be refactored
	Console::writeLine("Press <Enter> to continue...");
	Console::readKey();
}