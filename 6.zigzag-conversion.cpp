/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 * #Array #Direction #String #Amazon #mod #hashkey
 */

// @lc code=start

/*
This question is to check how do you change the direction when you meet 
defined or 0th boundry (i.e. when you are at numsRows and 0).
Also a slight observation of how do fill only one char to make a
diag.

Intiution :: I need to upward diagnally when I reach at numRows
and move verticaly down when form 0 numRows.
so change of direction needs to be updated. 
(We did change of direction in squiral matrix for right left up and down)
here only one direction is enough to make a move

*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s; // to avoid division by zero error

        int dir = 1;
        vector<string> vec(numRows);
        int i = 0;
        
        for(auto c: s)
        {
            //need to check if we reached at numRows
            if(i % (numRows-1) == 0)
                dir = dir * -1; 
            
            vec[i].push_back(c);  
            if(dir == -1) i++;
            else i--;
        }
        string st;
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < vec[i].size(); j++)
            {
                st += vec[i][j];
            }
        }
        return st;
    }
};
// @lc code=end

