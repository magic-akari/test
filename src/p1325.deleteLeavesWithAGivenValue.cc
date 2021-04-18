/*
 * @lc app=leetcode id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
 */

#include "structs.hh"

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
    auto removeLeafNodes(TreeNode* root, int target) -> TreeNode* {
        if (root->left != nullptr) {
            root->left = removeLeafNodes(root->left, target);
        }
        if (root->right != nullptr) {
            root->right = removeLeafNodes(root->right, target);
        }

        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }

        return root;
    }
};
// @lc code=end

auto main(int argc, char const* argv[]) -> int {
    /* code */
    return 0;
}
