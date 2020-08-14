/*
Remove all elements from a linked list of integers that have value val.
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val==val) head=head->next;
        if(!head) return head;
        ListNode* prev = head;
        ListNode* node = head->next;
        while(node){
            if(node->val == val) prev->next = node->next;
            else prev = prev->next;
            node = node->next;
        }
        return head;
    }
};
