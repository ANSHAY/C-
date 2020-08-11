/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* node = head;
        int c=0;
        while(l1 && l2){
            node->val = l1->val + l2->val + c;
            c = node->val/10;
            node->val %= 10;
            l1=l1->next;
            l2=l2->next;
            if(l1 || l2){
                node->next = new ListNode();
                node = node->next;
            }
        }
        while(l1){
            node->val = l1->val + c;
            c = node->val/10;
            node->val %= 10;
            l1=l1->next;
            if(l1){
                node->next = new ListNode();
                node = node->next;
            }
        }
        while(l2){
            node->val = l2->val + c;
            c = node->val/10;
            node->val %= 10;
            l2=l2->next;
            if(l2){
                node->next = new ListNode();
                node = node->next;
            }
        }
        if(c==1){
            node->next = new ListNode(c);
        }
        return head;
    }
};
