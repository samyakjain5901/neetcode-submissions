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
    int goodNodes_helper(TreeNode* root, int X){
        if(!root){
            return 0;
        }
        int cnt = 0;
        if(root->val >= X){
            cnt++;
            X = root->val;
        }
        cnt += goodNodes_helper(root->left, X);
        cnt += goodNodes_helper(root->right, X);
        return cnt;
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        return goodNodes_helper(root, root->val);
    }
};