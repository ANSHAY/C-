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
    bool check_tree(TreeNode* node, vector<int>& arr, int index){
        if(arr.size() <= index) return false;
        if(node->val == arr[index]){
            if(node->left){
                if(check_tree(node->left, arr, index+1)) return true;
            }
            if(node->right){
                if(check_tree(node->right, arr, index+1)) return true;
            }
            if(!node->left && !node->right) return arr.size()-1==index;
        }
        return false;
    }

    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(!root || arr.empty()) return false;
        return check_tree(root, arr, 0);
    }
};
