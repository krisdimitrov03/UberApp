#include "../../include/commands/CancelOrderCommand.h"
#include "../../include/services/OrderManager.h"

CancelOrderCommand::CancelOrderCommand(const String& _orderId)
	: orderId(_orderId)
{
}

void CancelOrderCommand::execute() const
{
	OrderManager::getInstance()
		.cancelOrder(orderId);
}
