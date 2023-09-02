/*
Problem : 
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Intuition
First : It is clear from the question that neighter we need to follow the order of the digits nor we need to push the index of the to the output. So, we may sort the array that will help us in a sense that we can check numbers in proximity that sums up to zero.

Approach
Sort the array in ascending numbers.
Pick one number in increasing order at a time to find a duo that helps to find the tuple that sums up to zero.
If number that we picked is positive, we would not find a tuple because 3 numbers greater than 3 can not make zero sum.
In order to avoid duplicate tuple, we will see the picked number is equal to previous number we will move the iterator.
Complexity
Time complexity:
O(N∗N)O(N*N)O(N∗N)

Space complexity:
O(1)O(1)O(1)

Code
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        if(nums[0] > 0) return ans;
        int sum = 0;
        for(int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0) return ans;
            if (i>0 and nums[i] == nums[i-1]) continue;

            int low = i+1;
            int high = nums.size() - 1;
            sum = 0;
            while (low < high)
            {
                sum = nums[i] + nums[low] + nums[high];

                if (sum == 0)
                {
                    ans.push_back({nums[i],nums[low],nums[high]});
                    int previous_low = nums[low];
                    int previous_high = nums[high];
                    while (low < high and nums[low] == previous_low) {
                        low++;
                    }
                    
                    while (low < high and nums[low] == previous_low)
                    {
                        high--;
                    }
                    //low++;
                    //high--;
                }

                else if(sum < 0) low++;
                else high--;
            }
        }
        return ans;
    }
};
