#include "../../include/commands/FinishOrderCommand.h"
#include "../../include/services/OrderManager.h"

FinishOrderCommand::FinishOrderCommand(const String& _orderId)
	: orderId(_orderId)
{
}

void FinishOrderCommand::execute() const
{
	OrderManager::getInstance()
		.finishOrder(orderId);
}