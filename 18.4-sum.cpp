/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       if(nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        
        for(int i = 0; i < nums.size() - 3; i++)
        {
            for(int j = i+1; j < nums.size() - 2; j++)
            {
                int k = j+1;
                int l = nums.size() - 1;
                while(k < l)
                {
                    long long sum = nums[i] + nums[j];
                    if(target == sum + nums[k] + nums[l])
                    {
                        ans.insert({nums[i], nums[j], nums[k], nums[l]});
                    }
                    if(sum + nums[k] + nums[l] > target)
                    {
                        l--;
                    }else{
                        k++;
                    }
                }
            }
        }
        vector<vector<int>> ret(ans.begin(), ans.end());
        return ret; 
    }
};
// @lc code=end

