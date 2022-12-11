// problem-link
// https://leetcode.com/problems/binary-tree-maximum-path-sum/


class Solution {
private:
    int maxSum = INT_MIN;
public:
    int traverse_postorder(TreeNode* root){
        if(root == NULL) return 0;
        int left = max(traverse_postorder(root->left),0);
        int right = max(traverse_postorder(root->right),0);

        maxSum = max(maxSum, left+right+root->val);
        return max(left,right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
       traverse_postorder(root);
       return maxSum;
    }
};