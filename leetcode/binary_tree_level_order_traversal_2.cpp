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
 /*
 Given binary tree [3,9,20,null,null,15,7],
 return its bottom-up level order traversal as:
 [
   [15,7],
   [9,20],
   [3]
 ]
 0. root
 1. for each level, find its children, push to a deque
 2. pop_front this level
 3. reverse res order

 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(!root) return res;
        que.push(root);
        int num_nodes=1;
        TreeNode* temp;
        while(!que.empty()){
            num_nodes = que.size();
            vector<int> level;
            while(num_nodes>0){
                temp = que.front();
                que.pop();
                level.push_back(temp->val);
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
                num_nodes--;
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
