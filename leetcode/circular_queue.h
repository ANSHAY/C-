#include<iostream>
#include<vector>
#include<string>
#include<algortihm>
using namespace std;

class CircularQueue {
    vector<int> data;
    int size;
    int head;
    int tail;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    CircularQueue(int k) : size{k}, head{-1}, tail{-1};
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value);
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue();
    /** Get the front item from the queue. */
    int Front();
    /** Get the last item from the queue. */
    int Rear();
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty();
    /** Checks whether the circular queue is full or not. */
    bool isFull();
};
