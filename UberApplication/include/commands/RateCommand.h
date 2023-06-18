#pragma once
#include "CommandBase.h"
#include "../helper/String.h"

class RateCommand : public CommandBase
{
	String driverName;
	double rating;
public:
	RateCommand() = default;
	RateCommand(const String& _driverName, double _rating);

	void execute() const override;
};

