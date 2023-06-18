#include "../../include/commands/PayCommand.h"
#include "../../include/services/OrderManager.h"

PayCommand::PayCommand(const String& _orderId, double _amount)
	: orderId(_orderId), amount(_amount)
{
}

void PayCommand::execute() const
{
	OrderManager::getInstance()
		.pay(orderId, amount);
}
