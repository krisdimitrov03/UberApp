#include "../../include/commands/FinishOrderCommand.h"
#include "../../include/services/OrderManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/ui/Messages.h"

FinishOrderCommand::FinishOrderCommand(const String& _orderId)
	: orderId(_orderId)
{
}

void FinishOrderCommand::execute() const
{
	try
	{
		OrderManager::getInstance()
			.finishOrder(orderId);

		UIManager::printSuccessMessage(success::ORDER_FINISHED);
	}
	catch (const std::exception&)
	{
		UIManager::printErrorMessage(error::ORDER_FINISH_FAIL);
	}
}