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
    ListNode* reverseIterative(ListNode* head){
        if(!head){
            return head;
        }
        ListNode* pivot = head;
        while(pivot->next){
            temp = pivot->next;
            pivot->next = temp->next;
            temp->next = head;
            head = temp;
        }
        return head;
    }

    ListNode* reverseRec(ListNode* head){
        if(!head || !(head->next)){
            return head;
        }
        cout<<head->val;
        ListNode* temp = head;
        head = reverseRec(head->next);
        temp->next->next = temp;
        temp->next = NULL;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        //return reverseIterative(head);
        return reverseRec(head);
    }
};
