/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 * #MonitonicQueue
 * #Stack-sortablepermutation
 * #stack
 * #queue
 * #dqueue
 * #dailychallange
 * Similar question :: 
 * https://leetcode.com/problems/daily-temperatures/
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * https://leetcode.com/problems/next-greater-element-i/
 * https://leetcode.com/problems/next-greater-element-ii/
 * https://leetcode.com/problems/online-stock-span/
 * https://leetcode.com/problems/132-pattern/
 * https://leetcode.com/problems/sum-of-subarray-minimums/
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 * 
 * Important links :: 
 * https://link.medium.com/qyg42kjqG5
 * https://link.medium.com/1Bo0jcJuw5
 */

// @lc code=start
/* 
Pattern 123 :: to solve this we can start form end or start, 
lets start fromt he begin :: we find the first small element and 
then 2nd compare to previous then 3rd. 

Pattern : 132 :: that is a[i] < a[k] < a[j] where i < j < k

Intution : 
1. Begin fromt he end 
2. find the 1st element and store (3rd) from the left which is greater then of any 
element of its right. which makes 32 pattern. else keep pushing the elemnt 
into the stack. 
3. if any element is less then 3rd element return true.

This is one of the problem form monotonic queue (either decresing or increasing)

Similar problem :: 
https://leetcode.com/problems/daily-temperatures/
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int third = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(nums[i] < third) return true;
            while(!st.empty() and nums[i] > st.top())
            {
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};
// @lc code=end

/*

one 
two 
three

[3, < 1, > 4,  2]
one  one   thre

one
if(nums[i] < one)
{

}
1. Find the one and make make the flag
2. if cur < pre make it one. 
3. if cur is > prev make it three. 
4. if cur is < cur-1 and two and return true else return false. 


*/