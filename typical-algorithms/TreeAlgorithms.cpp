//
//  TreeAlgorithms.cpp
//  typical-algorithms
//
//  Created by Yanling Zhi on 5/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#include "Types.h"
#include "TreeAlgorithms.h"
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

/** Traverse a tree in preorder iteratively */
void traversePreorderIteratively(TreeNode * root, void (*visit)(TreeNode *)) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        root = nodes.top(); nodes.pop();
        visit(root);
        if (root->right) {
            nodes.push(root->right);
        }
        if (root->left) {
            nodes.push(root->left);
        }
    }
    
}

/** traverse the tree by inorder iteratively. 
 * Is it possible to do in-order traversal without a stack?
 * The answer is yes, it’s possible. There’s 2 possible ways for now:
 * 1. By adding a parent pointer to the data structure, this allows us to 
 * return to a node’s parent. To determine when to print a node’s value, 
 * we would have to determine when it’s returned from. If it’s returned
 * from its left child, then you would print its value then traverse to 
 * its right child, on the other hand if it’s returned from its right 
 * child, you would traverse up one level to its parent.
 * 2. By using a Threaded Binary Tree. Read the article: 
 * http://en.wikipedia.org/wiki/Threaded_binary_tree
 */
void traverseInorderIteratively(TreeNode * root, void (* visit)(TreeNode *)) {
    stack<TreeNode *> nodes;
    while (root || !nodes.empty()) {
        while (root) {
            nodes.push(root);
            root = root->left;
        }
        root = nodes.top(); nodes.pop();
        visit(root);
        root = root->right;
    }
}

/** traverse the tree by inorder recursively. */
void traverseInorderRecursively(TreeNode * root, void (* visit)(TreeNode *)) {
    if (root == NULL) {
        return;
    }
    traverseInorderRecursively(root->left, visit);
    visit(root);
    traverseInorderRecursively(root->right, visit);
}

/** traverse the tree by postorder recursively.
 * A normal version: using only one stack.
 */
void traversePostorderIterativelyNormal(TreeNode * root,
                                        void (* visit)(TreeNode *)) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode *> nodes;
    nodes.push(root);
    TreeNode * cur, * prev = NULL;
    while (!nodes.empty()) {
        cur = nodes.top();
        if (!prev || prev->left == cur || prev->right == cur) { // traversing down the tree
            if (cur->left) {
                nodes.push(cur->left);
            }
            else if (cur->right) {
                nodes.push(cur->right);
            }
        }
        else if (prev == cur->left) { // traversing up from left child
            if (cur->right) {
                nodes.push(cur->right);
            }
        }
        else { // it's time to visit the node
            visit(cur);
            nodes.pop();
        }
        prev = cur;
    }
}

/** traverse the tree by postorder iteratively. 
 * A magic version: using a reverse "preorder" traversal: need an additional 
 * stack to keep the temporary data.
 */
void traversePostorderIteratively(TreeNode * root, void (* visit)(TreeNode *)) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode *> nodes;
    stack<TreeNode *> nodesInModifiedPreorder;
    nodes.push(root);
    while (!nodes.empty()) {
        root = nodes.top(); nodes.pop();
        nodesInModifiedPreorder.push(root);
        if (root->left) {
            nodes.push(root->left);
        }
        if (root->right) {
            nodes.push(root->right);
        }
    }
    while (!nodesInModifiedPreorder.empty()) {
        visit(nodesInModifiedPreorder.top());
        nodesInModifiedPreorder.pop();
    }
}

/** traverse the tree by postorder recursively. */
void traversePostorderRecursively(TreeNode * root, void (* visit)(TreeNode *)) {
    if (root == NULL) {
        return;
    }
    traversePostorderRecursively(root->left, visit);
    traversePostorderRecursively(root->right, visit);
    visit(root);
}

struct Edge {
    Edge(int s, int e) : start(s), end(e) {}
    int start;
    int end;
};

struct Vertex {
    vector<Edge> adjacentEdges;
};

vector<Vertex> vertices;
map<string, int> mapStringToIndex;

enum Color {
    White, // never visited
    Gray,  // being visited (i.e., as an ancestor for current)
    Black  // finished visiting
};

bool detectCycleWithDFS(int v, vector<Color> & visitedStatus) {
    bool isValidStatus = true;
    visitedStatus[v] = Gray; // mark as being visited
    for (int i = 0; i < vertices[v].adjacentEdges.size(); ++i) {
        int to = vertices[v].adjacentEdges[i].end;
        if (visitedStatus[to] == White) { // not visited before -> continue DFS
            isValidStatus = detectCycleWithDFS(to, visitedStatus);
            if (!isValidStatus) {
                return isValidStatus;
            }
        }
        else if (visitedStatus[to] == Gray) { // an ancestor -> cycle detected
            return false;
        }
    }
    visitedStatus[v] = Black; // mark as finished visiting
    return isValidStatus;
}

bool isValid(const vector<string> & formulas) {
    // construct the directed graph...... (omitted here)
    
    vector<Color> visitedStatus(vertices.size(), White);
    int startVertex = 0;
    bool isValidStatus = true;
    while (startVertex != vertices.size()) {
        for (int i = startVertex; i < vertices.size(); ++i) {
            if (visitedStatus[i] == White) {
                isValidStatus = detectCycleWithDFS(i, visitedStatus);
                if (!isValidStatus) {
                    return isValidStatus;
                }
            }
        }
    }
    
    return isValidStatus;
}
//a < b, b < d, a < c, c < d



