/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal #Inorder #Morristraversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode * cur = root;
        //cout << cur->val;
        while(cur != NULL)
        {
            if(cur->left == NULL)
            {
                ans.push_back(cur->val);
                cur = cur->right;
            }else{
                TreeNode * prev = cur->left;
            while(prev->right != NULL and prev->right != cur)
            {
                prev = prev->right;
            }

            if(prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }else{
                prev->right = NULL;
                ans.push_back(cur->val);
                cur = cur->right;
            }
                
            }
        }
        return ans;
    }
};
// @lc code=end

