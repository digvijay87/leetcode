/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;
        
        unordered_map<int, Node*> map;
        vector<Node*> vec;
        
        Node* cursor = head;
        while(cursor)
        {
            vec.push_back(cursor);
            cursor = cursor->next;
        }
        
        cursor = head;
        
        Node* newHead = new Node(cursor->val);
        newHead->next = NULL;
        
        if(cursor->random == NULL)
        {
            map[0] = NULL;
        }
        else{
            map[0] = vec[cursor->random];
        }
        
        Node* cur = newHead;
        cursor = cursor->next
        int i = 1;
        while(cursor)
        {
            Node *temp = new Node(cursor->val);
            cur->next = temp;
            cur = temp;
            if(cursor->random)
            {
                map[i++] = vec[cursor->random];
            }
            cursor = cursor->next;
            
        }
        // Recover 
        
        cur = newHead;
        int len = i;
        for(i = 0; i < len; i++)
        {
            if(map[i] == NULL){
                cur->random = map[i];
            }else{
                cur->random = 
            }
            
        }
    }
};
*/

/*
Explination of below solution is here
https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43491/A-solution-with-constant-space-complexity-O(1)-and-linear-time-complexity-O(N)/42652
*/
/*    
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        
        
        Node* cur = head;
        Node* temp; 
        
        while(cur)
        {
            Node* temp;
            temp = new Node(cur->val, NULL, NULL);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
            
        }
        
        cur = head;
        
        while(cur)
        {
            if(cur->next && cur->random)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next ? cur->next->next : cur->next;
           
        }
        
        Node* original = head;
        Node* copy = head->next;
        temp = copy;
        
        while(original && copy)
        {
            original->next = original->next ? original->next->next : original->next;
            copy->next = copy->next ? copy->next->next : copy->next;
            
            original = original->next;
            copy = copy->next;
          
        }
        
        
        return temp;
    }
};
*/
/* Second solution by using map of node */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        
        map<Node*, Node*> m;
        
        Node* ptr = head;
        while(ptr)
        {
            m[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        
        /********************************
        1  ->  1`
        10 -> 10`
        11 -> 11`
        13 -> 13`
        7  -> 7`
        *********************************/
        
        ptr = head;
        
        while(ptr)
        {
            m[ptr]->next = m[ptr->next];  // map[7] is 7` so map[7]->next is 7`->next = m[7->next] is m[13] that is 13` so 7`->next = 13`
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        
        return m[head];
        }
};


