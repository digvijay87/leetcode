class Solution {
public:
    int findNumbers(vector<int>& nums){
        int n;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int n = 0;
            while(nums[i])
            {
                n++;
                nums[i] = nums[i] / 10;
            }
            if( (n % 2) == 0)
            {
                count++;
            }
                
        }
        return count;
    }
};
