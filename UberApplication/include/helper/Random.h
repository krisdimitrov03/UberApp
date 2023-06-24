//Copied from Stoycho Kyosev and refactored a little bit

#pragma once

class Random {
private:
	static Random instance;
	static size_t seed;

	Random();
public:
	Random(const Random&) = delete;
	Random& operator=(const Random&) = delete;

	void setSeed(size_t s);
	size_t getRand() const;

	static const Random& getInstance();

	~Random();
};