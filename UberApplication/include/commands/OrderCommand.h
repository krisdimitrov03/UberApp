#pragma once
#include "CommandBase.h"
#include "../helper/String.h"
#include "../helper/Point.h"

class OrderCommand : public CommandBase
{
	String startName;
	String startAddInfo;

	String destName;
	String destAddInfo;

	Point start;
	Point dest;

	int passengersCount;

public:
	OrderCommand(
		const String& _startName,
		const String& _startAddInfo,
		const String& _destName,
		const String& _destAddInfo,
		const Point& _start,
		const Point& _dest,
		int _passengersCount);

	void execute() const override;
};