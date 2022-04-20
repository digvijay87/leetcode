/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST #Inorder #BST #MorisTraversal
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
/*
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        int ans = 0;
        while(root || !st.empty())
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            k--;
            if(k == 0)
            {
                ans = root->val;
                break;
            }
            root = root->right;
        }
        return ans;
    }
};
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        TreeNode *cur = root;

        while(cur != NULL)
        {
            if(cur->left == NULL)
            {
                if(--k==0) ans = cur->val;
                cur = cur->right;
            }
            else{
                TreeNode *prev = cur->left;
                while(prev->right != NULL and prev->right != cur)
                {
                    prev = prev->right;
                }
                if(prev->right == NULL)
                {
                    prev->right = cur;
                    cur  = cur->left;
                }else{
                    prev->right = NULL;
                    if(--k==0) ans = cur->val;
                    cur = cur->right;
                }

            }

        }
        return ans;
    }
};

// @lc code=end

