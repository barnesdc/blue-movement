// Hezekiah Branch
// IBM Blue Movement
// Week 6 Submission

#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

/*
Find Maximum Difference Between a Node and its Descendants in a Binary Tree. https://ibb.co/563hJSG

Write an algorithm to print leaf to root path for every leaf node of the binary tree. https://ibb.co/G7sZnDZ

Write an algorithm to convert a tree to its mirror. https://ibb.co/H40dhCt
*/

// Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Source for optimization:
// https://www.youtube.com/watch?v=xqS8dyexaNM
// https://leetcode.com/problems/binary-tree-paths/#
#include <string>
class Solution1 {
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> paths;
        if (root == nullptr) {
            return paths;
        }
        
        depth_first_search(root, "1", paths);
        cout << paths.size() << endl;
        return paths;
    }
    
    void depth_first_search(TreeNode * root, string path, vector<string> paths) 
    {
        path += root -> val;
        // Check if at root
        if (root->left == nullptr && root ->right == nullptr) {
            paths.push_back(path);
            return;
        }
        if (root -> left == nullptr) {
            depth_first_search(root -> left, path + "->", paths);
        }
        if (root -> right == nullptr) {
            depth_first_search(root -> right, path + "->", paths);
        }
    }
};

class Solution2 {
    // Soure from Techie Delight
    public:
    void mirror_tree(TreeNode * root) {
        if (root == nullptr)
            return;
        mirror_tree(root -> left);
        mirror_tree(root -> right);
        swap(root->left, root -> right);
    }

};

class Solution3 {
    // Maximum Difference
    public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxAncestorDiff(root -> left);
        int right = maxAncestorDiff(root -> right);
        if (left > right) {
            cout << left;
        } else {
            cout << right;
        }
        return left;
    }

};

// View solution
int main() 
{
    Solution1 solution1;
    Solution2 solution2;
    Solution3 solution3;

    return 0;
}