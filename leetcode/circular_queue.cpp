#include"circular_queue.h"

/** Initialize your data structure here. Set the size of the queue to be k. */
CircularQueue::CircularQueue(int k) : size{k}, head{-1}, tail{-1}{
    data.assign(k, 0);
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool CircularQueue::enQueue(int value) {
    if(isFull()){
        return false;
    }
    if(head==-1){
        head=0;
    }
    tail = (tail+1) % size;
    data[tail] = value;

    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool CircularQueue::deQueue() {
    if (isEmpty()){
        return false;
    }
    if(head==tail){
        head=-1;
        tail=-1;
        return true;
    }
    head = (head+1) % size;
    return true;
}

/** Get the front item from the queue. */
int CircularQueue::Front() {
    if(isEmpty()){
        return -1;
    }
    return data[head];
}

/** Get the last item from the queue. */
int CircularQueue::Rear() {
    if(isEmpty()){
        return -1;
    }
    return data[tail];
}

/** Checks whether the circular queue is empty or not. */
bool CircularQueue::isEmpty() {
    return (head==-1 && tail==-1);
}

/** Checks whether the circular queue is full or not. */
bool CircularQueue::isFull() {
    if((tail+1)%size==head){
        return true;
    }
    return false;
}
