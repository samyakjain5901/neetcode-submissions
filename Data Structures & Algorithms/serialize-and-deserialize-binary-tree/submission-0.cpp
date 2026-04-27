/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    TreeNode *helper(vector<string> &tokens, int &idx){
        if(idx >= tokens.size()){
            return NULL;
        }
        if(tokens[idx] == "N"){
            idx++;
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(tokens[idx++]));
        root->left = helper(tokens, idx);
        root->right = helper(tokens, idx);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "N";
        }
        string preorder = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        return preorder;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        int idx = 0;
        return helper(tokens, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));