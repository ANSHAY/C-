#include<iostream>
#include<vector>
#include<string>
#include<algortihm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode *next;

   TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}
   TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
   TreeNode(int _val, Node* _left, Node* _right, Node* _next)
       : val(_val), left(_left), right(_right), next(_next) {}
};

class BinaryTree {
public:
    vector<int> preorderTraversal(TreeNode* root);
    vector<int> inorderTraversal(TreeNode* root);
    vector<int> postorderTraversal(TreeNode* root);
    vector<vector<int>> levelorderTraversal(TreeNode* root);
    int maxDepth(TreeNode* root);
    bool are_mirrors(TreeNode* left, TreeNode* right);
    bool isSymmetric(TreeNode* root);
    bool isSymmetric_iterative(TreeNode* root);
    bool hasPathSum(TreeNode* root, int sum);
    int search(vector<int>& inorder, int start, int end, int val);
    TreeNode* buildTreeRec_in_post(vector<int>& inorder, vector<int>& postorder, int start, int end);
    TreeNode* buildTree_in_post(vector<int>& inorder, vector<int>& postorder);
    TreeNode* buildTreeRec_pre_in(vector<int>& preorder, vector<int>& inorder, int start, int end);
    TreeNode* buildTree_pre_in(vector<int>& preorder, vector<int>& inorder)
    TreeNode* findNextNode(TreeNode* root, int left=0);
    TreeNode* connect(TreeNode* root);
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path);
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    string serialize(TreeNode* root);
    TreeNode* deserialize(string data);
};
