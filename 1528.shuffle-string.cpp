/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 * #TagCyclicSort
 * Similar question ::
 * 448. Find All Numbers Disappeared in an Array
 * 41. First Missing Positive
 */

// @lc code=start
class Solution {
public:
    string restoreString(string s, vector<int>& idx) {
        //string str(s.length(), ' ');
        for(int i = 0; i < s.length(); i++)
        {
            while(i != idx[i])
            {
                swap(s[i], s[idx[i]]);
                swap(idx[i], idx[idx[i]]);
            }
        }
        
        return s;
    }
};
// @lc code=end
/*
Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
            01234567
l e e t c o d e
0 1 2 3 4 5 6 7 
Place the index at right position  :: Cyclic sort

cyclic sort says pace the index at right place and keep swaping the
idx[i] and idx[idx[i]]



a b c
0 1 2 



*/


