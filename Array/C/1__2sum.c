/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

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
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

1. One solution is hash map :: (Not A good Solution)
take a array of 109 + 109 numbers (Which is penelty) Also there is problem in c to make a hashmap for negative numbers.
Traverse from 0 to n, set the value at a[i] location in the map and see if loaction (target - a[i]) is set, if yes
they this is the pair we can return.

2. Brute force (not a good solution) :: Traverse from 0 to n, for each element search again if we have pair or not. (O(n2). 
*/

/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  int *ret = (int*)malloc(sizeof(int)*2);
  int a[219] = {0};
  int offset = 110;
  int toCheck = 0;
  for(int i = 0; i < numsSize; i++){
    
    if(a[i] < 0)
    {
      a[abs(a[i])] = 1;
      
      toCheck = target - a[i];
      
      if(toCheck >= 0)
      {
        if(a[offset + toCheck] == 1)
        {
          ret[o] = i;
          ret[1] = toCheck;
          return ret;
        }
      
      
  
}
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  int ret* = (int*)malloc(sizeof(int)*2);
  ret[0] = -1;
  ret[1] = -1;
  for(int i = 0; i< numsSize; i++){
    for(int j = 0; j < numsSizel j++){
      if(i == j)
        continue;
      else{
        if(a[i] + a[j] == target)
        {
          ret[0] = i;
          ret[1] = j;
          return ret;
        }
      }
    }
  }
  return ret;
}
