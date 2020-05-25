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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int i=1;
        TreeNode* node;
        while(i<preorder.size()){
            node = root;
            while(true){
                if(node->val > preorder[i]){
                    if(node->left) node = node->left;
                    else{
                        node->left = new TreeNode(preorder[i]);
                        break;
                    }
                }
                else{
                    if(node->right) node = node->right;
                    else{
                        node->right = new TreeNode(preorder[i]);
                        break;
                    }
                }
            }
            ++i;
        }
        return root;
    }
};
