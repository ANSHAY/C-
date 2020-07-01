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
    int sum;
    void dfs(TreeNode* root, int val){
        if(!root) return;
        int v = val*10+root->val;
        if(!root->left && !root->right){
            sum+=v;
        }
        dfs(root->left, v);
        dfs(root->right, v);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};
