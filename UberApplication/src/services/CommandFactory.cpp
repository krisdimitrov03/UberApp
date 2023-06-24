#include "../../include/services/CommandFactory.h"
#include "../../include/commands/LoginCommand.h"
#include "../../include/commands/RegisterCommand.h"
#include "../../include/commands/LogoutCommand.h"
#include "../../include/commands/OrderCommand.h"
#include "../../include/commands/CheckOrderCommand.h"
#include "../../include/commands/CheckMessagesCommand.h"
#include "../../include/commands/AddMoneyCommand.h"
#include "../../include/commands/CancelOrderCommand.h"
#include "../../include/commands/PayCommand.h"
#include "../../include/commands/RateCommand.h"
#include "../../include/commands/ChangeAddressCommand.h"
#include "../../include/commands/AcceptOrderCommand.h"
#include "../../include/commands/DeclineOrderCommand.h"
#include "../../include/commands/FinishOrderCommand.h"
#include "../../include/commands/AcceptPaymentCommand.h"

CommandFactory CommandFactory::instance;

CommandBase* CommandFactory::createLoginCommand(const String& username, const String& password) const
{
	return new LoginCommand(username, password);
}

CommandBase* CommandFactory::createRegisterCommand(UserType type, const String& username, const String& firstName, const String& lastName, const String& password, const String& carNumber, const String& phoneNumber) const
{
	return new RegisterCommand(type, username, firstName, lastName, password, carNumber, phoneNumber);
}

CommandBase* CommandFactory::createLogoutCommand() const
{
	return new LogoutCommand();
}

CommandBase* CommandFactory::createOrderCommand(const String& _startName, const String& _startAddInfo, const String& _destName, const String& _destAddInfo, const Point& _start, const Point& _dest, int _passengersCount) const
{
	return new OrderCommand(_startName, _startAddInfo, _destName, _destAddInfo, _start, _dest, _passengersCount);
}

CommandBase* CommandFactory::createCheckOrderCommand() const
{
	return new CheckOrderCommand();
}

CommandBase* CommandFactory::createCheckMessagesCommand() const
{
	return new CheckMessagesCommand();
}

CommandBase* CommandFactory::createAddMoneyCommand(double amount) const
{
	return new AddMoneyCommand(amount);
}

CommandBase* CommandFactory::createCancelOrderCommand(const String& orderId) const
{
	return new CancelOrderCommand(orderId);
}

CommandBase* CommandFactory::createPayCommand(const String& orderId, double amount)
{
	return new PayCommand(orderId, amount);
}

CommandBase* CommandFactory::createRateCommand(const String& driverName, double rating)
{
	return new RateCommand(driverName, rating);
}

CommandBase* CommandFactory::createChangeAddressCommand(const String& name, const Point& coordinates)
{
	return new ChangeAddressCommand(name, coordinates);
}

CommandBase* CommandFactory::createAcceptOrderCommand(const String& orderId, unsigned minutes)
{
	return new AcceptOrderCommand(orderId, minutes);
}

CommandBase* CommandFactory::createDeclineOrderCommand(const String& orderId)
{
	return new DeclineOrderCommand(orderId);
}

CommandBase* CommandFactory::createFinishOrderCommand(const String& orderId)
{
	return new FinishOrderCommand(orderId);
}

CommandBase* CommandFactory::createAcceptPaymentCommand(const String& orderId)
{
	return new AcceptPaymentCommand(orderId);
}

CommandFactory& CommandFactory::getInstance()
{
	return instance;
}
