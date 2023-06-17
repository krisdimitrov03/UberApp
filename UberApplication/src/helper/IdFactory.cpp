#include "../../include/helper/IdFactory.h"
#include "../../include/helper/Random.h"
#include "../../include/services/Parser.h"

IdFactory IdFactory::instance;

IdFactory& IdFactory::getInstance()
{
	return instance;
}

String IdFactory::create() const
{
	String result;

	size_t left = Random::getInstance()
		.getRand();
	size_t mid = Random::getInstance()
		.getRand();
	size_t right = Random::getInstance()
		.getRand();

	result += Parser::hex(left);
	result += Parser::hex(mid);
	result += Parser::hex(right);

	return result;
}
