#pragma once
#include "CommandBase.h"
#include "../helper/String.h"

class DeclineOrderCommand : public CommandBase
{
	String orderId;

public:
	DeclineOrderCommand() = default;
	DeclineOrderCommand(const String& _orderId);

	void execute() const override;
};