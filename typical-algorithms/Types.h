//
//  Types.h
//  typical-algorithms
//
//  Created by Yanling Zhi on 5/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef typical_algorithms_Types_h
#define typical_algorithms_Types_h

#include <cstdio>

/** Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
    ~ListNode() { // destroy sub-list, assuming all are allocated by new
        delete next;
    }
};

/** Binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode() { // destroy subtrees, assuming they are allocated by new
        delete left;
        delete right;
    }
};



#endif
