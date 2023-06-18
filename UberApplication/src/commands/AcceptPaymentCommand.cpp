#include "../../include/commands/AcceptPaymentCommand.h"
#include "../../include/services/OrderManager.h"

AcceptPaymentCommand::AcceptPaymentCommand(const String& _orderId)
	: orderId(_orderId)
{
}

void AcceptPaymentCommand::execute() const
{
	OrderManager::getInstance()
		.acceptPayment(orderId);
}