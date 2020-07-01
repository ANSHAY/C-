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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return root;
        }
        if(root->val == val){
            return root;
        }
        TreeNode* temp = searchBST(root->left, val);
        if(temp) return temp;
        temp = searchBST(root->right, val);
        if(temp) return temp;
        return NULL;
    }
};
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        if(root->val == val) return root;
        TreeNode* node = searchBST(root->left, val);
        if(node) return node;
        return searchBST(root->right, val);
    }
};
