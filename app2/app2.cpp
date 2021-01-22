#include <stdio.h>

extern "C" unsigned int integer_logical_ (
    unsigned int a, unsigned int b, unsigned int c, unsigned int d
);
extern "C" unsigned int g_Val1 = 0;
static unsigned int
integer_logical_cpp (unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
// Calculate (((a & b) | c ) ^ d) + g_Val1
    unsigned int t1 = a & b;
    unsigned int t2 = t1 | c;
    unsigned int t3 = t2 ^ d;
    unsigned int result = t3 + g_Val1;
    return result;
}
static void
display_result (
    char const * s, unsigned int a, unsigned int b, unsigned int c,
    unsigned int d, unsigned val1, unsigned int r1, unsigned int r2
) {
    printf("%s\n", s);
    printf("a=0x%x\n", a);
    printf("b=0x%x\n", b);
    printf("c=0x%x\n", c);
    printf("d=0x%x\n", d);
    printf("val1=0x%x\n", val1);
    printf("r1=0x%x (%u)\n", r1, r1);
    printf("r2=0x%x (%u)\n", r2, r2);
    printf("\n");
    if (r1 != r2)
        printf("Compare failed!\n");
}
int
main() {
    unsigned int a, b, c, d, r1, r2 = 0;
    a = 0x00223344;
    b = 0x00775544;
    c = 0x00555555;
    d = 0x00998877;
    g_Val1 = 7;
    r1 = integer_logical_cpp(a, b, c, d);
    r2 = integer_logical_(a, b, c, d);
    display_result("Test 1", a, b, c, d, g_Val1, r1, r2);

    a = 0x70987655;
    b = 0x55555555;
    c = 0xAAAAAAAA;
    d = 0x12345678;
    g_Val1 = 23;
    r1 = integer_logical_cpp(a, b, c, d);
    r2 = integer_logical_(a, b, c, d);
    display_result("Test 2", a, b, c, d, g_Val1, r1, r2);

    return(0);
}
