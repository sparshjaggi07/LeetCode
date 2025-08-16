/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void dfs(TreeNode* node, std::vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);      
        dfs(node->left,  res);         
        dfs(node->right, res);         
    }
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        dfs(root, result);
        return result;
    }
};