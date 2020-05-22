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
    int index=0;
    int res=0;
    int kthSmallest(TreeNode* root, int k) {
        if(root->left){
            kthSmallest(root->left, k);
        }
        if(++index==k) res = root->val;
        if(root->right){
            kthSmallest(root->right, k);
        }
        return res;
    }
};
