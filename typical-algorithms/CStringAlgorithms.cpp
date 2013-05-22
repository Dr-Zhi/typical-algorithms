//
//  CStringAlgorithms.cpp
//  typical-algorithms
//
//  Created by Yanling Zhi on 5/20/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#include "CStringAlgorithms.h"

namespace CStringAlgorithms {
    /** strlen: return length of string s */
    size_t strlen(char * s) {
        char * p = s;
        while (*p) {
            ++p;
        }
        return p - s;
    }
    
    /** strcpy: copy string t to s. */
    char * strcpy(char * s, char * t) {
        char * p = s;
        while((*p++ = *t++));
        return s;
    }
    
    /** strcmp: return <0 if s < t, 0 if s == t, >0 if s>t. */
    int strcmp(char * s, char * t) {
        while (*s && *s++ == *t++);
        return *s - *t;
    }
    
    /** concatenate t to s. Assume enough space in t. */
    char * strcat(char * s, char * t) {
        char * p = s;
        while (*p) { // find the end of s
            ++p;
        }
        while ((*p++ = *t++));
        return s;
    }
    
    /** ascii to float number. A simple implementation.
     *
     * C99: A valid floating point number for atof using the "C" locale is
     * formed by an optional sign character (+ or -), followed by one of:
     * - A sequence of digits, optionally containing a decimal-point
     * character (.), optionally followed by an exponent part (an e or E 
     * character followed by an optional sign and a sequence of digits).
     - A 0x or 0X prefix, then a sequence of hexadecimal digits (as in 
     * isxdigit) optionally containing a period which separates the whole
     * and fractional number parts. Optionally followed by a power of 2 
     * exponent (a p or P character followed by an optional sign and 
     * a sequence of hexadecimal digits).
     * - INF or INFINITY (ignoring case).
     * - NAN or NANsequence (ignoring case), where sequence is a sequence 
     * of characters, where each character is either an alphanumeric 
     * character (as in isalnum) or the underscore character (_).
     */
    double atof(char s[]) {
        int i = 0;
        while (isspace(s[i])) {
            ++i;
        }
        double sign = (s[i] == '-') ? -1.0 : 1.0;
        if (s[i] == '+' || s[i] == '-') {
            ++i;
        }
        double value = 0.0;
        while (isdigit(s[i])) {
            value = value * 10.0 + (s[i] - '0');
        }
        double power = 1.0;
        if (s[i] == '.') {
            ++i;
        }
        while (isdigit(s[i])) {
            value = value * 10.0 + (s[i] - '0');
            power *= 10.0;
        }
        return sign * value / power;
    }
}
