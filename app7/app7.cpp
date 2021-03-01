/* ===========================================================
   #File: app7.cpp #
   #Date: 01 March 2021 #
   #Revision: 1.0 #
   #Creator: Omid Miresmaeili #
   #Description: Conditional mov and jumps #
   #Notice: (C) Copyright 2021 by Omid. All Rights Reserved. #
   =========================================================== */

#include <stdio.h>

extern "C" int signed_min_v1 (int a, int b, int c);
extern "C" int signed_max_v1 (int a, int b, int c);
extern "C" int signed_min_v2 (int a, int b, int c);
extern "C" int signed_max_v2 (int a, int b, int c);

static void
print_results (char const * fname, int a, int b, int c, int result) {
    int w = 5;
    printf("%s(%*d, %*d, %*d) = %*d\n",
           fname,
           w, a,
           w, b,
           w, c,
           w, result
    );
}
int
main (void) {
    int a, b, c;
    int smin1, smax1, smin2, smax2;

    // signed_min examples
    a = 2; b = 15; c = 8;
    smin1 = signed_min_v1(a, b, c);
    smin2 = signed_min_v2(a, b, c);
    print_results("signed_min_v1", a, b, c, smin1);
    print_results("signed_min_v2", a, b, c, smin2);
    printf("\n");

    a = -3; b = -22; c = 28;
    smin1 = signed_min_v1(a, b, c);
    smin2 = signed_min_v2(a, b, c);
    print_results("signed_min_v1", a, b, c, smin1);
    print_results("signed_min_v2", a, b, c, smin2);
    printf("\n");

    a = 17; b = 37; c = -11;
    smin1 = signed_min_v1(a, b, c);
    smin2 = signed_min_v2(a, b, c);
    print_results("signed_min_v1", a, b, c, smin1);
    print_results("signed_min_v2", a, b, c, smin2);
    printf("\n");

    // signed_max examples
    a = 10; b = 5; c = 3;
    smax1 = signed_max_v1(a, b, c);
    smax2 = signed_max_v2(a, b, c);
    print_results("signed_max_v1", a, b, c, smax1);
    print_results("signed_max_v2", a, b, c, smax2);
    printf("\n");

    a = -3; b = 28; c = 15;
    smax1 = signed_max_v1(a, b, c);
    smax2 = signed_max_v2(a, b, c);
    print_results("signed_max_v1", a, b, c, smax1);
    print_results("signed_max_v2", a, b, c, smax2);
    printf("\n");

    a = -25; b = -37; c = -17;
    smax1 = signed_max_v1(a, b, c);
    smax2 = signed_max_v2(a, b, c);
    print_results("signed_max_v1", a, b, c, smax1);
    print_results("signed_max_v2", a, b, c, smax2);
    printf("\n");
}

