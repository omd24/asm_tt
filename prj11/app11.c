/* ===========================================================
   #File: app11.c #
   #Date: 15 Mar 2021 #
   #Revision: 1.0 #
   #Creator: Omid Miresmaeili #
   #Description: Simple strings - counting characters #
   #Notice: (C) Copyright 2021 by Omid. All Rights Reserved. #
   =========================================================== */

#include <stdio.h>

unsigned long long
count_chars_ (char * s, char c);

int main (void) {
    char nl = '\n';
    char * s0 = "Test string: ";
    char * s1 = " SearchChar: ";
    char * s2 = " Count: ";
    char c;
    char * s;
    s = "Four score and seven seconds ago, ...";
    printf("%s%s\n", s0, s);
    c = 's';
    printf("%s%c%s%llu\n", s1, c, s2, count_chars_(s, c));
    c = 'o';
    printf("%s%c%s%llu\n", s1, c, s2, count_chars_(s, c));
    c = 'z';
    printf("%s%c%s%llu\n", s1, c, s2, count_chars_(s, c));
    c = 'F';
    printf("%s%c%s%llu\n", s1, c, s2, count_chars_(s, c));
    c = '.';
    printf("%s%c%s%llu\n", s1, c, s2, count_chars_(s, c));
    s = "Red Green Blue Cyan Magenta Yellow";
    printf("%s%s\n", s0, s);
    c = 'e';
    printf("%s%c%s%llu\n", s1, c, s2, count_chars_(s, c));
    c = 'w';
    printf("%s%c%s%llu\n", s1, c, s2, count_chars_(s, c));
    c = 'l';
    printf("%s%c%s%llu\n", s1, c, s2, count_chars_(s, c));
    c = 'Q';
    printf("%s%c%s%llu\n", s1, c, s2, count_chars_(s, c));
    c = 'n';
    printf("%s%c%s%llu\n", s1, c, s2, count_chars_(s, c));
    return(0);
}
