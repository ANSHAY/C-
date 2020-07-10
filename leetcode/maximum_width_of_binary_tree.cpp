/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        unsigned long long l=0, r=0;
        queue<TreeNode*> que;
        queue<unsigned long long> ns;
        que.push(root);
        ns.push(1);
        int numn = 0, res = 0;
        while(!que.empty()){
            numn = que.size();
            l=ns.front();
            r=0;
            while(numn>0){
                TreeNode* temp = que.front();
                que.pop();
                r = ns.front();
                ns.pop();
                if(temp->left){
                    que.push(temp->left);
                    ns.push(2*r);
                }
                if(temp->right){
                    que.push(temp->right);
                    ns.push(2*r+1);
                }
                numn--;
            }
            res = max(res, int(r-l+1));
        }
        return res;
    }
};
