#include "../../include/commands/AcceptOrderCommand.h"
#include "../../include/services/OrderManager.h"

AcceptOrderCommand::AcceptOrderCommand(const String& _orderId)
	: orderId(_orderId)
{
}

void AcceptOrderCommand::execute() const
{
	OrderManager::getInstance()
		.acceptOrder(orderId);
}
