/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL #SystemDesign #Hash 
 * https://www.educative.io/courses/grokking-the-system-design-interview/m2ygV4E81AR
 * http://blog.gainlo.co/index.php/2016/03/08/system-design-interview-question-create-tinyurl-system/
 * 
 */

// @lc code=start
class Solution {
public:
    string hash = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string prefix = "http://tinyurl.com/";
    unordered_map<string, string> db;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string initial = "";   // I will take an intial empty string as key
        while(db.find(initial) != db.end())     //Untill I have an exiting key matiching with initial or new generated key
        {
            char ch = hash[rand() % 62];
            initial += ch;
        }
        
        string shorturl = prefix + initial;
        db[shorturl] = longUrl;
        return shorturl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return db[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

