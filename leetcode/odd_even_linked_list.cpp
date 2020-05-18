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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        int i=0;
        int num_nodes=0;
        ListNode* node = head;
        ListNode* tail;
        ListNode* prev;
        while(node){
            tail=node;
            num_nodes++;
            node=node->next;
        }
        prev=head;
        node=head->next;
        num_nodes = (num_nodes>>1);
        while(i<num_nodes && node!=tail){
            prev->next=node->next;
            tail->next=node;
            tail=node;
            tail->next=NULL;
            prev=prev->next;
            node=prev->next;
            ++i;
        }
        return head;
    }
};
