/*
Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

    add(value): Insert a value into the HashSet.
    contains(value) : Return whether the value exists in the HashSet or not.
    remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing
*/

class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> data;
    MyHashSet() {

    }

    void add(int key) {
        if(!contains(key)){
            data.push_back(key);
        }
    }

    void remove(int key) {
        if(!contains(key)) return;
        for(int i=0; i<data.size();++i){
            if(data[i] == key) data[i] = -1;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        for(int d:data){
            if(key==d) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
