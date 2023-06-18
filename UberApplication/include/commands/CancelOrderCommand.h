#pragma once
#include "CommandBase.h"
#include "../../include/helper/String.h"

class CancelOrderCommand : public CommandBase
{
	String orderId;
public:
	CancelOrderCommand() = default;
	CancelOrderCommand(const String& _orderId);

	void execute() const override;
};

