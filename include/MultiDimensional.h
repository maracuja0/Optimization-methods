//
// Created by maracuja on 23.03.2024.
//

#ifndef MOLR_MULTIDIMENSIONAL_H
#define MOLR_MULTIDIMENSIONAL_H

#pragma once
#include "numeric_vector.h"
#include "numeric_utils.h"
#include "common.h"

typedef F64(*function_nd)(const vector_f64&);

namespace multiDimensional {
    vector_f64 bisect(function_nd function, vector_f64 &left, vector_f64 &right, const I32 max_iterations = MAX_ITERS, const F64 eps = ACCURACY);
    vector_f64 golden_ratio(function_nd function, vector_f64 &left, vector_f64 &right, const I32 max_iterations = MAX_ITERS, const F64 eps = ACCURACY);
    vector_f64 fibonacci(function_nd function, vector_f64 &left, vector_f64 &right, const F64 eps = ACCURACY);
    vector_f64 per_coord_descend(function_nd function, vector_f64 &x_start, const I32 max_iterations = MAX_ITERS, const F64 eps = ACCURACY);
}


vector_f64 multiDimensional::bisect(function_nd function, vector_f64 &left, vector_f64 &right, const I32 max_iterations, const F64 eps) {

    vector_f64 x_c, dir, lhs(left), rhs(right);
    dir = vector_f64::direction(lhs, rhs) * eps;
    I32 iteration = 0;
    for (; iteration != max_iterations; iteration++)
    {
        if ((lhs - rhs).magnitude() < 2 * eps) break;
        x_c = (lhs + rhs) * 0.5;
        if (function(x_c - dir) > function(x_c + dir))
            lhs = x_c;
        else
            rhs = x_c;
    }
#if _DEBUG
    std::cout << "bisect::function arg range    : " << (rhs - lhs).magnitude() << "\n";
    std::cout << "bisect::function probes count : " << iteration * 2 << "\n";
#endif
    return (lhs + rhs) * 0.5;
}

vector_f64 multiDimensional::golden_ratio(function_nd function, vector_f64 &left, vector_f64 &right, const I32 max_iterations, const F64 eps) {
    vector_f64 lhs(left), rhs(right);
    vector_f64 x_l, x_r;
    F64 f_l, f_r;
    I32 iteration = 0;
    x_l = rhs - (rhs - lhs) * ONE_OVER_PHI;
    x_r = lhs + (rhs - lhs) * ONE_OVER_PHI;
    f_l = function(x_l);
    f_r = function(x_r);
    for (; iteration != max_iterations; iteration++)
    {
        if ((rhs - lhs).magnitude() < 2 * eps) break;
        if (f_l > f_r)
        {
            lhs = x_l;
            x_l = x_r;
            f_l = f_r;
            x_r = lhs + (rhs - lhs) * ONE_OVER_PHI;
            f_r = function(x_r);
        }
        else
        {
            rhs = x_r;
            x_r = x_l;
            f_r = f_l;
            x_l = rhs - (rhs - lhs) * ONE_OVER_PHI;
            f_l = function(x_l);
        }
    }
#if _DEBUG
    std::cout << "golden_ratio::function arg range    : " << (rhs - lhs).magnitude() << "\n";
    std::cout << "golden_ratio::function probes count : " << iteration + 2 << "\n";
#endif
    return (right + left) * 0.5;
}

vector_f64 multiDimensional::fibonacci(function_nd function, vector_f64 &left, vector_f64 &right, const F64 eps) {
    vector_f64 x_l, x_r;
    vector_f64 lhs(left), rhs(right);
    F64 f_l, f_r, value, fib_t{ 0.0 }, fib_1{ 1.0 }, fib_2{ 1.0 };
    I32 iterations{ 0 };
    value = (right - left).magnitude() / eps;
    while (fib_2 < value)
    {
        iterations++;
        fib_t = fib_1;
        fib_1 = fib_2;
        fib_2 += fib_t;
    }
    x_l = lhs + (rhs - lhs) * ((fib_2 - fib_1) / fib_2);
    x_r = lhs + (rhs - lhs) * (fib_1 / fib_2);

    f_l = function(x_l);
    f_r = function(x_r);

    fib_t = fib_2 - fib_1;
    fib_2 = fib_1;
    fib_1 = fib_t;

    for (I32 index = iterations; index > 0; index--)
    {
        if (f_l > f_r)
        {
            lhs = x_l;
            f_l = f_r;
            x_l = x_r;
            x_r = lhs + (rhs - lhs) * (fib_1 / fib_2);
            f_r = function(x_r);
        }
        else
        {
            rhs = x_r;
            x_r = x_l;
            f_r = f_l;
            x_l = lhs + (rhs - lhs) * ((fib_2 - fib_1) / fib_2);
            f_l = function(x_l);
        }
        fib_t = fib_2 - fib_1;
        fib_2 = fib_1;
        fib_1 = fib_t;
        // #if _DEBUG
        // 	   std::cout << "\nfibonacchi [a, b] range: " << (right - left) << "\n";
        // #endif
    }
#if _DEBUG
    std::cout << "fibonacci::function arg range    : " << (rhs - lhs).magnitude() << "\n";
    std::cout << "fibonacci::function probes count : " << iterations + 2 << "\n";
#endif
    return (rhs + lhs) * 0.5;
}

vector_f64 multiDimensional::per_coord_descend(function_nd function, vector_f64 &x_start, const I32 max_iterations, const F64 eps) {
    vector_f64 ort(x_start.size());
    vector_f64 p_cur;
    vector_f64 p;

    F64 lam = 1.0;

    I32 cnt = 0;
    for (; cnt < max_iterations; cnt++)
    {
        int ort_idx = cnt % x_start.size();
        ort[ort_idx] = lam;
        p_cur = x_start + ort;
        std::cout << "x_start: " << x_start << ", p_cur: " << p_cur <<"\n";
        p = multiDimensional::fibonacci(function,p_cur, x_start);
        ort[ort_idx] = 0;

        if ((p - x_start).magnitude() < 2 * eps) {
            break;
        }
        x_start = p;
    }

    return p;
}

#endif //MOLR_MULTIDIMENSIONAL_H
