/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree #BST #Inorder #Moris #DailyChanllange #19thApr22
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
    //void helper(TreeNode *)
    TreeNode *pre;
    TreeNode *first;
    TreeNode *second;

    void inorder(TreeNode *root)
    {
        if(root == NULL) return;

        inorder(root->left);

        if(first == NULL and (pre == NULL || pre->val >= root->val))
        {
            first = pre;
        }

        if(first != NULL and pre->val >= root->val )
        {
            second = root;
        }
        pre = root;
        inorder(root->right);

    }
public:
    void recoverTree(TreeNode* root) {
        //helper(root);
        if(root == NULL) return;
        first = NULL;
        second = NULL;
        pre = NULL;

        inorder(root);
        swap(first->val, second->val);
    }

};
// @lc code=end

