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
        ListNode* pivot = head;
        ListNode* temp;
        while(pivot->next){
            temp = pivot->next;
            pivot->next = temp->next;
            temp->next = head;
            head = temp;
        }
        return head;
    }

    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* node = head;
        int c=1;
        while(node->next){
            c++;
            node = node->next;
        }
        if(c==1) return true;
        node = head;
        for(int i=1; i<=c/2; ++i){
            node = node->next;
        }
        if(c%2) node=node->next;
        node = reverse(node);
        while(node){
            if(node->val != head->val) return false;
            node = node->next;
            head = head->next;
        }
        return true;
    }
};
/* testcases
[]
[1]
[1,2]
[1,1]
[1,2,3]
[1,2,1]
[1,2,3,4]
[1,2,2,1]
[1,2,3,4,5]
[1,2,3,2,1]
*/
