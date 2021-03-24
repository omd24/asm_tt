/* ===========================================================
   #File: app12.c #
   #Date: 24 Mar 2021 #
   #Revision: 1.0 #
   #Creator: Omid Miresmaeili #
   #Description: Conact multiple strings #
   #Notice: (C) Copyright 2021 by Omid. All Rights Reserved. #
   =========================================================== */

#include <stdio.h>
#include <string.h>

size_t concat_strings_ (char * des, size_t des_size, char ** src, size_t src_n);

#define buffer_size 1024
#define test_size 1024

#define des1_size 64
#define des2_size 16
#define des3_size 128
#define des4_size 42
#define des5_size 11

void print_result (char * msg, char * des, size_t des_len, char ** src, size_t src_n) {

    // strcat_s (char * strDestination, size_t numberOfElements, char *strSource);
    // Note that the second parameter is the size of the destination buffer,
    // (not the remaining size)
    char test[test_size];
    memset(test, 0, test_size);

    char buffer[buffer_size];
    int buffer_used  = sprintf_s(buffer, buffer_size, "\nTest Case:  %s\n", msg);
    buffer_used += sprintf_s(buffer + buffer_used, buffer_size - buffer_used - 1, "   Original Strings\n");
    for (size_t i = 0; i < src_n; i++) {
        char * s1 = (strlen(src[i]) == 0) ? "<empty string>" : src[i];
        buffer_used += sprintf_s(buffer + buffer_used, buffer_size - buffer_used, "   i: %Id %s\n", i, s1);
        strcat_s(test, test_size, src[i]);
    }
    char * s2 = (strlen(des) == 0) ? "<empty string>" : des;
    buffer_used += sprintf_s(buffer + buffer_used, buffer_size - buffer_used, "   Concatenated Result\n");
    buffer_used += sprintf_s(buffer + buffer_used, buffer_size - buffer_used, "   %s\n", s2);

    printf(buffer);

    test[test_size - 1] = '\0'; // avoidng C6054 warning
    if (strcmp(test, des) != 0)
        printf("   Error - test string compare failed\n");
}
int main () {
// Destination buffer size OK
    char* src1 [] = {"One ", "Two ", "Three ", "Four"};
    size_t src1_n = sizeof(src1) / sizeof(char*);
    char des1[des1_size];
    size_t des1_len = concat_strings_(des1, des1_size, src1, src1_n);
    print_result("destination buffer size OK", des1, des1_len, src1, src1_n);
    // Destination buffer too small
    char* src2 [] = {"Red ", "Green ", "Blue ", "Yellow "};
    size_t src2_n = sizeof(src2) / sizeof(char*);
    char des2[des2_size];
    size_t des2_len = concat_strings_(des2, des2_size, src2, src2_n);
    print_result("destination buffer too small", des2, des2_len, src2, src2_n);
    // Empty source string
    char* src3 [] = {"Plane ", "Car ", "", "Truck ", "Boat ", "Train ", "Bicycle "};
    size_t src3_n = sizeof(src3) / sizeof(char*);
    char des3[des3_size];
    size_t des3_len = concat_strings_(des3, des3_size, src3, src3_n);
    print_result("empty source string", des3, des3_len, src3, src3_n);
    // All strings empty
    char* src4 [] = {"", "", "", ""};
    size_t src4_n = sizeof(src4) / sizeof(char*);
    char des4[des4_size];
    size_t des4_len = concat_strings_(des4, des4_size, src4, src4_n);
    print_result("all strings empty", des4, des4_len, src4, src4_n);
    // Minimum des_size
    char* src5 [] = {"1", "22", "333", "4444"};
    size_t src5_n = sizeof(src5) / sizeof(char*);
    char des5[des5_size];
    size_t des5_len = concat_strings_(des5, des5_size, src5, src5_n);
    print_result("minimum des_size", des5, des5_len, src5, src5_n);
    return 0;

}


