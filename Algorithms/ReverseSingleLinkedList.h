//
//  ReverseSingleLinkedList.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/23/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ReverseSingleLinkedList_h
#define OnlineJudge_ReverseSingleLinkedList_h

/** Definition for linked list node
 */
template <class T>
struct Node {
    T val;
    Node * next;
};

/** A typical program: reverse a given single linked list using constant space
 * and O(n) time complexity.
 */
template <class T>
class ReverseSingleLinkedList {
public:
    Node * reverse(Node * head) {
        Node * cur = head, prev = NULL, next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;        
    }
};

#endif
