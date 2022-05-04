/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 * #dailyChallange
 * #Twopass
 * #unorderedmap
 * #hash
 * #twosum
 * #2sum
 */

// @lc code=start
/*
Approach 1:
1. Use a Data base (Hash) which will keep trace of the nums 
2. Run for the whole array
3. If we find any element which adds up with any value in db and gives sum as k
    increase the count and remove the found number form the hash (decrement the freq)
4. else add the value to the hash (increment the freq)

TC : O(N)
SC : O(N)


class Solution {
    unordered_map<int,int> db;

public:
    int maxOperations(vector<int>& nums, int k) {
       int counter = 0;
       for(auto num : nums)
       {
           int key = k - num;
           if(db[key] > 0)
           {
               counter++;
               db[key]--;
           }else{
               db[num]++;
           }

       } 
       return counter;
    }
};

*/

/*

Approach 2: Use 2 sum approach ont the sorted array;

1. Sort the array
   [3,1,3,4,3], k = 6
   1, 3, 3 ,3, 4
2. Keep two pointers at starting and end
3. Run a loop while (left < right)
4. if sum of left and right num is equal to key increment the counter.
   and increment left and decrement the right
5. if sum of left and right > key decrement the right pointer
6. if sum of left and right > key increment the left pointer

Time Complexity : nLogn
SC : O(1);
*/
class Solution {
    
public:
    int maxOperations(vector<int>& nums, int key) {
       int counter = 0;
       int left = 0;
       int right = nums.size() - 1;
       sort(nums.begin(), nums.end());

       while(left < right)
       {
           if(nums[left] + nums[right] == key)
           {
               counter++;
               left++;
               right--;
           }else if(nums[left] + nums[right] > key)
           {
               right--;
           }else{
               left++;
           }
       }
       
       return counter;
    }
};

// @lc code=end

