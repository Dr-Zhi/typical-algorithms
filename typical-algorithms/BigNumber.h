//
//  BigNumber.h
//  typical-algorithms
//
//  Created by Yanling Zhi on 6/19/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef __typical_algorithms__BigNumber__
#define __typical_algorithms__BigNumber__

#include <iostream>
#include <string.h>
#include <string>

using std::string;
using std::istream;
using std::ostream;

const int MAX_LENGTH = 1000;

class BigNumber {
public:
    BigNumber() : _length(0) {
        memset(_array, 0, sizeof(_array));
    }
    
    BigNumber(int num);
    
    BigNumber(const char * num);
    
    BigNumber & operator=(int num);
    
    BigNumber & operator=(const char * num);
    
    BigNumber operator+(const BigNumber & x) const;
    
    BigNumber operator+=(const BigNumber & x);
    
    bool operator<(const BigNumber & x) const;
    
    string str() const;
    
    friend istream & operator>>(istream & in, BigNumber & x);
    friend ostream & operator<<(ostream & out, const BigNumber & x);
    
private:
    int _length;
    int _array[MAX_LENGTH];
};

#endif /* defined(__typical_algorithms__BigNumber__) */
