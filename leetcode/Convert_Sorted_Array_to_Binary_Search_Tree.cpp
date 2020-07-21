/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    TreeNode* sAToBST(vector<int>& nums, int l, int r) {
        if(l==r) return NULL;
        int n = l + (r-l)/2;
        TreeNode* head = new TreeNode(nums[n]);
        head->left = sAToBST(nums, l, n);
        head->right = sAToBST(nums, n+1, r);
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n<=0) return NULL;
        return sAToBST(nums, 0, n);
    }
};
