#include "../../include/commands/AcceptOrderCommand.h"
#include "../../include/services/OrderManager.h"

AcceptOrderCommand::AcceptOrderCommand(const String& _orderId, unsigned _minutes)
	: orderId(_orderId), minutes(_minutes)
{
}

void AcceptOrderCommand::execute() const
{
	OrderManager::getInstance()
		.acceptOrder(orderId, minutes);
}
