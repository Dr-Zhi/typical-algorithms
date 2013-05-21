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
    size_t strlen(char * s);
    
    /** strcpy: copy string t to s. */
    char * strcpy(char * s, char * t);
    
    /** strcmp: return <0 if s < t, 0 if s == t, >0 if s>t. */
    int strcmp(char * s, char * t);
    
    /** concatenate t to s. Assume enough space in t. */ 
    char * strcat(char * s, char * t);

}

#endif /* defined(__typical_algorithms__CStringAlgorithms__) */
