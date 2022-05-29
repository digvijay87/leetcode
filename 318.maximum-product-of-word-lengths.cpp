/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 * #DailyChallange
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<string,int> map;
        int ans = 0;
        int n = words.size();
        
        for(int i = 0; i < n; i++ )
        {
            int mask = 0;
            if(map.find(words[i]) == map.end()){
                for (char c : words[i]){
                    mask |= 1 << (c - 'a');
                }
                map[words[i]] = mask;
            }
            
            for(int j = 0; j < i; j++)
            {
                if(map[words[i]] & map[words[j]]) continue;
                
                int temp = words[i].length() * words[j].length();
                ans = max(ans, temp);
            }
        }
        return ans;
        
    }
};
// @lc code=end

