////
//// Created by maracuja on 23.03.2024.
////
//
//#ifndef MOLR_ONEDIMENSIONAL_H
//#define MOLR_ONEDIMENSIONAL_H
//
//#include "common.h"
//#include "numeric_utils.h"
//
//typedef double (*function_1d)(const double);
//
//namespace oneDimensional {
//    double bisect(function_1d func, double x_0, double x_1, const int max_iters = MAX_ITERS, const double eps = ACCURACY);
//
//    double golden_ratio(function_1d func, double x_0, double x_1, const int max_iters = MAX_ITERS, const double eps = ACCURACY);
//
//    double fibonacci(function_1d, double x_0, double x_1, const double eps = ACCURACY);
//}
//#endif //MOLR_ONEDIMENSIONAL_H
//
//
//double oneDimensional::bisect(function_1d func, double x_0, double x_1, const int max_iters, const double eps)
//{
//    double x_c = 0.0;
//
//    if (x_0 > x_1) std::swap(x_0, x_1);
//
//    int cnt = 0;
//    while (cnt != max_iters) {
//
//        if (std::abs(x_1 - x_0) < 2 * eps) break;
//        cnt++;
//
//        x_c = (x_0 + x_1) * 0.5;
//        if (func(x_c - eps) < func(x_c + eps)){
//            x_1 = x_c;
//        }else{
//            x_0 = x_c;
//        }
//    }
//#if _DEBUG
//    std::cout << "\nIterations number : " << cnt << "\n";
//    std::cout << "Answer: ";
//#endif
//    return (x_0 + x_1) * 0.5;
//}
//
//double oneDimensional::golden_ratio(function_1d func, double x_0, double x_1, const int max_iters, const double eps)
//{
//    double a = x_0, b = x_1;
//
//    if (a > b) std::swap(a, b);
//
//    double x_l, x_r, y_l, y_r, dx = 0.0;
//
//    dx = b-a;
//    x_l = b - dx * ONE_OVER_PHI;
//    x_r = a + dx * ONE_OVER_PHI;
//
//    y_l = func(x_l);
//    y_r = func(x_r);
//
//    int cnt = 0;
//    while (cnt != max_iters) {
//        if (std::abs(x_r - x_l) < 2 * eps) break;
//
//        if(y_l >= y_r){
//            a = x_l;
//            x_l = x_r;
//            y_l = y_r;
//            x_r = a + (b -a) * ONE_OVER_PHI;
//            y_r = func(x_r);
//        }else{
//            b = x_r;
//            x_r = x_l;
//            y_r = y_l;
//            x_l = b - (b - a) * ONE_OVER_PHI;
//            y_l = func(x_l);
//        }
//        cnt++;
//    }
//#if _DEBUG
//    std::cout << "\nIterations number : " << cnt << "\n";
//    std::cout << "Answer: ";
//#endif
//    return (x_r + x_l) * 0.5;
//}
//
//double oneDimensional::fibonacci(function_1d func, double x_0, double x_1, const double eps)
//{
//    double a = x_0, b = x_1;
//    if (a > b) std::swap(a, b);
//
//    double x_l = a, x_r = b, dx = 0.0;
//
//    int f_n, f_n_1, f_tmp;
//
//    closest_fibonacci_pair((b - a) / eps, f_n, f_n_1);
//
//    int cnt = 0;
//    while (f_n != f_n_1) {
//        cnt++;
//
//        dx = b - a;
//        f_tmp = f_n_1 - f_n;
//
//        x_l = a + dx * ((double)f_tmp / f_n_1);
//        x_r = a + dx * ((double)f_n / f_n_1);
//
//        f_n_1 = f_n;
//        f_n = f_tmp;
//
//        (func(x_l) < func(x_r)) ? b = x_r : a = x_l;
//    }
//#if _DEBUG
//    std::cout << "\nIterations number : " << cnt << "\n";
//    std::cout << "Answer: ";
//#endif
//    return (x_l + x_r) * 0.5;
//}

#pragma once
#include "common.h"

typedef double (*function_1d)(const double);

namespace oneDimensional {
    double bisect(function_1d func, double x_0, double x_1, const int max_iters = MAX_ITERS, const double eps = ACCURACY);

    double golden_ratio(function_1d func, double x_0, double x_1, const int max_iters = MAX_ITERS, const double eps = ACCURACY);

    double fibonacci(function_1d, double x_0, double x_1, const double eps = ACCURACY);
}

double oneDimensional::bisect(function_1d func, double x_0, double x_1, const int max_iters, const double eps)
{
    double x_c = 0.0;

    if (x_0 > x_1) std::swap(x_0, x_1);

    int cnt = 0;
    while (cnt != max_iters) {

        if (abs(x_1 - x_0) < 2 * eps) break;
        cnt++;

        x_c = (x_0 + x_1) * 0.5;
        if (func(x_c - eps) < func(x_c + eps)) {
            x_1 = x_c;
        }
        else {
            x_0 = x_c;
        }
    }
#if _DEBUG
    std::cout << "bisect::function arg range    : " << (x_1 - x_0) << "\n";
    std::cout << "bisect::function probes count : " << cnt * 2 << "\n";
#endif
    return (x_0 + x_1) * 0.5;
}

double oneDimensional::golden_ratio(function_1d func, double x_0, double x_1, const int max_iters, const double eps)
{
    double a = x_0, b = x_1;

    if (a > b) std::swap(a, b);

    double x_l, x_r, y_l, y_r, dx = 0.0;

    dx = b - a;
    x_l = b - dx * ONE_OVER_PHI;
    x_r = a + dx * ONE_OVER_PHI;

    y_l = func(x_l);
    y_r = func(x_r);

    int cnt = 0;
    while (cnt != max_iters) {
        if (abs(x_r - x_l) < 2 * eps) break;

        if (y_l > y_r) {
            a = x_l;
            x_l = x_r;
            y_l = y_r;
            x_r = a + (b - a) * ONE_OVER_PHI;
            y_r = func(x_r);
        }
        else {
            b = x_r;
            x_r = x_l;
            y_r = y_l;
            x_l = b - (b - a) * ONE_OVER_PHI;
            y_l = func(x_l);
        }
        cnt++;
    }
#if _DEBUG
    std::cout << "golden_ratio::function arg range    : " << (x_r - x_l) << "\n";
    std::cout << "golden_ratio::function probes count : " << cnt + 2 << "\n";
#endif
    return (x_r + x_l) * 0.5;
}

double oneDimensional::fibonacci(function_1d func, double x_0, double x_1, const double eps)
{

    double a = x_0, b = x_1;

    if (a > b) std::swap(a, b);

    double x_l = a, x_r = b, dx = 0.0, y_l, y_r;

    int f_n = 1, f_n_1 = 1, f_tmp;
    int iterations = 0;
    double value = (b - a) / eps;
    while (f_n_1 < value) {
        iterations++;
        f_tmp = f_n;
        f_n = f_n_1;
        f_n_1 += f_tmp;
    }

    dx = b - a;
    x_l = a + dx * ((double)(f_n_1 - f_n) / f_n_1);
    x_r = a + dx * ((double)f_n / f_n_1);

    y_l = func(x_l);
    y_r = func(x_r);

    f_tmp = f_n_1 - f_n;
    f_n_1 = f_n;
    f_n = f_tmp;

    int cnt = 0;
    while (f_n_1 != f_n) {
    //for (int index = iterations; index > 0; index--){
        if (std::abs(x_r - x_l) < 2 * eps) break;

        if (y_l > y_r) {
            a = x_l;
            x_l = x_r;
            y_l = y_r;
            x_r = a + (b - a) * ((double)f_n / f_n_1);
            y_r = func(x_r);
        }
        else {
            b = x_r;
            x_r = x_l;
            y_r = y_l;
            x_l = a + (b - a) * ((double)(f_n_1 - f_n) / f_n_1);
            y_l = func(x_l);
        }

        f_tmp = f_n_1 - f_n;
        f_n_1 = f_n;
        f_n = f_tmp;

        cnt++;
    }

#if _DEBUG
    std::cout << "fibonacci::function arg range    : " << (x_r - x_l) << "\n";
    std::cout << "fibonacci::function probes count : " << cnt + 2 << "\n";
#endif
    return (x_l + x_r) * 0.5;
}

//
//double oneDimensional::fibonacci(function_1d function, double left, double right, const double eps)
//{
//    if (left > right) std::swap(left, right);
//    F64 x_l, x_r, f_l, f_r, value, fib_t{ 0.0 }, fib_1{ 1.0 }, fib_2{ 1.0 };
//    I32 iterations{ 0 };
//    value = (right - left) / eps;
//    while (fib_2 < value)
//    {
//        iterations++;
//        fib_t = fib_1;
//        fib_1 = fib_2;
//        fib_2 += fib_t;
//    }
//    x_l = left + (right - left) * ((fib_2 - fib_1) / fib_2);
//    x_r = left + (right - left) * (fib_1 / fib_2);
//
//    f_l = function(x_l);
//    f_r = function(x_r);
//
//    fib_t = fib_2 - fib_1;
//    fib_2 = fib_1;
//    fib_1 = fib_t;
//
//    for (I32 index = iterations; index > 0; index--)
//    {
//        if (f_l > f_r)
//        {
//            left = x_l;
//            f_l = f_r;
//            x_l = x_r;
//            x_r = left + (right - left) * (fib_1 / fib_2);
//            f_r = function(x_r);
//        }
//        else
//        {
//            right = x_r;
//            x_r = x_l;
//            f_r = f_l;
//            x_l = left + (right - left) * ((fib_2 - fib_1) / fib_2);
//            f_l = function(x_l);
//        }
//        fib_t = fib_2 - fib_1;
//        fib_2 = fib_1;
//        fib_1 = fib_t;
//#if _DEBUG
//        std::cout << "\nfibonacchi [a, b] range: " << (right - left) << "\n";
//#endif
//    }
//#if _DEBUG
//    std::cout << "fibonacci::function arg range    : " << right - left << "\n";
//    std::cout << "fibonacci::function probes count : " << iterations + 2 << "\n";
//#endif
//    return (right + left) * 0.5;
//}