// problem link - https://leetcode.com/problems/validate-binary-search-tree



class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL ) return true;
       // iterative approach
       stack<TreeNode*> bucket;
       TreeNode* prev = NULL;

       TreeNode* curr = root;
       while(curr != NULL || !bucket.empty()){
           while(curr){
               bucket.push(curr);
               curr = curr->left;
           }
           // now curr is in left most node
           curr = bucket.top();
           bucket.pop();
           if(prev != NULL && curr->val <= prev->val) return false;
           prev = curr;
           curr = curr->right;
       }
       return true;
    }
};