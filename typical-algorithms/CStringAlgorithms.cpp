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
    
}
