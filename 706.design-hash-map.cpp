/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap #SystemDesign #Design
 * 
 */

// @lc code=start
class MyHashMap {
public:
    int size = 769;
    vector<list<pair<int,int>>> hash;
    MyHashMap() {
        hash.resize(size);
    }
    
    void put(int key, int value) {
        int idx = key%size;
        auto &mylist = hash[idx];
        
        for(auto &mypair : mylist){
            if(mypair.first == key){
                mypair.second = value;
                return;
            }
            
        }
        
        mylist.push_back({key,value});
    }
    
    int get(int key) {
        int idx = key%size;
        auto &mylist = hash[idx];
        
        for(auto &mypair : mylist){
            if(mypair.first == key){
                return mypair.second;
                }
            
        }
        return -1;
    }
    
    void remove(int key) {
        int x=key%size;
        auto& mylist=hash[x];
        for(auto mypair :mylist){
            if(mypair.first==key){
                mylist.remove(mypair);
                return ;
            }
    }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

