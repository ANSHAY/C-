class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int, int> mymap;
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mymap.find(val) != mymap.end()) return false;
        mymap[val] = vec.size();
        vec.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mymap.find(val) == mymap.end()) return false;
        mymap[vec.back()] = mymap[val];
        vec[mymap[val]] = vec.back();
        mymap.erase(val);
        vec.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
