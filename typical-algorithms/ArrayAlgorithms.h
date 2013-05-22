//
//  ArrayAlgorithms.h
//  typical-algorithms
//
//  Created by Yanling Zhi on 5/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef __typical_algorithms__ArrayAlgorithms__
#define __typical_algorithms__ArrayAlgorithms__

#include <iostream>
#include <vector>

using std::vector;

/** quick sort algorithm on an array.
 * average complexity: O(nlogn), worst: O(n^2); space: O(1).
 */
void qsort(int v[], int left, int right);

/** Find the intersection of two sorted arrays. */
vector<int> findIntersection(const vector<int> & v1,
                             const vector<int> & v2);

/* Find the k-th Smallest Element in the Union of Two Sorted Arrays. */
int findKthElement(const vector<int> & v1,
                   const vector<int> & v2,
                   const int k);

#endif /* defined(__typical_algorithms__ArrayAlgorithms__) */
