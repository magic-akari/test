/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

#include <queue>
#include <vector>
#include "structs.hh"

using namespace std;

// @lc code=start
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
   public:
    auto levelOrder(TreeNode* root) -> vector<vector<int>> {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q_a{};
        queue<TreeNode*> q_b{};

        q_a.push(root);

        vector<vector<int>> result{};
        vector<int> layer{};

        while (!q_a.empty()) {
            while (!q_a.empty()) {
                auto* const node = q_a.front();
                layer.push_back(node->val);
                if (node->left != nullptr) {
                    q_b.push(node->left);
                }
                if (node->right != nullptr) {
                    q_b.push(node->right);
                }
                q_a.pop();
            }
            if (!layer.empty()) {
                result.push_back(layer);
                layer.clear();
            }
            swap(q_a, q_b);
        }

        return result;
    }
};
// @lc code=end

auto main(int argc, char const* argv[]) -> int {
    /* code */
    return 0;
}
