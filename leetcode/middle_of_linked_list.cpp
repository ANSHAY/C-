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
    ListNode* middleNode(ListNode* head) {
        if(!head) return head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(true){
            if(!p1->next) return p2;
            if(!p1->next->next) return p2->next;
            p1 = p1->next->next;
            p2 = p2->next;
        }
    }
};
/* testcases
[1,2,3,4,5]
[1]
[1,2]
[1,2,3]
[1,2,3,4]
[5,4,7,8,9,6,5,2,3,6,5,4,12,5,4,7,8,9,56,8,7,4,5,2,3,6,0,2,5,6,3,8]
*/
