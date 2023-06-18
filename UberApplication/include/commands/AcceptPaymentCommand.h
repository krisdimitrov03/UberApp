#pragma once
#include "CommandBase.h"
#include "../helper/String.h"

class AcceptPaymentCommand : public CommandBase
{
	String orderId;

public:
	AcceptPaymentCommand() = default;
	AcceptPaymentCommand(const String& _orderId);

	void execute() const override;
};