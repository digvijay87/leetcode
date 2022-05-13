/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/*
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q; 
        //Node* right;
        if(root == NULL) return root;

        q.push(root);
        while(!q.empty())
        {
            Node *right = NULL;
            int n = q.size();

            for(int i = 0; i < n; i++)
            {
                Node* cur = q.front();    
                q.pop();
                cur->next = right;
                right = cur;                
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
        }
        return root;
    }
};

*/

class Solution {
public:
    Node* connect(Node* root) {
       if(root == NULL) return NULL;

       Node* dummy = new Node(0);
       Node* cur = root;
       Node* cursor = dummy;

       while(cur != NULL)
       {
           if(cur->left != NULL)
           {
               cursor->next = cur->left;
               cursor = cursor->next;
           }
           if(cur->right != NULL)
           {
               cursor->next = cur->right;
               cursor = cursor->next;
           }

           if(cur->next != NULL)
           {
               cur = cur->next;
           }else{
               cur = dummy->next;
               cursor = dummy;
               dummy->next = NULL;
           }
       }
       return root;
    }
};

// @lc code=end




