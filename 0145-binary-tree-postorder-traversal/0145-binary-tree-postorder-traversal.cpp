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
        dfs(node->left,  res);         // left
        dfs(node->right, res);         // right
        res.push_back(node->val);      // root
    }
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        dfs(root, result);
        return result;
    }
};