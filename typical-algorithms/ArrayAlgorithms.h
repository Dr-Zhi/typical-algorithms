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

/** typical algorithm: bubble sort on an arry.
 * Complexity: O(n^2) time, O(1) space.
 */
void bubbleSort(int v[], int n);

/** Find the intersection of two sorted arrays. */
vector<int> findIntersection(const vector<int> & v1,
                             const vector<int> & v2);

/* Find the k-th Smallest Element in the Union of Two Sorted Arrays. */
int findKthElement(const vector<int> & v1,
                   const vector<int> & v2,
                   const int k);

/** compute intersections of intervals. Read intervals from stdin and
 * print the results to stdout.
 */
void computeIntervalsIntersections();

/** Remove consecutive duplicates in range => the STL unique() method.
 */
template <class ForwardIterator>
ForwardIterator unique (ForwardIterator first, ForwardIterator last);

#endif /* defined(__typical_algorithms__ArrayAlgorithms__) */
