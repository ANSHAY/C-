/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int n;
        bool rev=true;
        while(!q.empty()){
            n = q.size();
            vector<int> temp;
            rev = !rev;
            while(n>0){
                TreeNode* t = q.front();
                q.pop();
                n--;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                temp.push_back(t->val);
            }
            if(rev) reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }
};
