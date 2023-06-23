#include "../../include/commands/OrderCommand.h"
#include "../../include/models/Address.h"
#include "../../include/ui/Messages.h"
#include "../../include/services/OrderManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/helper/Console.h"

OrderCommand::OrderCommand(const String& _startName, const String& _startAddInfo, const String& _destName, const String& _destAddInfo, const Point& _start, const Point& _dest, int _passengersCount)
	: startName(_startName),
	startAddInfo(_startAddInfo),
	destName(_destName),
	destAddInfo(_destAddInfo),
	start(_start),
	dest(_dest),
	passengersCount(_passengersCount)
{
}

void OrderCommand::execute() const
{
	Address startAddress(startName, start, startAddInfo);
	Address destAddress(destName, dest, destAddInfo);

	try
	{
		OrderManager::getInstance()
			.makeOrder(startAddress, destAddress, passengersCount);

		UIManager::getInstance()
			.printSuccessMessage(success::ORDER_SUCCESSFUL);
	}
	catch (const std::runtime_error& err)
	{
		UIManager::getInstance()
			.printErrorMessage(err.what());
	}
}