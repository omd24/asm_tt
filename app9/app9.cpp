/* ===========================================================
   #File: app9.cpp #
   #Date: 07 Month 2021 #
   #Revision: 1.0 #
   #Creator: Omid Miresmaeili #
   #Description: 2D array, nested loop #
   #Notice: (C) Copyright 2021 by Omid. All Rights Reserved. #
   =========================================================== */

#include <stdio.h>

extern "C" void
calc_matrix_squares_ (int * y, int * x, int nrows, int ncols);

static void
calc_matrix_squares_cpp (int * y, int * x, int nrows, int ncols) {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            int kx = j * ncols + i;
            int ky = i * ncols + j;
            y[ky] = x[kx] * x[kx];
        }
    }
}
int main (void) {
    int const nrows = 6;
    int const ncols = 3;
    int y1[nrows][ncols];
    int y2[nrows][ncols];
    int x[nrows][ncols] = {
        {1, 2, 3,}, {4,5,6}, {7,8,9},
        {10,11,12}, {13,14,15}, {16,17,18}
    };

    calc_matrix_squares_cpp(&y1[0][0], &x[0][0], nrows, ncols);
    calc_matrix_squares_(&y2[0][0], &x[0][0], nrows, ncols);

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            printf(
                "y1[%2d][%2d] = %*d, y2[%2d][%2d] = %*d, x[%2d][%2d] = %*d\n",
                i, j, 6, y1[i][j], i, j, 6, y2[i][j], i, j, 6, x[i][j]
            );
        }
    }

    return(0);
}
