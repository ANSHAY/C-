class MyQueue {
public:
    /** Initialize your data structure here. */
    vector<int> stack;
    vector<int> buffer;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack.push_back(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(stack.size()>1){
            int temp = stack.back();
            stack.pop_back();
            buffer.push_back(temp);
        }
        int res = stack.back();
        stack.pop_back();
        while(buffer.size()>0){
            int temp = buffer.back();
            buffer.pop_back();
            stack.push_back(temp);
        }
        return res;
    }

    /** Get the front element. */
    int peek() {
        while(stack.size()>1){
            int temp = stack.back();
            stack.pop_back();
            buffer.push_back(temp);
        }
        int res = stack.back();
        while(buffer.size()>0){
            int temp = buffer.back();
            buffer.pop_back();
            stack.push_back(temp);
        }
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
