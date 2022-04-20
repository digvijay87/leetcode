/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache #Design #Iterator #HashMap #list #DoubleLinkedList
 * 
 * LRU : Least recent used cache, evict the most aged or least recent used
 * candidate, 
 * every entry touched by put, update or get gets the younger.
 * so difficulty is to keep track of the one which was touched by get API.
 * Intitution :: make a data structure which gives keep the recenttly touced
 * candidate at the front and aged one at the end. so we need a DS which can 
 * be double queue, or vector but we need to get put and get in O(1) TC
 * so we can use a list (double linked list) you can push pop from front and 
 * back.
 * but traversal is expensive so to make traversal in O(1) we need a hash to 
 * keep the track of iterator which will points the the begin of the list.
 *   
 */

// @lc code=start
class LRUCache {
    int size;
    unordered_map<int, int> cache;    // Cache for the key value
    list<int> age; // List for the recently touched candidate
    unordered_map<int, list<int>::iterator> position; // map of iterator for the keys

    void age_the_key(int key)
    {
        if(position.find(key) != position.end())
        {
            age.erase(position[key]);       // for the get API, If key exist in the key erase it because we are going to make it younger (place it int he front)
        }else if(age.size() >= size){       // for the Put api if size exceeds the capacity
            int leastRecentKey = age.back(); //the the aged one (from the back)
            age.pop_back();                  // Remove from the age data structure 
            position.erase(leastRecentKey); // remove it from the has because we keep only pair fit with size
        }
        age.push_front(key);    // Update the age list (place it int he front)
        position[key] = age.begin(); // update the hash of the key witht he youngest one (front front he age list)
    }

public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(position.find(key) != position.end())
        {
            age_the_key(key); // Update the age if the key in cache or in hash which has key and iterator 
            return cache[key];
        }
        return -1; 
    }
    
    void put(int key, int value) {
        age_the_key(key);           // Update the age for the touched key
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

