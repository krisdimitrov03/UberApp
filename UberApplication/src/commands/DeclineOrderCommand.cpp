#include "../../include/commands/DeclineOrderCommand.h"
#include "../../include/services/OrderManager.h"

DeclineOrderCommand::DeclineOrderCommand(const String& _orderId)
	: orderId(_orderId)
{
}

void DeclineOrderCommand::execute() const
{
	OrderManager::getInstance()
		.declineOrder(orderId);
}