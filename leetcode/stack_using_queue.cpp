class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> que;
    queue<int> buffer;
    int top_num;
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        top_num = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(que.size()>1){
            top_num = que.front();
            buffer.push(top_num);
            que.pop();
        }
        int res = que.front();
        que.pop();
        queue<int> temp = que;
        que = buffer;
        buffer = temp;
        return res;
    }

    /** Get the top element. */
    int top() {
        return top_num;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
