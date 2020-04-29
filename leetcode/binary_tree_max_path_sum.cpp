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
    int max_sum = INT_MIN;
    int max_val(TreeNode* root){
        int left=0, right=0;
        if(root->left) left = max_val(root->left);
        if(root->right) right = max_val(root->right);

        int max_val = max(root->val, root->val + max(left, right));
        max_sum = max(max_sum, max(max_val, root->val + left + right));
        return max_val;
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return max_sum;
        // check if current node makes the max_path
        // update max_sum
        // set max_sum for current node
        max_val(root);
        return max_sum;
    }
};
