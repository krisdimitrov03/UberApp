#include "../../include/commands/AcceptPaymentCommand.h"
#include "../../include/services/OrderManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/ui/Messages.h"

AcceptPaymentCommand::AcceptPaymentCommand(const String& _orderId)
	: orderId(_orderId)
{
}

void AcceptPaymentCommand::execute() const
{
	try
	{
		OrderManager::getInstance()
			.acceptPayment(orderId);

		UIManager::printSuccessMessage(success::PAYMENT_ACCEPTED);
	}
	catch (const std::exception& ex)
	{
		UIManager::printErrorMessage(error::PAYMENT_NOT_ACCEPTED);
	}
}