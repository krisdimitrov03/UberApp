#pragma once
#include "CommandBase.h"

class CheckOrderCommand : public CommandBase
{
public:
	CheckOrderCommand() = default;

	void execute() const override;
};