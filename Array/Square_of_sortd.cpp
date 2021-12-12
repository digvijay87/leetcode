/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
      int size = nums.size();
      vector<int> retVect(size,0);
      int l = 0;
      int r = size - 1;
      
      for(int i = size - 1; i >= 0 ; i--)
      {
        if(abs(nums[l]) > abs(nums[r]))
        {
          retVect[i] = (nums[l] * nums[l]);
          l++;
        }
        else{
          retVect[i] = (nums[r] * nums[r]);
          r--;
        }
      }
      return retVect; 
    }
};
