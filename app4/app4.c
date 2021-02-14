#include<stdio.h>

int integer_mul_div_(int a, int b, int * out_prod, int * out_quo, int * out_rem);

int main () {
    int a = 247;
    int b = 85;

    int product;
    int quotient;
    int remainder;

    int res = integer_mul_div_(a, b, &product, &quotient, &remainder);

    printf("return code: %s\n", (1 == res) ? "Success" : "Error");
    printf("product = %d, quotient = %d, remainder = %d\n", product, quotient, remainder);

    return(0);
}

