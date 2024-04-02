//
// Created by maracuja on 02.04.2024.
//

#include "OneDimensional.h"
#include <iostream>
double test_f1d_2(const double x) {

    return x*(x-10);

}
int main(){
    std::cout << "\nBisect: " << oneDimensional::bisect(test_f1d_2, -11, 10) << '\n';
    std::cout << "Golden ratio: " << oneDimensional::golden_ratio(test_f1d_2, -11, 10) << "\n";
    std::cout << "Fibonacci: " << oneDimensional::fibonacci(test_f1d_2, -11, 10) << "\n";
    return 0;
}