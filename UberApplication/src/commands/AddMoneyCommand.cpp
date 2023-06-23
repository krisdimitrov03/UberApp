#include "../../include/commands/AddMoneyCommand.h"
#include "../../include/services/UserManager.h"
#include "../../include/ui/Messages.h"
#include "../../include/services/UIManager.h"

AddMoneyCommand::AddMoneyCommand(double _amount)
{
	amount = _amount;
}

void AddMoneyCommand::execute() const
{
	try
	{
		UserManager::getInstance()
			.addMoney(amount);

		UIManager::printSuccessMessage(success::DEPOSIT_SUCCESSFUL);
	}
	catch (const std::invalid_argument& err)
	{
		UIManager::printErrorMessage(err.what());
	}
}