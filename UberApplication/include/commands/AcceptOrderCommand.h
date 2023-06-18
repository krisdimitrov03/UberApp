#pragma once
#include "CommandBase.h"
#include "../helper/String.h"

class AcceptOrderCommand : public CommandBase
{
	String orderId;

public:
	AcceptOrderCommand() = default;
	AcceptOrderCommand(const String& _orderId);

	void execute() const override;
};

