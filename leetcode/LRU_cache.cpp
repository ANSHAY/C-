class LRUCache {
public:
    list<pair<int, int>> que;
    map<int, list<pair<int, int>>::iterator> mmp;
    int cache_size;
    LRUCache(int capacity) {
        cache_size = capacity;
    }

    int get(int key) {
        if(mmp.find(key) == mmp.end()){
            return -1;
        }
        int value = (*mmp[key]).second;
        que.push_front(make_pair(key, value));
        que.erase(mmp[key]);
        mmp[key] = que.begin();
        return value;
    }

    void put(int key, int value) {
        if(mmp.find(key) == mmp.end()){
            que.push_front(make_pair(key, value));
            mmp[key] = que.begin();
            if(que.size() > cache_size){
                mmp.erase(que.back().first);
                que.pop_back();
            }
        }
        else{
            que.push_front(make_pair(key, value));
            que.erase(mmp[key]);
            mmp[key] = que.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
