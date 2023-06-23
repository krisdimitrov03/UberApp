#include "../../include/commands/CheckOrderCommand.h"
#include "../../include/services/UserManager.h"
#include "../../include/services/OrderManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/helper/Console.h"

void CheckOrderCommand::execute() const
{
	const String& userId = UserManager::getInstance()
		.getCurrentUserId();

	CheckOrderDto details = OrderManager::getInstance()
		.getInstance()
		.checkOrder();

	UIManager::printOrderDetailsPage(details);
	Console::writeLine("Press <Enter> to continue...");
	Console::readKey();
}
