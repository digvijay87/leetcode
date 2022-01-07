class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
      int size = nums.size();
      vector<int> retVect(size,0);
      int l = 0;
      int r = size - 1;
      
      for(int i = r; i >= 0 ; i--)
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
