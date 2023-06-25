#include "../../include/commands/PayCommand.h"
#include "../../include/services/OrderManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/helper/Console.h"
#include "../../include/services/CommandFactory.h"

PayCommand::PayCommand(const String& _orderId, double _amount)
	: orderId(_orderId), amount(_amount)
{
}

void PayCommand::execute() const
{
	try
	{
		OrderManager::getInstance()
			.pay(orderId, amount);

		Console::writeLine("Rate your driver:");
		Console::write(" Driver name -> ");
		String driverName;
		Console::read(driverName);
		Console::write(" Rating -> ");
		double rating = Console::read<double>();
		std::cin.ignore();

		CommandFactory::getInstance()
			.createRateCommand(driverName, rating)
			->execute();
	}
	catch (const std::exception& ex)
	{
		UIManager::printErrorMessage(ex.what());
	}
}
