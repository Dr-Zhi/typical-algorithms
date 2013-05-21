//
//  main.cpp
//  typical algorithms
//
//  Created by Yanling Zhi on 3/23/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#include <iostream>
#include "numberAlgorithms.h"

using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    vector<int> array;
//    array.push_back(1);
//    array.push_back(5);
//    array.push_back(2);
    array.push_back(4);
    int N = 3;
    int result = composeIntegerWithArrayAndNoGreaterThan(array, N);
    cout << "result integer = " << result << endl;
}
