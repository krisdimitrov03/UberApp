#pragma once
#include "CommandBase.h"
#include "../helper/String.h"
#include "../helper/Point.h"

class ChangeAddressCommand : public CommandBase
{
	String name;
	Point coordinates;

public:
	ChangeAddressCommand() = default;
	ChangeAddressCommand(const String& _name, const Point& _coordinates);

	void execute() const override;
};

