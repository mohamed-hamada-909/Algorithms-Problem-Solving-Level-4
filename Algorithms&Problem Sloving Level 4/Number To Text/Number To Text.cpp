#include <iostream>
#include <string>
#include "NumberToText.h";

using namespace std;

int main()
{
    int num = ToText::ReadNumber();

    cout << ToText::NumberToText(num) << endl;

    return 0;
}
