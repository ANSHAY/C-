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
    vector<int> res;
    vector<Node*> stack;
    void recTraversal(Node* root){
        if(!root) return;
        // add current value
        res.push_back(root->val);
        //loop over children recursively
        for(Node* ch:root->children){
            recTraversal(ch);
        }
    }
    void iterTraversal(Node* root){
        if(!root) return;
        stack.push_back(root);
        while(!stack.empty()){
            Node* nd = stack.back(); stack.pop_back();
            res.push_back(nd->val);
            for(int i=nd->children.size()-1; i>=0; --i){
                stack.push_back(nd->children[i]);
            }
        }
    }
    vector<int> preorder(Node* root) {
        //recTraversal(root);
        iterTraversal(root);
        return res;
    }
};
