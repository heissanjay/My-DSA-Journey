// problem link
// https://leetcode.com/problems/binary-tree-inorder-traversal


// Solution Approach
// Iterative Method or Non-Recursive Method


class Solution {
public:
    vector<int> result;
    stack<TreeNode*> bucket; // to store the node
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *curr = root;

        while(curr || !bucket.empty()){
            while(curr){
                bucket.push(curr);
                curr = curr->left;
            }
            curr = bucket.top();
            bucket.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }
};