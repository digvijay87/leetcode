/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
*/

int firstUniqChar(char * s){
    int map[128] = {0};
    
    int i = 0;
    int len = strlen(s);
    //printf("%d\n",len);
    for(i = 0 ; i < len; i++)
    {
        map[s[i]]++;
       // printf("i = %d map[s[i]] = %d\n",i,map[s[i]]);
    }
    
    for(i = 0; i < len; i++)
    {
        if(map[s[i]] == 1){
            return i;
        }
    }
    
    return -1;
}
