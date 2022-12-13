// https://leetcode.com/problems/balanced-binary-tree

// Approach - 1
class Solution {
public:
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int l = height(root->left);
        int r = height(root->right);

        return max(l,r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return 1;

        int lh = height(root->left);
        int rh = height(root->right);

        return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
    }
};

