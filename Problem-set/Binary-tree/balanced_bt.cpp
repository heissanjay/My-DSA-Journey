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

//  Approach - 2
class Solution {
public:
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = dfs(root->left);
        if(lh == -1) return -1;
        int rh = dfs(root->right);
        if(rh == -1) return -1;
        // if at any point of the
        if(abs(lh-rh) > 1) return -1;
        return max(lh,rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};