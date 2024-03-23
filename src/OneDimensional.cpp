//
// Created by maracuja on 23.03.2024.
//


#include "../include/OneDimensional.h"
#include <cmath>
#include <algorithm>
#include <iostream>

namespace oneDimensional{
    double bisect(function_1d func, double x_0, double x_1, const int max_iters, const double eps)
    {
        double x_l = x_0, x_r = x_1, x_c = 0.0;

        if (x_l > x_r) std::swap(x_l, x_r);

        int cnt = 0;
        while (cnt != max_iters) {

            if (std::abs(x_r - x_l) < eps) break;
            cnt++;

            x_c = (x_l + x_r) * 0.5;
            (func(x_c - eps) > func(x_c + eps)) ? x_l = x_c : x_r = x_c;
        }
#if DEBUG
        std::cout << "\ndihotomia iterations number : " << cnt << "\n";
#endif
        return x_c;
    }

    double golden_ratio(function_1d func, double x_0, double x_1, const int max_iters, const double eps)
    {
        double a = x_0, b = x_1;

        if (a > b) std::swap(a, b);

        double x_l = a, x_r = b, dx = 0.0;

        int cnt = 0;
        while (cnt != max_iters) {
            if (x_r - x_l < eps) break;
            cnt++;

            dx = b - a;
            x_l = b - dx * ONE_OVER_PHI;
            x_r = a + dx * ONE_OVER_PHI;

            (func(x_l) >= func(x_r)) ? a = x_l : b = x_r;
        }
#if DEBUG
        std::cout << "\ngolden ratio iterations number : " << cnt << "\n";
#endif
        return (x_r + x_l) * 0.5;
    }

    void closest_fibonacci_pair(const double value, int& fib_n, int& fib_n_1) {
        fib_n = 0;
        fib_n_1 = 0;
        if (value < 1) return;

        fib_n_1 = 1;
        if (value < 2) return;

        int f_tmp;
        while (fib_n < value) {
            f_tmp = fib_n;
            fib_n = fib_n_1;
            fib_n_1 += f_tmp;
        }
    }

    double fibonacci(function_1d func, double x_0, double x_1, const double eps)
    {
        double a = x_0, b = x_1;
        if (a > b) std::swap(a, b);

        double x_l = a, x_r = b, dx = 0.0;

        int f_n, f_n_1, f_tmp;

        closest_fibonacci_pair((b - a) / eps, f_n, f_n_1);

        int cnt = 0;
        while (f_n != f_n_1) {
            cnt++;

            dx = b - a;
            f_tmp = f_n_1 - f_n;

            x_l = a + dx * ((double)f_tmp / f_n_1);
            x_r = a + dx * ((double)f_n / f_n_1);

            f_n_1 = f_n;
            f_n = f_tmp;

            (func(x_l) < func(x_r)) ? b = x_r : a = x_l;
        }
#if DEBUG
        std::cout << "\nfibonacchi iterations number : " << cnt << "\n";
#endif
        return (x_l + x_r) * 0.5;
    }
}