#include "../../include/commands/RateCommand.h"
#include "../../include/services/UserManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/ui/Messages.h"

RateCommand::RateCommand(const String& _driverName, double _rating)
	: driverName(_driverName), rating(_rating)
{
}

void RateCommand::execute() const
{
	try
	{
		UserManager::getInstance()
			.rateDriver(driverName, rating);

		UIManager::printSuccessMessage(success::DRIVER_RATE_SUCCESSFUL);
	}
	catch (const std::exception&)
	{
		UIManager::printErrorMessage(error::DRIVER_RATE_FAIL);
	}
}
