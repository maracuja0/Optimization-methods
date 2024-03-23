//
// Created by maracuja on 23.03.2024.
//

#ifndef MOLR_ONEDIMENSIONAL_H
#define MOLR_ONEDIMENSIONAL_H

#include "config.h"

typedef double (*function_1d)(const double);

namespace oneDimensional {
    double bisect(function_1d func, double x_0, double x_1, const int max_iters = MAX_ITERS, const double eps = ACCURACY);

    double golden_ratio(function_1d func, double x_0, double x_1, const int max_iters = MAX_ITERS, const double eps = ACCURACY);

    double fibonacci(function_1d, double x_0, double x_1, const double eps = ACCURACY);
}
#endif //MOLR_ONEDIMENSIONAL_H
