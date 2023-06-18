#include "../../include/helper/Console.h"
#include <iostream>

void Console::read(String& dest)
{
    std::cin >> dest;
}

void Console::readLine(const String& dest)
{

}

void Console::readKey()
{
    std::cin.get();
}

void Console::write(const String& data)
{
    std::cout << data;
}

void Console::writeLine(const String& data)
{
    std::cout << data << std::endl;
}

void Console::clear()
{
    system("cls");
}

void Console::changeColors(const Theme& theme)
{
    String command("color ");
    command += theme.getBColor();
    command += theme.getFColor();
    system(command.c_str());
}
