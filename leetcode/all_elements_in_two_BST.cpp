/*
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.
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
    vector<int> merge(vector<int>& l1, vector<int>& l2){
        vector<int> res(l1.size()+l2.size());
        int i=0,j=0,k=0;
        int s1=l1.size(), s2=l2.size();
        while(j<s1 & k<s2){
            if(l1[j]<l2[k]){
                res[i] = l1[j];
                j++;
            }
            else{
                res[i] = l2[k];
                k++;
            }
            i++;
        }
        while(j<s1){
            res[i] = l1[j];
            i++; j++;
        }
        while(k<s2){
            res[i] = l2[k];
            i++; k++;
        }
        return res;
    }

    void inOrderTrav(TreeNode* root, vector<int>& l){
        if(!root) return;
        inOrderTrav(root->left, l);
        l.push_back(root->val);
        inOrderTrav(root->right, l);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        inOrderTrav(root1, l1);
        inOrderTrav(root2, l2);
        return merge(l1, l2);
    }
};
