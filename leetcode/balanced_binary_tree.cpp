/**
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:

 *  a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        if(!l || !r) return false;
        if(!root->left && !root->right){
            root->val = 1;
            return true;
        }
        else if(!root->left){
            if(root->right->val<=1){
                root->val = root->right->val+1;
                return true;
            }
            else return false;
        }
        else if(!root->right){
            if(root->left->val<=1){
                root->val = root->left->val+1;
                return true;
            }
            else return false;
        }
        else{
            if(abs(root->left->val - root->right->val)<=1){
                root->val = max(root->left->val, root->right->val) + 1;
                return true;
            }
            else{
                return false;
            }
        }
        return  false;
    }
};