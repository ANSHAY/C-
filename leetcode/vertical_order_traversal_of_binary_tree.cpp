/*
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.
*/
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<int>> resmp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int n=q.size();
            unordered_map<int, set<int>> mp;
            while(n>0){
                TreeNode* node=q.front().first;
                int c=q.front().second;
                q.pop();
                mp[c].insert(node->val);
                if(node->left) q.push({node->left, c-1});
                if(node->right) q.push({node->right, c+1});
                --n;
            }
            for(auto& p:mp){
                for(auto& v:p.second){
                    resmp[p.first].push_back(v);
                }
            }
        }
        for(auto& p:resmp){
            res.push_back(p.second);
        }
        return res;
    }
};
