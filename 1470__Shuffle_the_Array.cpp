/*
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0;
        int j = n;
        
        vector<int> ans(2*n, 0);
        
        for(int idx = 0; idx < 2*n;)
        {
            ans[idx++] = nums[i++];
            ans[idx++] = nums[j++];
        }
        return ans;
    }
};

i = 0
    for (let j = n; j < nums.length; j++) {
        const num1 = nums[j] & 1023
        const num2 = nums[j] >> 10
        nums[i] = num1
        nums[i + 1] = num2
        i += 2    

*/
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = n-1;
        int j = 2 * n -1;
        
        for(;j >=n; i--, j--)
        {
            nums[j] = nums[j] << 10;
            nums[j] |= nums[i]; 
        }
        
        i = 0; 
        j = n;
        for(;j < 2*n; j++)
        {
            nums[i++] = nums[j] & 1023;
            nums[i++] = nums[j] >> 10;
            
        }
        return nums;
        
    }
};
/*

Interesting thing is nums[i] is in the range of 1 to 10^3,
can I make a pair of 2 numbers ?
yes .
1 number will take not more than 10 bits so I can make pair of 2 numbers in 1 word i.2. in 32 bits.
how ?
nums2 = num1 | num2 << 10
pair of what ? pair of num[n-1] and num[2n] and store it at num[2n]


/*
