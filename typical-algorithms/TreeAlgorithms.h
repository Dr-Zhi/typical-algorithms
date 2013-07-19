//
//  TreeAlgorithms.h
//  typical-algorithms
//
//  Created by Yanling Zhi on 5/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef __typical_algorithms__TreeAlgorithms__
#define __typical_algorithms__TreeAlgorithms__

#include <vector>

using std::vector;

void traversePreorderIteratively(TreeNode * root,
                                 void (*visit)(TreeNode *));

void traverseInorderIteratively(TreeNode * root,
                                void (* visit)(TreeNode *));

void traverseInorderRecursively(TreeNode * root,
                                void (* visit)(TreeNode *));

void traversePostorderIterativelyNormal(TreeNode * root,
                                        void (* visit)(TreeNode *));

void traversePostorderIteratively(TreeNode * root,
                                  void (* visit)(TreeNode *));

void traversePostorderRecursively(TreeNode * root, void (* visit)(TreeNode *));

#endif /* defined(__typical_algorithms__TreeAlgorithms__) */
