//
// Created by maracuja on 23.03.2024.
//

#ifndef MOLR_MULTIDIMENSIONAL_H
#define MOLR_MULTIDIMENSIONAL_H

#pragma once
#include "numeric_vector.h"
#include "numeric_utils.h"
#include "common.h"

typedef F64(*function_1d)(const F64);
typedef F64(*function_nd)(const vector_f64&);

namespace multiDimensional {
    vector_f64 bisect(function_nd func, vector_f64& p_0, vector_f64& p_1, const I32 max_iters = MAX_ITERS, const F64 eps = ACCURACY);
    vector_f64 golden_ratio(function_nd func, vector_f64& p_0, vector_f64& p_1, const I32 max_iters = MAX_ITERS, const F64 eps = ACCURACY);
    vector_f64 fibonacci(function_nd func, vector_f64& p_0, vector_f64& p_1, const F64 eps = ACCURACY);
    vector_f64 per_coord_descend(function_nd func, vector_f64& p_prev, const I32 max_iters = MAX_ITERS, const F64 eps = ACCURACY);
}


vector_f64 multiDimensional::bisect(function_nd func, vector_f64& p_0, vector_f64& p_1, const I32 max_iters, const F64 eps) {

    vector_f64 p_l = p_0, p_r = p_1, p_c, dir;

    dir = vector_f64::direction(p_1, p_0) * eps;

    I32 cnt = 0;
    for (; cnt != max_iters; ++cnt) {

        if ((p_l - p_r).magnitude() < 2 * eps) break;

        p_c = (p_l + p_r) * 0.5;


        (func(p_l - dir) > func(p_r)) ? p_l = p_c : p_r = p_c;
    }
#if _DEBUG
    std::cout << "bisect::function arg range    : " << (p_r - p_l).magnitude() << "\n";
	std::cout << "bisect::function probes count : " << cnt * 2 << "\n";
#endif
    return p_c;
}

vector_f64 multiDimensional::golden_ratio(function_nd func, vector_f64& p_0, vector_f64& p_1, const I32 max_iters, const F64 eps) {
    vector_f64 a = p_0, b = p_1;
    vector_f64 p_l(a), p_r(b), p_c;
    F64 y_l, y_r;
    vector_f64 dx;

    dx = (b - a);
    p_l = b - dx * ONE_OVER_PHI;
    p_r = a + dx * ONE_OVER_PHI;

    y_l = func(p_l);
    y_r = func(p_r);

    I32 cnt = 0;

    while (cnt != max_iters) {
        if ((p_r - p_l).magnitude() < 2 * eps) break;

        if (y_l > y_r) {
            a = p_l;
            p_l = p_r;
            y_l = y_r;
            p_r = a + (b - a) * ONE_OVER_PHI;
            y_r = func(p_r);
        }
        else {
            b = p_r;
            p_r = p_l;
            y_r = y_l;
            p_l = b - (b - a) * ONE_OVER_PHI;
            y_l = func(p_l);
        }
        cnt++;
    }


#if _DEBUG
    std::cout << "golden_ratio::function arg range    : " << (p_r - p_l).magnitude() << "\n";
	std::cout << "golden_ratio::function probes count : " << cnt + 2 << "\n";
#endif
    return (p_r + p_l) * 0.5;
}

vector_f64 multiDimensional::fibonacci(function_nd func, vector_f64& p_0, vector_f64& p_1, const F64 eps) {

    vector_f64 a = p_0, b = p_1;

    vector_f64 p_l = a, p_r = b, dx;
    F64 y_l, y_r;

    F64 f_n = 0, f_n_1 = 1, f_tmp;

    while (f_n < (b - a) / eps) {
        f_tmp = f_n;
        f_n = f_n_1;
        f_n_1 += f_tmp;
    }

    dx = b - a;
    p_l = a + dx * ((double)(f_n_1 - f_n) / f_n_1);
    p_r = a + dx * ((double)f_n / f_n_1);

    y_l = func(p_l);
    y_r = func(p_r);

    f_tmp = f_n_1 - f_n;
    f_n_1 = f_n;
    f_n = f_tmp;

    I32 cnt = 0;

    while (f_n_1 != f_n) {
        if ((p_r - p_l).magnitude() < 2 * eps) break;

        if (y_l >= y_r) {
            a = p_l;
            p_l = p_r;
            y_l = y_r;
            p_r = a + (b - a) * ((double)f_n / f_n_1);
            y_r = func(p_r);
        }
        else {
            b = p_r;
            p_r = p_l;
            y_r = y_l;
            p_l = a + (b - a) * ((double)(f_n_1 - f_n) / f_n_1);
            y_l = func(p_l);
        }
        cnt++;
    }

#if _DEBUG
    std::cout << "fibonacci::function arg range    : " << (p_r - p_l).magnitude() << "\n";
	std::cout << "fibonacci::function probes count : " << cnt + 2 << "\n";
#endif
    return (p_l + p_r) * 0.5;
}

vector_f64 multiDimensional::per_coord_descend(function_nd func, vector_f64& p_prev, const I32 max_iters, const F64 eps) {
    vector_f64 ort(p_prev.size());
    vector_f64 p_cur;
    vector_f64 p;

    F64 lam = 1.0;

    I32 cnt = 0;
    for (; cnt < max_iters; cnt++)
    {
        int ort_idx = cnt % p_prev.size();
        ort[ort_idx] = 1;
        p_cur = p_prev + lam * ort;
        p = multiDimensional::bisect(func, p_cur, p_prev);
        ort[ort_idx] = 0;

        if ((p - p_prev).magnitude() < 2 * eps) {
            break;
        }
        p_prev = p;
    }

    return p_prev;
}


#endif //MOLR_MULTIDIMENSIONAL_H
