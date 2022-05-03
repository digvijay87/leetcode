/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 * #twopass #dailychallange
 */

// @lc code=start
/*
This is two pass soluiton. 

Intitutiom ::
1. check for the first unsorted number from the left and right
2. From the range find the max and min val.
3. Check left and right again 
    a. if there is any value in the left > min value move left towards 0
    b. if there is any value at the right < max, move the right towards end of array
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0;
        int r = nums.size();

        while(l < r -1 and nums[l] <= nums[l+1])
        {
            l++;
        }
        if(l == r-1) return 0;
        
        r = nums.size() - 1;
        
        while(r > 0 and nums[r-1] <= nums[r])
        {
            r--;
        }
        int maxNo = INT_MIN;
        int minNo = INT_MAX;
        
        for(int i = l ; i <= r; i++)
        {
            maxNo = max(nums[i], maxNo);
            minNo = min(nums[i], minNo);
        }
        
        while(l > 0 and nums[l-1] > minNo)
        {
            l--;
        }
        
        while(r < nums.size() - 1 and nums[r+1] < maxNo)
        {
            r++;
        }
        return r - l + 1;
    }
};
// @lc code=end

