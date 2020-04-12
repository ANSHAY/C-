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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool left = true;
        bool right = true;
        if(root->left){
            left = (root->val > root->left->val) && isValidBST(root->left);
        }
        if(root->right){
            right = (root->val < root->right->val) && isValidBST(root->right);
        }
        return left && right;
    }
};
/*
[2,1,3]
[]
[5,1,4,null,null,3,6]
*/
