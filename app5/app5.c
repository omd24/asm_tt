/* ===========================================================
   #File: app5.c #
   #Date: 14 Feb 2021 #
   #Revision: 1.0 #
   #Creator: Omid Miresmaeili #
   #Description: Using mixed data types (8, 16, 32, 64 bits signed and unsigned) #
   #Notice: (C) Copyright 2021 by Omid. All Rights Reserved. #
   =========================================================== */

#include <stdint.h>
#include <stdio.h>

// -- calculates (a * b * c * d * e * f * g * h)
int mixed_int_mul_ (
    int8_t a, int16_t b, int32_t c, int64_t d,
    int8_t e, int16_t f, int32_t g, int64_t h,
    int64_t * out_prod
);
// -- calculates (a + b + c + d) / (e + f + g + h)
int mixed_int_div_ (
    uint8_t a, uint16_t b, uint32_t c, uint64_t d,
    uint8_t e, uint16_t f, uint32_t g, uint64_t h,
    uint64_t * out_quo, uint64_t * out_rem
);

int main () {
    {
        int8_t a = 2;
        int16_t b = -3;
        int32_t c = 8;
        int64_t d = 4;
        int8_t e = 3;
        int16_t f = -7;
        int32_t g = -5;
        int64_t h = 10;

        int64_t prod = 0;

        int res = mixed_int_mul_(a, b, c, d, e, f, g, h, &prod);
        if (0 != res) {
            printf("Return Code: %d (success)\n", res);
            printf("Product = %I64d \n", prod);
        } else {
            printf("Return Code: %d (error)\n", res);
        }
    }
    {
        uint8_t a = 12;
        uint16_t b = 17;
        uint32_t c = 71000000;
        uint64_t d = 90000000000;
        uint8_t e = 101;
        uint16_t f = 37;
        uint32_t g = 25;
        uint64_t h = 5;
        
        uint64_t quo = 0;
        uint64_t rem = 0;

        int res = mixed_int_div_(a, b, c, d, e, f, g, h, &quo, &rem);
        if (0 != res) {
            printf("Return Code: %d (success)\n", res);
            printf("Quotient = %I64u\n", quo);
            printf("Remainder = %I64u\n", rem);
        } else {
            printf("Return Code: %d (error)\n", res);
        }
    }
    return(0);
}

