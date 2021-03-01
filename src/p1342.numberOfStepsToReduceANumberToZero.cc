/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution {
   public:
    auto numberOfSteps(int num) -> int {
        auto result = 0;
        while (num > 0) {
            if ((num & 1) != 0) {
                ++result;
                num -= 1;
            } else {
                num >>= 1;
                ++result;
            }
        }
        return result;
    }
};
// @lc code=end

#include <iostream>

using namespace std;

auto main(int argc, char const* argv[]) -> int {
    Solution s;

    cout << s.numberOfSteps(14) << "==" << 6 << endl;
    cout << s.numberOfSteps(8) << "==" << 4 << endl;
    cout << s.numberOfSteps(123) << "==" << 12 << endl;

    return 0;
}
