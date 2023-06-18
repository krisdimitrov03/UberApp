#pragma once
#include "CommandBase.h"
#include "../helper/String.h"

class PayCommand : public CommandBase
{
	String orderId;
	double amount = 0;
public:
	PayCommand() = default;
	PayCommand(const String& _orderId, double _amount);

	void execute() const override;
};

