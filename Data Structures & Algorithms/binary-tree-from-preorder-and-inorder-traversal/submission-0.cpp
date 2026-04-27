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
    TreeNode* helper(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
        if(pl > pr || il > ir){
            return NULL;
        }
        int root_val = preorder[pl];
        TreeNode *root = new TreeNode(root_val);
        int root_idx = il;
        while(inorder[root_idx] != root_val){
            root_idx++;
        }
        int left_size = root_idx-il;
        root->left = helper(preorder, pl+1, pl+left_size, inorder, il, root_idx-1);
        root->right = helper(preorder, pl+left_size+1, pr, inorder, root_idx+1, ir);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};