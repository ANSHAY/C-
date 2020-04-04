/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> visited;
    Solution():visited(101){};
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        Node* newNode = new Node(node->val);
        visited[node->val] = newNode;
        for (Node* n: node->neighbors){
            if(!visited[n->val]){
                newNode->neighbors.push_back(cloneGraph(n));
            }
            else{
                newNode->neighbors.push_back(visited[n->val]);
            }
        }
        return newNode;
    }
};
