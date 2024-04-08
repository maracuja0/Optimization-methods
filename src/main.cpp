#include <iostream>
#include <iomanip>

#include "OneDimensional.h"
#include "MultiDimensional.h"

void calcPHI() {
    double fi = ((1 + pow(5, 0.5)) / 2);

    std::cout << "PHI: " << std::setprecision(20) << fi << ", ONE_OVER_PHI: " << 1 / fi << '\n';
}

void LR1(function_1d f) {
    std::cout << "\n---------------\n";
    std::cout << "------LR1------\n";
    std::cout << "---------------\n\n";
    std::cout << "One dimensional search:\n\n";

    double x_0 = -5, x_1 = 125;
    std::cout << "y = (x - 5) * x\n" << "x_0 = " << x_0 << ", x_1 = " << x_1 << "\n\n";

    std::cout << "Bisect: " << oneDimensional::bisect(f, x_0, x_1) << "\n\n";
    std::cout << "Golden ratio: " << oneDimensional::golden_ratio(f, x_0, x_1) << "\n\n";
    std::cout << "Fibonacci: " << oneDimensional::fibonacci(f, x_0, x_1) << "\n\n";
}

void LR2(function_nd f) {
    std::cout << "\n---------------\n";
    std::cout << "------LR2------\n";
    std::cout << "---------------\n\n";
    std::cout << "Multi dimensional search:\n\n";

    vector_f64 x_0 = { 0,0 };
    vector_f64 x_1 = { 5,3 };

    std::cout << "x_0: " << x_0 << ", x_1: " << x_1 << "\n";

    std::cout << "Bisect: " << multiDimensional::bisect(f, x_0, x_1) << "\n\n";
    std::cout << "Golden ration: " << multiDimensional::golden_ratio(f, x_0, x_1) << "\n\n";
    std::cout << "Fibonacci:" << multiDimensional::fibonacci(f, x_0, x_1) << "\n\n";

    vector_f64 start_x0 = { 0, 0 };
    std::cout << "Per coord descend: " << multiDimensional::per_coord_descend(f, start_x0) << "\n";
}

double f_1(const double x) {

    return (x - 5) * x;

}


F64 f_n(const vector_f64& args) {

    return(args[0] - 5) * args[0] + (args[1] - 3) * args[1];
}

int main()
{
    //calcPHI();

    LR1(f_1);

    LR2(f_n);

    return 0;
}
