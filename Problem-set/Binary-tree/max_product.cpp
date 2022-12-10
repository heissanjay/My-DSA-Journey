// problem-link
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/


class Solution {
public:
    long long totalSum = 0;
    long long productMax = 0;
    int mod  = 1e9 + 7;
    // traverse the tree and find the total sum
    void find_the_totalsum(TreeNode* root, long long &sum){
        if(root == NULL){
            return;
        }
        totalSum+=root->val;
        find_the_totalsum(root->left,totalSum);
        find_the_totalsum(root->right,totalSum);
    }
    long long calc_max_prod(TreeNode* root){
        if(root == NULL) return 0;

        long long left = calc_max_prod(root->left);
        long long right = calc_max_prod(root->right);

        long long subtree_sum = left + right + root->val;
        productMax = max(productMax, (subtree_sum) * (totalSum - subtree_sum));
        return subtree_sum;
    }
    int maxProduct(TreeNode* root) {
        find_the_totalsum(root,totalSum);
        calc_max_prod(root);
        return (int)(productMax % mod);
    }
// };