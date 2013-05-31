//
//  CStringAlgorithms.h
//  typical-algorithms
//
//  Created by Yanling Zhi on 5/20/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef __typical_algorithms__CStringAlgorithms__
#define __typical_algorithms__CStringAlgorithms__

#include <iostream>

namespace CStringAlgorithms {
    /** strlen: return length of string s */
    size_t strlen(const char * str);
    
    /** strcpy: copy string source to destination. */
    char * strcpy(char * destination, const char * source);
    
    /** Return an integer indicating the relationship between the strings:
     * <0 if str1 < str2, 0 if str1 == str2,
     * >0 if str1>str2. */
    int strcmp(const char * str1, const char * str2);
    
    /** Appends a copy of the source string to the destination string.
     * Assume: 
     * 1. enough space in destination;
     * 2. destination and source shall not overlap.
     */
    char * strcat(char * destination, const char * source);
    
    /** convert string to double. */
    double atof(const char * str);
    
    /** ascii to integer */
    int atoi(const char * str);
    
    /** inverse all the words (except numbers, punctuation) in a string. */
    void inverseWordsInString(char * str);
    
    /** inverse a string*/
    void inverseWordsOrderInString(char * str);
}

#endif /* defined(__typical_algorithms__CStringAlgorithms__) */
