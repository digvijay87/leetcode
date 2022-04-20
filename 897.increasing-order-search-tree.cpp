/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree #Inorder #BST #MorisTraversal #DailyChalalnge #April172022 #Tree
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
    
public:
    TreeNode* increasingBST(TreeNode* root) {
       TreeNode *dummy = new TreeNode(0);
       TreeNode *node = dummy;
       // helper(root,node);
       TreeNode *cur = root;
       TreeNode *pre;

       while(cur != NULL)
       {
           if(cur->left == NULL)
           {
               dummy->right = new TreeNode(cur->val);
               dummy = dummy->right;
               cur = cur->right;
           }else{
               pre = cur->left;
               while(pre->right != NULL and pre->right != cur)
               {
                   pre = pre->right;
               }

               if(pre->right == NULL)
               {
                   pre->right = cur;
                   cur = cur->left;
               }else{
                   pre->right = NULL;
                   dummy->right = new TreeNode(cur->val);
                   dummy = dummy->right;
                   cur = cur->right;
               }
           }
       }
       return node->right; 
    }
};
// @lc code=end

