/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
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
    int s;
    int pSum(TreeNode* root, int sum) {
        int count = 0;
        if(root->val == sum) count++;
        if(root->left){
            count+= pSum(root->left, sum-root->val);
        }
        if(root->right){
            count+= pSum(root->right, sum-root->val);
        }
        return count;
    }
    int ps(TreeNode* node){
        int c=0;
        c+=pSum(node, s);
        if(node->left) c+=ps(node->left);
        if(node->right) c+=ps(node->right);
        return c;
    }
    int pathSum(TreeNode* root, int sum){
        if(!root) return 0;
        s = sum;
        return ps(root);
    }
};
