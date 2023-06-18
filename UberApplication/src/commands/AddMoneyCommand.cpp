#include "../../include/commands/AddMoneyCommand.h"
#include "../../include/services/UserManager.h"

AddMoneyCommand::AddMoneyCommand(double _amount)
{
	amount = _amount;
}

void AddMoneyCommand::execute() const
{
	UserManager::getInstance()
		.addMoney(amount);
}