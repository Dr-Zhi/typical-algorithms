//
//  main.cpp
//  typical algorithms
//
//  Created by Yanling Zhi on 3/23/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#include <iostream>
#include <string>
#include "numberAlgorithms.h"
#include "ArrayAlgorithms.h"
#include "CStringAlgorithms.h"

using namespace std;

int main(int argc, const char * argv[]) {
//    /* tests for composeIntegerWithArrayAndNoGreaterThan */
//    vector<int> array;
////    array.push_back(1);
////    array.push_back(5);
////    array.push_back(2);
//    array.push_back(4);
//    int N = 3;
//    int result = composeIntegerWithArrayAndNoGreaterThan(array, N);
//    cout << "result integer = " << result << endl;
//    
//    /* test for findKthElement */
//    vector<int> v1; // v1.push_back(1);
//    vector<int> v2; v2.push_back(2); v2.push_back(3);
//    int kthValue = findKthElement(v1, v2, 2);
//    cout << "kth element = " << kthValue << endl;
//    
//    /* test for inverseWordsInString */
//    char str[50] = "Hi, I am goo123d!!!";
//    CStringAlgorithms::inverseWordsInString(str);
//    cout << "inversed string = " << str << endl;
//    
//    int n = 5, k = 2;
//    partition(n, k);

    /* test for intervals intersection computation */
//    computeIntervalsIntersections();
    
//    const char * str = "-2147483647";
//    int value = CStringAlgorithms::atoi(str);
//    printf("value for string %s: %d", str, value);

    
//    char str1[] = "I am a Chinese";
//    CStringAlgorithms::inverseWordsOrderInString(str1);
//    printf("%s\n", str1);
//    
//    char str2[] = "    ";
//    CStringAlgorithms::inverseWordsOrderInString(str2);
//    printf("%s\n", str2);
//    
//    char str3[] = "    I   am    a     Chinese  ";
//    CStringAlgorithms::inverseWordsOrderInString(str3);
//    printf("%s\n", str3);
//    
//    char * str4 = NULL;
//    CStringAlgorithms::inverseWordsOrderInString(str4);
//    printf("%s\n", str4);
//    
//    char str5[] = "a";
//    CStringAlgorithms::inverseWordsOrderInString(str5);
//    printf("%s\n", str5);
    
    /* Test for sorting */
    int n = 5;
    printf("before sorting: ");
    int v[] = {9, 8, 7, 6, 5};
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    qsort(v, 0, 4);
    
//    bubbleSort(v, n);
    printf("\nafter sorting: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    
    return 0;
}

