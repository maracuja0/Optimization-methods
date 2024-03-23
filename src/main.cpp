#include <iostream>
#include <cmath>
#include "../include/OneDimensional.h"
#include <iomanip>

double f(const double x);

void calcPHI(){
    double fi =((1 + pow(5, 0.5)) / 2);

    std::cout << "PHI: " << std::setprecision(20)<<  fi << ", ONE_OVER_PHI: " << 1 / fi << '\n';
}

void LR1(){
    std::cout << "\n---------------\n";
    std::cout << "------LR1------\n";
    std::cout << "---------------\n\n";
    std::cout << "One dimensional search:\n\n";

    double x_0 = -2, x_1 = 10;
    std::cout << "y = (x - 5) * x\n" << "x_0 = " << x_0 << ", x_1 = " << x_1 << "\n\n";

    std::cout << "Bisect: " << oneDimensional::bisect(f, x_0, x_1) << "\n\n";
    std::cout << "Golden ratio: " << oneDimensional::golden_ratio(f, x_0, x_1) << "\n\n";
    std::cout << "Fibonacci: " << oneDimensional::fibonacci(f, x_0, x_1) << "\n\n";
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

