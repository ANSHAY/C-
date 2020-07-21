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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* p1= head, *p2=head;
        while(p1->next && p2->next && p2->next->next){
            p1=p1->next;
            p2=p2->next->next;
            if(p1->val == p2->val) return true;
        }
        return false;
    }
};
