#include "../../include/commands/CancelOrderCommand.h"
#include "../../include/services/OrderManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/ui/Messages.h"

CancelOrderCommand::CancelOrderCommand(const String& _orderId)
	: orderId(_orderId)
{
}

void CancelOrderCommand::execute() const
{
	try
	{
		OrderManager::getInstance()
			.cancelOrder(orderId);

		UIManager::printSuccessMessage(success::ORDER_CANCELED);
	}
	catch (const std::exception&)
	{
		UIManager::printErrorMessage(error::ORDER_CANCEL_FAIL);
	}
}
