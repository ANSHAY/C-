/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return res;
        queue<Node*> q;
        q.push(root);
        int numnodes;
        vector<int> temp;
        while(!q.empty()){
            numnodes = q.size();
            temp = vector<int>();
            while(numnodes--){
                Node* nd = q.front(); q.pop();
                temp.push_back(nd->val);
                for(int i=0; i<nd->children.size(); ++i){
                    q.push(nd->children[i]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
