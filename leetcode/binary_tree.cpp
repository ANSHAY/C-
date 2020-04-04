#include"binary_tree.h"

vector<int> BinaryTree::preorderTraversal(TreeNode* root) {
    vector<int> out;
    vector<TreeNode*> stack;
    if(!root){
        return out;
    }
    stack.push_back(root);
    while(stack.size()>0){
        TreeNode* temp = stack.back();
        stack.pop_back();
        out.push_back(temp->val);
        if(temp->right){
            stack.push_back(temp->right);
        }
        if(temp->left){
            stack.push_back(temp->left);
        }
    }
    return out;
}

vector<int> BinaryTree::inorderTraversal(TreeNode* root) {
    vector<int> out;
    TreeNode* cur=root;
    vector<TreeNode*> stack;
    if(!root){
        return out;
    }
    //stack.push_back(root);
    while(cur || stack.size()>0){
        while(cur){
            stack.push_back(cur);
            cur = cur->left;
        }
        cur = stack.back();
        stack.pop_back();
        out.push_back(cur->val);
        cur = cur->right;
    }
    // iterate to the left most
    // push its value
    // iterate the right
    return out;
}

vector<int> BinaryTree::postorderTraversal(TreeNode* root) {
    vector<int> out;
    TreeNode* cur=root;
    vector<TreeNode*> stack;
    if(!root){
        return out;
    }
    //stack.push_back(root);
    while(cur || stack.size()){
        while(cur){
            if(cur->right) stack.push_back(cur->right);
            stack.push_back(cur);
            cur=cur->left;
        }
        cur = stack.back();
        stack.pop_back();
        if(cur->right && stack.size() && cur->right==stack.back()){
            stack.pop_back();
            stack.push_back(cur);
            cur=cur->right;
        }
        else{
            out.push_back(cur->val);
            cur = nullptr;
        }
    }
    return out;
}

vector<vector<int>> BinaryTree::levelorderTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    TreeNode* cur = root;
    vector<vector<int>> out;
    int num_nodes = 0;
    int level = 0;
    if(!root)
        return vector<vector<int>>();

    q.push(root);
    while (!q.empty()) {
        num_nodes = q.size();
        out.push_back(vector<int>());
        while (num_nodes > 0) {
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
            out[level].push_back(cur->val);
            q.pop();
            cur = q.front();
            num_nodes--;
        }
        level++;
    }
    return out;
}

int BinaryTree::maxDepth(TreeNode* root) {
    if (!root){
        return 0;
    }
    int l_depth = maxDepth(root->left);
    int r_depth = maxDepth(root->right);
    return max(l_depth, r_depth) + 1;
}

bool BinaryTree::are_mirrors(TreeNode* left, TreeNode* right){
    if(!left && !right){
        return true;
    }
    else if(!left || !right){
        return false;
    }
    return (left->val == right->val) &&
           (are_mirrors(left->left, right->right)) &&
           (are_mirrors(left->right, right->left));
}

bool BinaryTree::isSymmetric(TreeNode* root) {
    if(!root){
        return true;
    }
    return are_mirrors(root->left, root->right);
}

bool BinaryTree::isSymmetric_iterative(TreeNode* root) {
    queue<TreeNode*> q_left;
    queue<TreeNode*> q_right;
    if(!root){
        return true;
    }
    q_left.push(root->left);
    q_right.push(root->right);
    while(!q_left.empty() && !q_right.empty()){
        TreeNode* tempL = q_left.front();
        TreeNode* tempR = q_right.front();
        q_left.pop();
        q_right.pop();
        if(tempL && tempR){
            if(tempL->val!=tempR->val){
                return false;
            }
            q_left.push(tempL->left);
            q_left.push(tempL->right);
            q_right.push(tempR->right);
            q_right.push(tempR->left);
        }
        else if(!tempL && !tempR){
        }
        else{
            return false;
        }
    }
    if(q_left.empty() && q_right.empty()){
        return true;
    }
    return false;
}

bool BinaryTree::hasPathSum(TreeNode* root, int sum) {
    if(!root){
        return false;
    }
    if(sum==root->val && !root->left && !root->right){
        return true;
    }
    int rem = sum-root->val;
    return hasPathSum(root->left, rem) || hasPathSum(root->right, rem);
}

int BinaryTree::search(vector<int>& inorder, int start, int end, int val){
    int index;
    for (index=start; index<=end; ++index){
        if(inorder[index] == val){
            break;
        }
    }
    return index;
}

TreeNode* BinaryTree::buildTreeRec_in_post(vector<int>& inorder,
                                           vector<int>& postorder,
                                           int start, int end) {
    if(start>end){
        return nullptr;
    }
    TreeNode* node = new TreeNode(postorder.back());
    postorder.pop_back();
    if(start==end){
        return node;
    }
    // search node in inorder and set start end accordingly
    int index = search(inorder, start, end, node->val);
    node->right = buildTreeRec_in_post(inorder, postorder, index+1, end);
    node->left = buildTreeRec_in_post(inorder, postorder, start, index-1);
    return node;
}

TreeNode* BinaryTree::buildTree_in_post(vector<int>& inorder,
                                        vector<int>& postorder) {
    if(inorder.size()<=0 || postorder.size()<=0 ||
       inorder.size()!=postorder.size()){
        return nullptr;
    }
    return buildTreeRec_in_post(inorder, postorder, 0, inorder.size()-1);
}

TreeNode* BinaryTree::buildTreeRec_pre_in(vector<int>& preorder,
                                          vector<int>& inorder,
                                          int start, int end) {
    if(start>end){
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder.back());
    preorder.pop_back();
    if(start==end){
        return node;
    }
    int index = search(inorder, start, end, node->val);
    node->left = buildTreeRec_pre_in(preorder, inorder, start, index-1);
    node->right = buildTreeRec_pre_in(preorder, inorder, index+1, end);
    return node;
}

TreeNode* BinaryTree::buildTree_pre_in(vector<int>& preorder,
                                       vector<int>& inorder) {
    if(inorder.size() <= 0 ||
       preorder.size() <= 0 ||
       inorder.size() != preorder.size()){
        return nullptr;
    }
    vector<int> porder;
    for(int i=preorder.size()-1;i>=0;i--){
        porder.push_back(preorder[i]);
    }
    return buildTreeRec_pre_in(porder, inorder, 0, inorder.size()-1);
}

TreeNode* BinaryTree::findNextNode(TreeNode* root, int left=0){
    switch (left){
        case 0:
            if(root->left){
                return root->left;
            }
        case 1:
            if(root->right){
                return root->right;
            }
        case 2:
            if(root->next){
                return findNextNode(root->next);
            }
        default:
    }
    return nullptr;
}

// Populate each next pointer to point to its next right node.
// If there is no next right node, the next pointer should be set to NULL.
TreeNode* BinaryTree::connect(TreeNode* root) {
    if(!root){
        return nullptr;
    }
    if(root->right){
        root->right->next = findNextNode(root, 2);
        connect(root->right);
    }
    if(root->left){
        root->left->next = findNextNode(root, 1);
        connect(root->left);
    }
    return root;
}

bool BinaryTree::findPath(TreeNode* root,
                          TreeNode* target,
                          vector<TreeNode*>& path) {
    if(!root){
        return false;
    }
    if(root->val==target->val){
        path.push_back(root);
        return true;
    }
    if(root->left && findPath(root->left, target, path)){
        path.push_back(root);
        return true;
    }
    if(root->right && findPath(root->right, target, path)){
        path.push_back(root);
        return true;
    }
    return false;
}

TreeNode* BinaryTree::lowestCommonAncestor(TreeNode* root,
                                           TreeNode* p,
                                           TreeNode* q) {
    if(!root || !p || !q){
        return nullptr;
    }
    TreeNode* res = root;
    vector<TreeNode*> pathP, pathQ;
    findPath(root, p, pathP);
    findPath(root, q, pathQ);
    for(int i=pathP.size()-1, j=pathQ.size()-1; i>=0 && j>=0; --i, --j){
        if(pathP[i]->val==pathQ[j]->val)
            res = pathP[i];
        else
            break;
    }
    return res;
}

// Serialize a Binary Tree
string BinaryTree::serialize(TreeNode* root) {
    if(!root){
        return "";
    }
    string res;
    queue<TreeNode*> que;
    que.push(root);
    res+=to_string(root->val)+" ";
    while(!que.empty()){
        TreeNode* node = que.front();
        que.pop();
        if(node->left){
            que.push(node->left);
            res+=to_string(node->left->val)+" ";
        }
        else{
            res+="# ";
        }
        if(node->right){
            que.push(node->right);
            res+=to_string(node->right->val)+" ";
        }
        else{
            res+="# ";
        }
    }
    res+=";";
    return res;
}

// Deserialize a Binary Tree
TreeNode* BinaryTree::deserialize(string data) {
    if(data==""){
        return NULL;
    }
    queue<TreeNode*> que;
    stringstream ss{data};
    string num;
    ss>>num;
    TreeNode* root = new TreeNode(stoi(num));
    que.push(root);
    while(!que.empty() && ss>>num){
        TreeNode* node = que.front();
        que.pop();
        if(num=="#"){
            node->left = NULL;
        }
        else{
            node->left = new TreeNode(stoi(num));
            que.push(node->left);
        }
        ss>>num;
        if(num=="#"){
            node->right = NULL;
        }
        else{
            node->right = new TreeNode(stoi(num));
            que.push(node->right);
        }
    }
    return root;
}
