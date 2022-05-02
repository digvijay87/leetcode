/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
	#twopass #dailychallange
 */

// @lc code=start
class Solution {
    bool isodd(int a)
    {
        int ret = (a & 1 ) ? 1 : 0;
        return ret;
    }

    bool iseven(int a)
    {
        int ret = (a & 1 ) ? 0 : 1;
        return ret;
    }
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j)
        {
            if(isodd(nums[i]) and iseven(nums[j]))
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }else if(iseven(nums[i]))
            {
                i++;
            }else{
                j--;
            }
        }
        return nums;
    }
};
// @lc code=end
/*
3 1 2 4

i     j

*/
