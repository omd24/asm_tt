#include <stdio.h>
#include <stdint.h>

int int_shift_(uint32_t a, uint32_t count, uint32_t * a_shr, uint32_t * a_shl);

int main () {

    uint32_t a = 3119;
    uint32_t count = 6;
    uint32_t ashr;
    uint32_t ashl;
    int res = int_shift_(a, count, &ashr, &ashl);

    if (res)
        printf("Return Code = %d, Shift Left = %d, Shift Right = %d\n", res, ashl, ashr);
    else
        printf("Return Code = %d (error)\n", res);

    return (0);
}


