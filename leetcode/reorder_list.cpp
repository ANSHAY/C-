/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* reverse(ListNode* head){
        ListNode* node = head->next;
        ListNode* temp = head;
        while(node){
            temp->next = node->next;
            node->next = head;
            head = node;
            node = temp->next;
        }
        return head;
    }

    void merge(ListNode* head, ListNode* head2){
        ListNode* node = head;
        ListNode* t;
        while(head2){
            t = head2->next;
            head2->next = node->next;
            node->next = head2;
            node = head2->next;
            head2 = t;
        }
    }

    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* node = head;
        int c=0;
        while(node){
            c++;
            node = node->next;
        }
        if(c==1) return;
        c = c%2?c/2+1:c/2;
        c--;
        node = head;
        while(c>0){
            node = node->next;
            c--;
        }
        ListNode* head2 = reverse(node->next);
        node->next = NULL;
        merge(head, head2);
    }
};
