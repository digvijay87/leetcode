// ****** Brute force ********//
// O(n2)
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                    return {i,j};
            }
        }
        return {};
    }
};

*/
// ******** Hash Map single loop *********//
// O(n)
/*
    Key : value at the index;
    Check the pair position of the key, i.e. [target - key]
        if value exist at the pair poistion. 
            return the index and the value at the pair position.
        else
            fill the index as value at the key'th index so that when you iteration             reaches at the pair position it will find the index of the 1st value of             the pair.
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    
    1.  Key = nums[0] = 2
        Pair position = target - key; i.e. 9-2 = 7; test.count(7)  which will               return 0;
        so go to else part and fill; 
        test[key] = i; i.e. test[2] = 0;
    2. Key = nums[1] = 7
        Pair position = target - key; i.e. 9-7 = 2; test.count(2) will be 1
        return {i, nums[target - key]}
        
    else never exist i.e. return empty vctor.
    
    |||||||||||||||||
    |       |       |
    |       |       |
    |       |       |
    |       |       |
    |       |       |
    |       |       |
    |       |       |
    |       |       |
 2. |   7   |   1   |       (9-7) = 2; at key loacation 2, we have pair which is 0
    |       |       |
    |       |       |
    |       |       |
    |       |       |
 1. |   2   |   0   |
    |       |       |
    |       |       |
    |||||||||||||||||

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        int i = 0;
        for(; i < nums.size(); i++)
        {
            int key = nums[i];       // 2, 7
            if(umap.count(target - key) == 0) // at (9-7) == 0 true; at (9-2) != 0
                umap[key] = i;       // at 2 -> 0
            else
                return {i,test[target - key]}; // return { 1, at 2-> 0}
        }
    return {};
    }
};


/*
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/
