/*
You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void insert(Node* node){
        Node* temp = node->next;
        node->next = node->child;
        node->child->prev = node;
        node->child = NULL;
        Node* t = node->next;
        while(t->next) t=t->next;
        t->next = temp;
        if(temp) temp->prev = t;
    }

    Node* flatten(Node* head) {
        if(!head) return head;
        Node* node=head;
        while(node->next){
            if(node->child){
                insert(node);
            }
            node = node->next;
        }
        return head;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* trav(Node* node){
        while(node->next){
            if(node->child){
                node = insert(node);
            }
            else node=node->next;
        }
        if(node->child){
            node = insert(node);
        }
        return node;
    }

    Node* insert(Node* node){
        Node* temp = node->next;
        node->next = node->child;
        node->child->prev = node;
        node->child = NULL;
        Node* t = node->next;
        t = trav(t);
        t->next = temp;
        if(temp) temp->prev = t;
        return t;
    }

    Node* flatten(Node* head) {
        if(!head) return head;
        Node* node=head;
        trav(node);
        return head;
    }
};
