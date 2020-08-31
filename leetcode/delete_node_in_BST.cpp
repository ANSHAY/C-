/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

    Search for a node to remove.
    If the node is found, delete the node.

Note: Time complexity should be O(height of tree).
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
    TreeNode* removeNode(TreeNode* node){
        if(!node->left) return node->right;
        if(!node->right) return node->left;
        TreeNode* temp = node->left;
        while(temp->right) temp=temp->right;
        temp->right = node->right;
        return node->left;
    }

    bool trav(TreeNode* root, int key){
        if(!root) return false;
        if(root->left && root->left->val==key){
            root->left = removeNode(root->left);
            return true;
        }
        if(root->right && root->right->val==key){
            root->right = removeNode(root->right);
            return true;
        }
        if(trav(root->left, key)) return true;
        return trav(root->right, key);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val==key){
            return removeNode(root);
        }
        trav(root, key);
        return root;
    }
};
