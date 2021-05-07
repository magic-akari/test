/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    auto jump(vector<int> const& nums) -> int {
        int start = 0;
        int end = 1;
        int next_end = end;
        int size = nums.size();

        int step = 0;

        while (next_end < size) {
            for (int i = start; i < end; ++i) {
                next_end = max(next_end, i + nums[i] + 1);
            }
            step += 1;
            start = end;
            end = next_end;
        }

        return step;
    }
};
// @lc code=end

#include <iostream>

auto main(int argc, char const* argv[]) -> int {
    Solution s;
    cout << s.jump({2, 3, 1, 1, 4}) << endl;
    cout << s.jump({2, 3, 0, 1, 4}) << endl;
    cout << s.jump({1, 2, 3}) << endl;
    cout << s.jump({1, 2}) << endl;
    cout << s.jump({0}) << endl;
    return 0;
}
