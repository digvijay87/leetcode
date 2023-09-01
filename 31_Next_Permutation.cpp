Intuition
The first thing that struck my mind was to find two neighboring digits that are in ascending order. For example, 12.
In a simple scenario, if we swap neighboring digits we can get the next number. However, there are more complicated use case that needs a few more deeper thought to put.

Approach
Firstly, as mentioned in the intuition section I traverse from the end and
figured out neighboring digits that are in ascending order.
Second, If we did not find any such duo that means either all the numbers are the same or the given number is the biggest number with given digits. For example, either 321 or 333. I just reversed the digits of the given vector to represent the next number.
Finally, I traversed from the end of the array to see any digit that is greater than the kth indexed digit. Once I found it I swapped.
In a few cases the above processed array could be the answer array.
However, there are a few cases where we need to reverse all the digits from k+1 to the end. Let's check the below example.
The given number is 0541
After swapping the 2 digits that can give us the next bigger number we get 1540
Now we found the next digit but all the digits from k+1 are in descending order. If we reverse all the digits i.e. make is an ascending number we will get the exact next higher number than the given number 1045.
Complexity
Time complexity:
O(1)O(1)O(1)

Space complexity:
O(n)O(n)O(n)

Code
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k;
        for (k = n-2; k >= 0; k--)
        {
            if (nums[k] < nums[k+1]) break;
        }
        //cout << k << endl;
        if (k < 0) return reverse(nums.begin(), nums.end());
        else{
            for (int l = n-1; l > k; l--)
            {
                if (nums[k] < nums[l]) {
                    swap(nums[k], nums[l]);
                    break;
                }
            }
            return reverse(nums.begin()+1+k, nums.end());
        }
        //return 
    }
};
