class Solution {
    int helper(TreeNode *root, int &max_len){
        if(!root) return 0;
        int left = helper(root->left, max_len);
        int right = helper(root->right, max_len);
        max_len = max(max_len, left+right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_len = 0;
        helper(root, max_len);
        return max_len;
    }
};