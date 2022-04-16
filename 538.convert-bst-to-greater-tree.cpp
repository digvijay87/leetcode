/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void helper(TreeNode* root, int &sum)
    {
        if(root == NULL) return;
        if(root->right)
            helper(root->right, sum);
        
        sum = root->val + sum;
        root->val = sum;

        if(root->left)
            helper(root->left, sum);
        return;
     }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }
};
// @lc code=end

/*

recursive :: 
inplace::

1. Base if Root == NULL 
    return;
   if(root->right)
        helper(root->right, sum)
   sum = root->val + cum;
   root->val = sum;

   if(root->left)
        helper(root->left, sum)
    
    return;





*/