#include "String.h"



int main()
{
    system("chcp 1251 > 0");

    String str1 = "Вадя";

    std::cout << str1 + " + Вика" << "\n";

    String str2 = " + Вика";

    std::cout << str1 + str2 << "\n";

    std::cout << str1 << "\n";

    std::cout << str2 << "\n";

}