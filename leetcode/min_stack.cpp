#include<iostream>
#include<vector>
#include<string>
#include<algortihm>
using namespace std;

// min stack
class MinStack {
    vector<int> data;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        data.push_back(x);
    }

    void pop() {
        if(data.size()<=0){
            return;
        }
        data.pop_back();
    }

    int top() {
        if(data.size()<=0) return -1;
        return data.back();
    }

    int getMin() {
        int min = INT_MAX;
        for (int i: data){
            if(i<min){
                min=i;
            }
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
