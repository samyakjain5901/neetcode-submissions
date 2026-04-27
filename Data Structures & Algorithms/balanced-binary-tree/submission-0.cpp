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
    int maxDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        int left_d = maxDepth(root->left);
        int right_d = maxDepth(root->right);
        return 1 + max(left_d, right_d);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        bool is_left_bal = isBalanced(root->left);
        bool is_right_bal = isBalanced(root->right);
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        bool is_root_bal = abs(left_depth - right_depth) <= 1;
        return is_left_bal && is_right_bal && is_root_bal;
    }
};