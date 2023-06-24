#pragma once
#include "../helper/String.h"
#include "../commands/CommandBase.h"
#include "../models/identity/UserType.h"
#include "../helper/Point.h"

class CommandFactory
{
	static CommandFactory instance;

	CommandFactory() = default;
public:
	CommandFactory(const CommandFactory&) = delete;
	CommandFactory& operator=(const CommandFactory&) = delete;

	CommandBase* createLoginCommand(const String& username, const String& password) const;

	CommandBase* createRegisterCommand(
		UserType type,
		const String& username,
		const String& firstName,
		const String& lastName,
		const String& password,
		const String& carNumber,
		const String& phoneNumber) const;

	CommandBase* createLogoutCommand() const;

	CommandBase* createOrderCommand(
		const String& _startName,
		const String& _startAddInfo,
		const String& _destName,
		const String& _destAddInfo,
		const Point& _start,
		const Point& _dest,
		int _passengersCount) const;

	CommandBase* createCheckOrderCommand() const;

	CommandBase* createCheckMessagesCommand() const;

	CommandBase* createAddMoneyCommand(double amount) const;

	CommandBase* createCancelOrderCommand(const String& orderId) const;

	CommandBase* createPayCommand(const String& orderId, double amount);

	CommandBase* createRateCommand(const String& driverName, double rating);

	CommandBase* createChangeAddressCommand(const String& name, const Point& coordinates);

	CommandBase* createAcceptOrderCommand(const String& orderId, unsigned minutes);

	CommandBase* createDeclineOrderCommand(const String& orderId);

	CommandBase* createFinishOrderCommand(const String& orderId);

	CommandBase* createAcceptPaymentCommand(const String& orderId);

	static CommandFactory& getInstance();
};

