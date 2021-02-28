/* ===========================================================
   #File: app6.c #
   #Date: 28 Feb 2021 #
   #Revision: 1.0 #
   #Creator: Omid Miresmaeili #
   #Description: Memory addressing modes #
   #Notice: (C) Copyright 2021 by Omid. All Rights Reserved. #
   =========================================================== */

#include <stdio.h>

extern "C" int nvals_, vals_sum_;
extern "C" int memory_addressing_(int i, int * v1, int * v2, int * v3, int * v4);

int main (void) {
    vals_sum_ = 0;
    for (int i = -1; i < nvals_ + 1; i++) {
        int v1 = -1, v2 = -1, v3 = -1, v4 = -1;
        int rc = memory_addressing_(i, &v1, &v2, &v3, &v4);
        int w = 5;
        printf(
            "i = %*d, rc = %*d, v1 = %*d, v2 = %*d, v3 = %*d, v4 = %*d\n",
            w, i,
            w, rc,
            w, v1,
            w, v2,
            w, v3,
            w, v4
        );
    }
    printf("vals_sum_ = %d\n", vals_sum_);
    return(0);
}
