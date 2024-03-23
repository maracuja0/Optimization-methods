#include <iostream>
#include <cmath>
#include "../include/OneDimensional.h"
#include <iomanip>

double f(const double x);

void calcPHI(){
    double fi =((1 + pow(5, 0.5)) / 2);

    std::cout << "PHI: " << std::setprecision(20)<<  fi << " ONE_OVER_PHI: " << 1 / fi << '\n';
}
void LR1(){
    std::cout << "\n---------------\n";
    std::cout << "------LR1------\n";
    std::cout << "---------------\n\n";

    int x_0 = 10, x_1 = 1;
    std::cout << "Function: (x-5)*x\n";
    std::cout << "x_0: " << x_0 << ", x_1: " << x_1 << "\n";

    std::cout << "Bisect: " << oneDimensional::bisect(f, x_0, x_1) << "\n";
    std::cout << "Golden ration: " << oneDimensional::golden_ratio(f, x_0, x_1) << "\n";
    std::cout << "Fibonacci:" << oneDimensional::fibonacci(f, x_0, x_1) << "\n";
}

void LR2(){

}

int main()
{
    calcPHI();

    LR1();


    return 0;
}

double f(const double x) {
    return (x - 5) * x;
}

