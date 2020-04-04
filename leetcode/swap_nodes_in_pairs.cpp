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
    ListNode* temp;
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        temp = head;
        head = head->next;
        temp->next = head->next;
        head->next = temp;
        head->next->next = swapPairs(head->next->next);
        return head;
    }
};
