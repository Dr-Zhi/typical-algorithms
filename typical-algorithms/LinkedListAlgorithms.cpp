//
//  LinkedListAlgorithms.cpp
//  typical-algorithms
//
//  Created by Yanling Zhi on 5/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#include "LinkedListAlgorithms.h"
#include "Types.h"

/** reverse a given single linked list using constant space.
 * Time complexity: O(n).
 */
ListNode * reverse(ListNode * head) {
    ListNode * cur = head, * prev = NULL, * next = NULL;
    while (cur) {
        next = cur->next; // keep next
        cur->next = prev;
        prev = cur; // update prev
        cur = next; // update cur
    }
    return prev;
}