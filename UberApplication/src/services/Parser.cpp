#include "../../include/services/Parser.h"

//This method is copied from https://www.geeksforgeeks.org/
String Parser::hex(size_t data)
{
    String answer;

    while (data != 0) {
        int rem = 0;

        char ch;
        rem = data % 16;

        if (rem < 10) {
            ch = rem + 48;
        }
        else {
            ch = rem + 87;
        }

        char current[2]{ ch, '\0' };
        answer += current;
        data /= 16;
    }

    int i = 0, j = answer.length() - 1;
    while (i <= j)
    {
        std::swap(answer[i], answer[j]);
        i++;
        j--;
    }
    return answer;
}
