#pragma once
#include "../../helper/String.h"
#include "../../helper/Point.h"

struct OrderMessageDto
{
	String orderId;

	String clientName;

	String start;
	Point startCoordinates;

	String destination;
	Point destCoordinates;
};