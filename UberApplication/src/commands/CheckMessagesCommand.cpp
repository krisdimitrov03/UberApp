#include "../../include/commands/CheckMessagesCommand.h"
#include "../../include/services/UserManager.h"
#include "../../include/ui/Messages.h"
#include "../../include/services/OrderManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/services/CommandFactory.h"
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
	Console::writeLine();

	Console::write("Choose message number or 0 to go back: ");
	int option = Console::read<int>();
	std::cin.ignore();

	if (option < 0 || option > messages.length()) {
		UIManager::printErrorMessage(error::INVALID_OPTION_NUMBER);
		return;
	}

	if (option == 0)
		return;

	Console::write("Accept or Decline? (A/D): ");
	char symbol = Console::read<char>();
	std::cin.ignore();

	switch (symbol) {
	case 'A':
	case 'a': {

		Console::write("Minutes to reach the address -> ");
		unsigned minutes = Console::read<unsigned>();
		CommandFactory::getInstance()
			.createAcceptOrderCommand(messages[option - 1].orderId, minutes)
			->execute();
		break;
	}
	case 'D':
	case 'd':
		CommandFactory::getInstance()
			.createDeclineOrderCommand(messages[option - 1].orderId)
			->execute();
		break;
	default:
		break;
	}
}