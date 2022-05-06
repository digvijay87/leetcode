/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start

/*
This is the problem for trimming the string. 
when we trim the string we need to keep track of previous characters, 
and trim the recent previous. 
since we need to consider recent previous, DS clicked in my mind is 
stack and hshmap to keep the frequency. 

Improved 1. :: instead of stack of charctor and hash we can use stack
of pair of charactor and int (freq).

1. stack of char and int.
2. if char is same as top of the member of the stack, raise the freq of the 
top member. 
3. if top member has freq == k, remove from the stack.
4. if top member is not equal the current char of the string push the 
current char with freq = 1.

5. keep removing all the elements from the stack and append them to a 
string for according to freq. 
6. Reverse the resulted string. 

Improved Version 2:: 

In the above approach we needed a stack which needs to give you previous recent
and at the end we needed element from the bottom of the stack for the 
final result. 

instead of stack STL if I use vecotr of pair of char and int, I keep avoid 
revrse of the string at the end, but iterating the vector from the 
starting at the end and consider the previous recent by taking the member 
form the Back. 

TC :: O(N)
SC :: O(N) For the stack. 

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"

maystack = 
1. d-1,  e-1 e-2 e-3 pop(e-3),d-2, b-1 b-2, c-1 c-2 c-3, pop(c-3),b-3 pop(b-3), d-3, pop(d-3), a-1 a-2.
2. a-2
4. output = "aa"

*/
class Solution {
    vector<pair<char, int>> mystack;
public:
    string removeDuplicates(string s, int k) {
        for(auto c : s)
        {
            if(mystack.size() > 0 and mystack.back().first == c)
            {
                mystack.back().second += 1;
                if(mystack.back().second == k)
                {
                    mystack.pop_back();
                }
            }else{
                mystack.push_back({c, 1});
            }
        }
        string st;
        for(auto p : mystack)
        {
            for(int i = 0; i < p.second; i++)
            {
                st += p.first;
            }
        }
        return st;
    }
};
// @lc code=end
