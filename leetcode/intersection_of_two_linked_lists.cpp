/*
Write a program to find the node at which the intersection of two singly linked lists begins.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* n1=headA;
        ListNode* n2=headB;
        int c1=0, c2=0;
        while(n1){
            c1++;
            n1 = n1->next;
        }
        while(n2){
            c2++;
            n2 = n2->next;
        }
        n1 = headA;
        n2 = headB;
        if(c1>c2){
            while(c1>c2){
                n1=n1->next;
                c1--;
            }
        }
        else{
            while(c2>c1){
                n2=n2->next;
                c2--;
            }
        }
        while(n1){
            if(n1==n2) return n1;
            n1=n1->next;
            n2=n2->next;
        }
        return n1;
    }
};
