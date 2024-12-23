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
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int operations = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            vector<int> sorted_level = level;
            sort(sorted_level.begin(), sorted_level.end());
            vector<int> index_map(size);
            for (int i = 0; i < size; ++i) {
                index_map[i] = find(sorted_level.begin(), sorted_level.end(), level[i]) - sorted_level.begin();
            }

            vector<bool> visited(size, false);
            for (int i = 0; i < size; ++i) {
                if (visited[i] || index_map[i] == i) continue;
                int cycle_size = 0;
                int x = i;
                while (!visited[x]) {
                    visited[x] = true;
                    x = index_map[x];
                    ++cycle_size;
                }
                operations += cycle_size - 1;
            }
        }
        return operations;
    }
};
