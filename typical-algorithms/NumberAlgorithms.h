//
//  numberAlgorithms.h
//  typical-algorithms
//
//  Created by Yanling Zhi on 5/19/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef __typical_algorithms__numberAlgorithms__
#define __typical_algorithms__numberAlgorithms__

#include <iostream>
#include <vector>

using std::vector;

/** Compose an integer no greater than a given integer while only using
 * numbers in an array. Complexity: O(lgN).
 * @param array[] numbers array
 * @param N the max value for the returned integer
 * @return return the integer no greater than N, and composed of
 * the integers in the array. Return -1 if inputs are invalid.
 */
int composeIntegerWithArrayAndNoGreaterThan(const vector<int> array,
                                            const int N);

/** Compute fibonacci number f(n): f(n) = f(n-1) + f(n-2), with f(1) = f(2)
 * = 1;
 */
int fibonacciNumber(int n);


#endif /* defined(__typical_algorithms__numberAlgorithms__) */
