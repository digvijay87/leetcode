/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

*/
/* 
approach::
1. Identify left most piller 
2. Identify right most piller 

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;
        int left_max = 0;
        int right_max = 0;
        
        while(l < r)
        {
            if(height[l] < height[r])
            {
                if(height[l] >= left_max)
                {
                    left_max = height[l];
                }
                else
                {
                    ans += left_max - height[l];
                }
                l++;
            }
            else
            {
                if(height[r] >= right_max)
                {
                    right_max = height[r];
                }
                else
                {
                    ans += right_max - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};
