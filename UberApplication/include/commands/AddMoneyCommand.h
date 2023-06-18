#pragma once
#include "CommandBase.h"

class AddMoneyCommand : public CommandBase
{
	double amount;
public:
	AddMoneyCommand(double _amount);

	void execute() const override;
};
