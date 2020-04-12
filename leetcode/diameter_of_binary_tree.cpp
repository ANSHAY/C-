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
    map<TreeNode*, int> depths;
    int depth(TreeNode* root){
        if(!root) return 0;
        if(depths[root]) return depths[root];
        depths[root] = 1+max(depth(root->left), depth(root->right));
        return depths[root];
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int dia = depth(root->left)+depth(root->right);
        dia = max(diameterOfBinaryTree(root->left), dia);
        return max(dia, diameterOfBinaryTree(root->right));
    }
};
