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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* cur;
        for(int i=1; i<preorder.size(); ++i){
            TreeNode* temp = root;
            while(true){
                cur = temp;
                if(preorder[i]<=temp->val){
                    if(temp->left) temp=temp->left;
                    else{
                        temp->left = new TreeNode(preorder[i]);
                        break;
                    }
                }
                else{
                    if(temp->right) temp=temp->right;
                    else{
                        temp->right = new TreeNode(preorder[i]);
                        break;
                    }
                }
            }
        }
        return root;
    }
};
