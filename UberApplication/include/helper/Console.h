#pragma once
#include "../App/Theme.h"
#include "../Helper/String.h"

class Console
{
public:
	static void read(String& dest);

	template <typename Number>
	static Number read();

	static void readKey();

	static void write(const String& data);

	template <typename T>
	static void write(const T& data);

	static void writeLine(const String& data = "");

	static void clear();

	static void changeColors(const Theme& theme);
};

template <typename Number>
Number Console::read() {
	Number result;
	std::cin >> result;

	return result;
}

template<typename T>
inline void Console::write(const T& data)
{
	std::cout << data;
}
