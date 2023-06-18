#pragma once
#include "CommandBase.h"

class LogoutCommand : public CommandBase
{
public:
	LogoutCommand() = default;

	void execute() const override;
};