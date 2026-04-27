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
    int helper(TreeNode *root, int &global_max){
        if(!root){
            return 0;
        }
        int left = max(0, helper(root->left,  global_max));
        int right = max(0, helper(root->right, global_max));
        global_max = max(global_max, root->val + left + right);
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int global_max = INT_MIN;
        helper(root, global_max);
        return global_max;
    }
};