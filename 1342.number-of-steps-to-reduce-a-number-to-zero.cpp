/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 * #DailyChallange #Mod
 */

// @lc code=start
class Solution {
public:
    int numberOfSteps(int num) {        //14
        int count  = 0;
        while(num)
        {
            if(num & 1){                //1
                num = num - 1;
                count++;
            }else{
                num = num/2;                // 7
                count++; 
            }
                               //
        }
        return count;
    }
};
// @lc code=end

