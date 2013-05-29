//
//  ArrayAlgorithms.cpp
//  typical-algorithms
//
//  Created by Yanling Zhi on 5/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#include "ArrayAlgorithms.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdio>

using namespace std;

using std::swap;
using std::vector;

/** quick sort algorithm on an array.
 * average complexity: O(nlogn), worst: O(n^2).
 * space: O(1), that is, this is a in-place algorithm.
 */
void qsort(int v[], int left, int right) {
    if (left >= right) {
        return;
    }
    
    // partition the array into two subarrays
    swap(v[left], v[left+(right-left)/2]); // select pivot. can be ignored
    int last = left;
    for (int i = left+1; i <= right; ++i) {
        if (v[i] < v[left]) {
            swap(v[i], v[++last]);
        }
    }
    swap(v[left], v[last]); // place the pivot
    
    // recursively sort the subarrays
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/** Find the intersection of two sorted arrays.
 * Assumption: there is NO repeated value in any sorted array.
 */
vector<int> findIntersection(const vector<int> & v1, const vector<int> & v2) {
    vector<int> intersection;
    int i = 0, j = 0;
    while ( i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            ++i;
        }
        else if (v1[i] > v2[j]) {
            ++j;
        }
        else { // find intersection
            intersection.push_back(v1[i]);
            ++i, ++j;
        }
    }
    return intersection;
}

/* Find the k-th Smallest Element in the Union of Two Sorted Arrays. 
 * Similar to findIntersection. 
 */
int findKthElement(const vector<int> & v1, const vector<int> & v2,
                   const int k) {
    int i = 0, j = 0;
    if (k > v1.size() + v2.size() || k <= 0) {
        return INT_MAX; // invalid value
    }
    int current;
    while (i + j < k) {
        if (i == v1.size()) {
            return v2[k-i-1];
        }
        if (j == v2.size()) {
            return v1[k-j-1];
        }
        
        if (v1[i] < v2[j]) {
            current = v1[++i];
        }
        else if (v1[i] > v2[j]) {
            current = v2[++j];
        }
        else {
            current = v1[++i];
            ++j;
        }
    }
    return current;
}



bool compare(const pair<int, int> interval1, pair<int, int> interval2) {
    return (interval1.first == interval2.first) ? (interval1.second < interval2.second) :
    (interval1.first < interval2.first);
}

/** compute intersections of intervals. Read intervals from stdin and
 * print the results to stdout.
 */
void computeIntervalsIntersections() {
    pair<int, int> interval;
    vector<pair<int, int> > allIntervals;
    while (scanf("[%d,%d] ", &interval.first, &interval.second) != EOF) {
        if (interval.first > interval.second) {
            cout << "invalid" << endl;
            return;
        }
        printf("[%d,%d]\n", interval.first, interval.second);
        allIntervals.push_back(interval);
    }
    if (allIntervals.size() < 2) {
        cout << "empty" << endl;
        return;
    }
    
    // calculate intersections
    vector<pair<int, int> > intersections;
    for(int i = 1; i < allIntervals.size(); ++i) {
        interval.first = max(allIntervals[i].first, allIntervals[0].first);
        interval.second = min(allIntervals[i].second, allIntervals[0].second);
        if(interval.first <= interval.second) {
            intersections.push_back(interval);
        }
    }
    
    if(intersections.size() == 0) {
        cout << "empty" << endl;
        return;
    }
    
    // sort the intersections
    sort(intersections.begin(), intersections.end(), compare);
    
    // merge the intersection
    vector<pair<int, int> > results;
    interval = intersections[0];
    for(int i = 1; i < intersections.size(); ++i) {
        if (intersections[i].first > interval.second) { // store the previous interval
            printf("[%d,%d] ", interval.first, interval.second);
            interval = intersections[i];
        }
        else { // merge the intervals
            interval.second = intersections[i].second;
        }
    }
    printf("[%d,%d]\n", interval.first, interval.second);
}

