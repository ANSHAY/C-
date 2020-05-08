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
    int dx = 0;
    int dy = 0;
    int px, py;
    bool fx = false, fy = false;
    bool depth(TreeNode* root, int x, int y, int p, int d){
        if(!root) return false;
        if(!fx && (root->val == x)){
            dx = d;
            px = p;
            fx = true;
        }
        if(!fy && (root->val == y)){
            dy = d;
            py = p;
            fy = true;
        }
        if(fx && fy) return true;
        return depth(root->left, x, y, root->val, d+1) || depth(root->right, x, y, root->val, d+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(depth(root, x, y, -1, 0)){
            return dx==dy && px!=py;
        }
        else return false;
    }
};
/* testcases
[1,2,3,4]
4
3
[3,4]
4
3
[1,2,5,4,7,8,9,6,23,58,52,3,74]
4
3
[1,2,3,4,5,6,7,8,9]
2
3
[1,2,3,4,5,6,7,8,9]
4
5
[1,2,3,4,5,6,7,8,9]
8
9
[1,2,3,4,5,6,7,8,9]
6
7
[1,2,3,4,5,6,7,8,9]
4
6
[1,2,3,4,5,6,7,8,9]
5
7
[1,2,3,4,5,6,7,8,9]
4
7
[1,2,3,4,5,6,7,8,9]
2
1
[1,2,3,4,5,6,7,8,9]
2
9
*/
