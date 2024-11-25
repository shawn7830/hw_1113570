/*
Name: [shawn]
Student ID: [s1113570]
Date of Submission: 25-Nov-2024

Description:
This program finds the diameter of a binary tree. The diameter is the longest path between two nodes.

Steps:
1. Read the tree as level-order input (use -1 for null nodes).
2. Build the tree.
3. Calculate the diameter.
4. Print the result.

Functions:
- `buildTree`: Builds the tree from input.
- `diameterOfBinaryTree`: Finds the diameter.
*/


#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int diameterOfBinaryTreeUtil(TreeNode* root, int& diameter) {
    if (!root) {
        return 0;
    }

    int left_height = diameterOfBinaryTreeUtil(root->left, diameter);
    int right_height = diameterOfBinaryTreeUtil(root->right, diameter);

    
    diameter = max(diameter, left_height + right_height);

    
    return max(left_height, right_height) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    diameterOfBinaryTreeUtil(root, diameter);
    return diameter;
}

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<int> nodes;
    int val;
    while (iss >> val) {
        nodes.push_back(val);
    }

    TreeNode* root = buildTree(nodes);
    int diameter = diameterOfBinaryTree(root);
    cout << diameter << endl;

    return 0;
}