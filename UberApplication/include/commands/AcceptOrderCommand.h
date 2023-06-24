#pragma once
#include "CommandBase.h"
#include "../helper/String.h"

class AcceptOrderCommand : public CommandBase
{
	String orderId;
	unsigned minutes;

public:
	AcceptOrderCommand() = default;
	AcceptOrderCommand(const String& _orderId, unsigned _minutes);

	void execute() const override;
};

