#pragma once
#include "../../helper/String.h"

struct CheckOrderDto
{
	String orderId;
	String driverName;
	String carNumber;
	unsigned minutes;
};