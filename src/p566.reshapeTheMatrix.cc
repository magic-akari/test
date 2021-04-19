/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    auto matrixReshape(vector<vector<int>> const& nums, int r, int c) -> vector<vector<int>> {
        auto const row = nums.size();
        auto const column = nums[0].size();
        if (r * c != row * column) {
            return nums;
        }

        if (r == row && c == column) {
            return nums;
        }

        vector<vector<int>> result(r, vector<int>(c, 0));

        for (size_t i = 0; i < r; ++i) {
            for (size_t j = 0; j < c; ++j) {
                auto const index = i * c + j;
                auto const o_r = index / column;
                auto const o_c = index % column;

                result[i][j] = nums[o_r][o_c];
            }
        }

        return result;
    }
};
// @lc code=end

#include <iostream>
#include "vectorfmt.hh"

auto main(int argc, char const* argv[]) -> int {
    Solution s;

    cout << s.matrixReshape({{1, 2, 3, 4}}, 2, 2) << endl;
    cout << s.matrixReshape({{1, 2, 3, 4}}, 5, 5) << endl;
    cout << s.matrixReshape({{1, 2}, {3, 4}}, 1, 4) << endl;
    cout << s.matrixReshape({{1, 2}, {3, 4}}, 4, 1) << endl;
    return 0;
}
