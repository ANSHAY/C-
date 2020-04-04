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
    map<int, map<int, vector<TreeNode*>>> memory;
    vector<TreeNode*> genTrees(int n, int start=1) {
        vector<TreeNode*> list;
        if(n==0 || start>n){
            list.push_back(NULL);
            return list;
        }
        if(!memory[n][start].empty()){
            return memory[n][start];
        }
        for(int i=start; i<=n; ++i){
            // for every i create a list of left trees
            vector<TreeNode*> left = genTrees(i-1, start);
            // create a list of right trees
            vector<TreeNode*> right = genTrees(n, i+1);
            // for all combinations of left and right trees attach them to root node i.e.,
            // iterate over all left trees
            for(TreeNode* l:left){
            // for every tree, create root node
                for(TreeNode* r:right){
                    TreeNode* root = new TreeNode(i);
                    // root->left = left tree
                    root->left = l;
                    // root->right = right tree
                    root->right = r;
                    // append root in the main list
                    list.push_back(root);
                }
            }
        }
        memory[n][start] = list;
        return list;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> list;
        if(n==0) return list;
        return genTrees(n);
    }
};
