#include "../../include/commands/RateCommand.h"
#include "../../include/services/UserManager.h"

RateCommand::RateCommand(const String& _driverName, double _rating)
	: driverName(_driverName), rating(_rating)
{
}

void RateCommand::execute() const
{
	UserManager::getInstance()
		.rateDriver(driverName, rating);
}
