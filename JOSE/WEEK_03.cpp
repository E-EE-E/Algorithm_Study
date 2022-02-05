#include <iostream>
#include <random>
#include <stdio.h>
using namespace std;
int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 3);

    switch (distribution(gen))
    {
    case 0:
        std::cout << "봉준";
        break;
    case 1:
        std::cout << "지민";
        break;
    case 2:
        std::cout << "호세";
        break;
    case 3:
        std::cout << "준영";
        break;
    };

    return 0;
}
