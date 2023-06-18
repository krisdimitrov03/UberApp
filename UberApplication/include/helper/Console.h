#pragma once
#include "../App/Theme.h"
#include "../Helper/String.h"

class Console
{
public:
	static void read(String& dest);

	template <typename Number>
	static Number read();

	static void readLine(const String& dest);

	static void readKey();

	static void write(const String& data);
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