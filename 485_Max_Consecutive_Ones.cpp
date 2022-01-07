/*
TC : O(N)
SC : O(N)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums);
    inline int compare(int &a, int &b);
    
};

int Solution::findMaxConsecutiveOnes(vector<int>& nums)
{
    int count = 0;
    int max = 0;
    int i = 0;
    for(i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1)
        {
            count++;
            max = compare(max,count);
        }
        else{
            count = 0;
        }
    }
    return max;
}

inline int Solution::compare(int &a, int &b)
{
    return (a>b) ? a : b;
}

