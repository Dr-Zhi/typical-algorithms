//
//  numberAlgorithms.cpp
//  typical-algorithms
//
//  Created by Yanling Zhi on 5/19/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#include "numberAlgorithms.h"

#include <vector>
#include <cmath>
#include <cassert>

using std::vector;

/** Compose an integer no greater than a given integer while only using
 * numbers in an array. Complexity: O(lgN).
 * Assumptions:
 * 1. all the numbers in the array is in 0~9;
 * 2. N >= 0;
 * 3. the array is not empty.
 * @param array[] numbers array
 * @param N the max value for the returned integer
 * @return return the integer no greater than N, and composed of
 * the integers in the array. Return -1 if inputs are invalid.
 */
int composeIntegerWithArrayAndNoGreaterThan(const vector<int> array,
                                            const int N) {
    int InvalidOutput = -1;
    if (array.empty() || N < 0) { // input array or N is invalid
        return InvalidOutput;
    }
    vector<bool> arrayNumberExists(10, false);
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] < 0 || array[i] > 9) {
            return InvalidOutput; // input array is invalid
        }
        arrayNumberExists[array[i]] = true;
    }
    
    vector<int> tableForClosestSmallerNumber(10);
    int closestSmallerNumber = -1, maxDigit = -1;
    // pre-calculate the existing closest smaller number for a given number in 0~10
    for (int i = 0; i < 10; ++i) {
        tableForClosestSmallerNumber[i] = closestSmallerNumber;
        if (arrayNumberExists[i]) {
            maxDigit = i;
            closestSmallerNumber = i;
        }
    }
    if (N < 10 && !arrayNumberExists[N] &&
        tableForClosestSmallerNumber[N] < 0) {
        return InvalidOutput; // input array or N is invalid
    }
    
    int maxValueBefore = 0, resultInteger = 0;
    int value = N, digit = 0, base = 1, valueProcessed = 0;
    while (value > 0) {
        digit = value % 10;
        bool isMostSignificantBit = (value / 10 == 0);
        int closestSmallerNumber = tableForClosestSmallerNumber[digit];
        if (!arrayNumberExists[digit]) {
            resultInteger = maxValueBefore; // update value for lower bits
        }
        int valueForCurrentBit = 0; // for current decimal bit, default zero
        if (resultInteger > valueProcessed) {
            if (closestSmallerNumber >= 0) {
                valueForCurrentBit = closestSmallerNumber;
            }
            else if (!isMostSignificantBit) {
                valueForCurrentBit = maxDigit;
            }
        }
        else {
            if (arrayNumberExists[digit]) {
                valueForCurrentBit = digit;
            }
            else if (closestSmallerNumber >= 0) {
                valueForCurrentBit = closestSmallerNumber;
            }
            else if (!isMostSignificantBit) {
                valueForCurrentBit = maxDigit;
            }
        }
        resultInteger += valueForCurrentBit * base;
        
        valueProcessed += digit * base;
        maxValueBefore += maxDigit * base;
        base *= 10, value /= 10;
    }
    
    return resultInteger;
}

/** Compute fibonacci number f(n): f(n) = f(n-1) + f(n-2), with 
 * f(1) = f(2) = 1;
 */
int fibonacciNumber(int n) {
    if (n < 3) {
        return 1;
    }
    int base1 = 1, base2 = 1;
    for (int i = 3; i <= n; ++i) {
        base2 += base1;
        base1 = base2 - base1;
    }
    return base2;
}

/** Compute the square root using Newton iteration algorithm
 * f(x) = x^2 - a = 0, f'(x0) = (f(x) - f(x0)) / (x - x0)
 * => x = x0 - f(x0) / f'(x0) = x0 - (x0^2 - a) / 2x0 = (x0 + a/x0) / 2;
 * => iteration formula: x_{n+1} = (x_n + a / x_n) / 2;
 * The initial value is essential to the performance.
 *
 * References:
 * http://blog.punkid.org/2008/02/28/compute-the-square-root-via-newtons-iteration/
 * http://www.nowamagic.net/algorithm/algorithm_EfficacyOfFunctionSqrt.php
 */
double sqrt(double x) {
    assert(x >= 0);
    double val = 1, last;
    double eps = 1e-6;
    do {
        last = val;
        val = (val + x / val) / 2.0;
    } while (fabs(val - last) > eps);
    return val;
}



/** Given n and k, output the ways to split n items into k partitions, 
 * with each partition having >= 0 items.
 */
void partition(const int n, const int k) {
    // forward declaration
    void partitionRecursively(const int n, const int k,
                              vector<int> &);
    
    vector<int> partitions;
    partitionRecursively(n, k, partitions);
}

void partitionRecursively(const int n, const int k,
                          vector<int> & partitions) {
    if (n < 0 || k < 0 || (n > 0 && k <= 0)) {
        return;
    }
    
    if (k == 0) { // output the partition
        for (int i = 0; i < partitions.size(); ++i) {
            printf("%d ", partitions[i]);
        }
        printf("\n");
    }
    
    for (int i = (partitions.size() == 0) ? 0 : *partitions.rbegin();
         i <= n; ++i) {
        partitions.push_back(i);
        partitionRecursively(n-i, k-1,
                             partitions);
        partitions.pop_back();
    }
}

/** implement x^n. */
double power(double x, int n) {
    bool isNegative = (n < 0);
    if (isNegative)  n = -n;
    double result = 1;
    while (n > 0) {
        if (n & 1) result *= x;
        x *= x;
        n = n >> 1;
    }
    if (isNegative)
        result = 1.0 / result;
    return result;
}


