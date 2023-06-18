#pragma once
#include "CommandBase.h"
#include "../helper/String.h"

class FinishOrderCommand : public CommandBase
{
	String orderId;

public:
	FinishOrderCommand() = default;
	FinishOrderCommand(const String& _orderId);

	void execute() const override;
};