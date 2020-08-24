/*
Find the sum of all left leaves in a given binary tree.
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
    int res;
    void soll(TreeNode* node, bool left){
        if(!node->left && !node->right){
            if(left) res+=node->val;
            return;
        }
        if(node->left){
            soll(node->left, true);
        }
        if(node->right){
            soll(node->right, false);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        res=0;
        if(!root) return res;
        soll(root, false);
        return res;
    }
};
