/* ===========================================================
   #File: app10.cpp #
   #Date: 11 March 2021 #
   #Revision: 1.0 #
   #Creator: Omid Miresmaeili #
   #Description: Structure sample #
   #Notice: (C) Copyright 2021 by Omid. All Rights Reserved. #
   =========================================================== */

#include <stdio.h>
#include <stdint.h>

struct TestStruct;

extern "C" int64_t
calc_struct_sum_ (TestStruct * ts);

static int64_t
calc_struct_sum_cpp (TestStruct * ts);

struct TestStruct {
    int8_t Val8;
    //int8_t Pad8;
    int16_t Val16;
    int32_t Val32;
    int64_t Val64;
};
int main (void) {
    TestStruct ts;
    ts.Val8 = -100;
    ts.Val16 = 2000;
    ts.Val32 = -300000;
    ts.Val64 = 40000000000;
    int64_t sum1 = calc_struct_sum_cpp(&ts);
    int64_t sum2 = calc_struct_sum_(&ts);

    printf("ts.Val8 = %d\n", (int)ts.Val8);
    printf("ts.Val16 = %d\n", ts.Val16);
    printf("ts.Val32 = %d\n", ts.Val32);
    printf("ts.Val64 = %lld\n\n", ts.Val64);

    printf("sum1 = %lld\n", sum1);
    printf("sum2 = %lld\n", sum2);
    return(0);
}
static int64_t
calc_struct_sum_cpp (TestStruct * ts) {
    return (ts->Val8 + ts->Val16 + ts->Val32 + ts->Val64);
}

