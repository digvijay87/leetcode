/*

Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104


Intuition
First: Keep adding elements to the sum and keep updating the max.
Second : we need to deal with negative numbers.

Approach
This is kind of DP approach I need to see if the immidiate prev sum is negative or not.
If sum just before the current number is negative, I will consider the current number as current sum and update the max sum accordingly.
Else, I will add this current number to the previous sum and update the max sum accordingly.

Complexity
Time complexity:
O(N)O(N)O(N)

Space complexity:
O(1)O(1)O(1)

Code
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       //int ans = int_MIN;
       int cur = nums[0];
       int prev = nums[0];
       int ans = nums[0]; 

       for (int i = 1; i < nums.size(); i++)
       {
           if (prev < 0)            // We dont consider that because prev value that was negative will not help use making the subarray sum greater
           {
               cur = nums[i];
           } else{
               cur = nums[i] + prev;
           }
           prev = cur;
           ans = max(cur, ans);
       }
       return ans;
    }
};
