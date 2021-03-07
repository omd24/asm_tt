/* ===========================================================
   #File: app8.cpp #
   #Date: 07 March 2021 #
   #Revision: 1.0 #
   #Creator: Omid Miresmaeili #
   #Description: 1D array #
   #Notice: (C) Copyright 2021 by Omid. All Rights Reserved. #
   =========================================================== */

#include <stdio.h>

extern "C" long long calc_array_vals_(long long * y, int * x, int a, short b, int n);

static long long
calc_array_vals_cpp(long long * y, int * x, int a, short b, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        y[i] = (long long)x[i] * a + b;
        sum += y[i];
    }
    return sum;
}
int main (void) {
    int a = -6;
    short b = -13;
    int x [] = {26, 12, -53,19,14,21,31,-4,12,-9,41,7};
    int const n = sizeof(x) / sizeof(x[0]);

    long long y1[n];
    long long y2[n];

    long long sum1 = calc_array_vals_(y1, x, a, b, n);
    long long sum2 = calc_array_vals_(y2, x, a, b, n);

    printf("a = %d, b = %d, n = %d,\n", a, b, n);
    for (unsigned i = 0; i < n; i++) {
        printf("i: %*u, x: %*d, y1: %6lld, y2: %6lld\n", 2, i, 6, x[i], y1[i], y2[i]);
    }
    printf("\nSum of y1 = %lld\nSum of y2 = %lld\n", sum1, sum2);
    return(0);
}

