#include <stdio.h>

extern "C" int
asm_add(int a, int b, int c, int d);

int
main() {
    int a, b, c, d, result;

    a = 1; b = 4; c = 3; d = 2;
    result = asm_add(a, b, c, d);
    printf("Test 1: %d + %d + %d - %d = %d\n", a, b, c, d, result);

    a = 122; b = -13; c = -100; d = 509;
    result = asm_add(a, b, c, d);
    printf("Test 2: %d + (%d) + (%d) - %d = %d\n", a, b, c, d, result);

    return(0);
}
