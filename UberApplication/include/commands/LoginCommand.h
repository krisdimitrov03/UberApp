#pragma once
#include "CommandBase.h"
#include "../helper/String.h"

class LoginCommand : public CommandBase
{
	String username;
	String password;

public:
	LoginCommand(const String&, const String&);
	void execute() const override;
};