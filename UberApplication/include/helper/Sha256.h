#pragma once
#include "String.h"

class Sha256
{
public:
	static String createHash(const String& message);
};