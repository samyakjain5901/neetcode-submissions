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
    bool areIdentical(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot){
            return true;
        }
        if(!root || !subRoot){
            return false;
        }
        if(root->val != subRoot->val){
            return false;
        }
        return areIdentical(root->left, subRoot->left) && areIdentical(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot){
            return true;
        }
        if(!root || !subRoot){
            return false;
        }
        bool present_left = isSubtree(root->left, subRoot);
        bool present_right = isSubtree(root->right, subRoot);
        bool present_root = areIdentical(root, subRoot);
        return present_left || present_right || present_root;
    }
};