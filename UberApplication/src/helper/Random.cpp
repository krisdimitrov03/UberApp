#include "../../include/helper/Random.h"
#include <fstream>

namespace {
	const char FILENAME[] = "random.dat";
}

size_t Random::seed = 0;
Random Random::instance;

size_t Random::getRand() const {
	seed = (1103515245 * seed + 12345) % (1ull << 31);
	return seed;
}

Random::Random()
{
	std::ifstream file(FILENAME, std::ios::in | std::ios::binary);

	if (file.is_open())
		file.read((char*)&seed, sizeof(size_t));

	file.close();
}

void Random::setSeed(size_t s) { seed = s; }

const Random& Random::getInstance() {
	return instance;
}

Random::~Random()
{
	std::ofstream file(FILENAME, std::ios::in | std::ios::binary);

	if (file.is_open())
		file.write((const char*)&seed, sizeof(size_t));

	file.close();
}
