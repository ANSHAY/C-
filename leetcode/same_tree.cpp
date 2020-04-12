/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool recCheck(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return (recCheck(p->left, q->left) && recCheck(p->right, q->right));
    }

    bool checkNodes(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return true;
    }

    bool iterCheck(TreeNode* p, TreeNode* q){
        queue<TreeNode*> p_q;
        queue<TreeNode*> q_q;
        p_q.push(p);
        q_q.push(q);
        while(!p_q.empty() && !q_q.empty()){
            TreeNode* temp_p = p_q.front();
            TreeNode* temp_q = q_q.front();
            p_q.pop();
            q_q.pop();
            if(!checkNodes(temp_p, temp_q)) return false;
            if(temp_p){
                p_q.push(temp_p->left);
                p_q.push(temp_p->right);
            }
            if(temp_q){
                q_q.push(temp_q->left);
                q_q.push(temp_q->right);
            }
        }
        if(p_q.empty() && q_q.empty()) return true;
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return recCheck(p, q);
        //return iterCheck(p,q);
    }
};
/*testcases
[1,2,3]
[1,2,3]
[]
[]
[1]
[1]
[1]
[2]
[1,2]
[3,2]
[1,2,5,4,7,8,9,6]
[1,2,5,4,7,8,5,6,9]
*/
