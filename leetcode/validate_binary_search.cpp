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
    bool isValid(TreeNode* root, int lower, int upper, bool l_vld, bool u_vld) {
        if(!root) return true;

        if(l_vld && root->val <= lower) return false;
        if(u_vld && root->val >= upper) return false;

        if(!isValid(root->left, lower, root->val, l_vld, true)) return false;
        if(!isValid(root->right, root->val, upper, true, u_vld)) return false;

        return true;
    }

    bool isValidBST(TreeNode* root){
        return isValid(root, INT_MIN, INT_MAX, NULL, NULL);
    }
};
/*
[2,1,3]
[]
[5,1,4,null,null,3,6]
[10,5,15,null,null,6,20]
[1,1]
[4,4,4,4,4,4,4,4,4]
[1,2,5,4,7,8,9,6,52,3,6,5,4,7,8,9]
[3,1,5,0,2,4,6]
[3,1,5,0,2,4,6,null,null,null,3]
[2147483647]
[0,null,-1]
*/
