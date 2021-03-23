/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
   public:
    auto judgeSquareSum(unsigned c) -> bool {
        if (c == 0) {
            return true;
        }
        unsigned left = 0;
        unsigned right = c / 2 + 1;

        for (unsigned d = c / right; right > d; d = c / right) {
            right += d;
            right /= 2;
        }

        while (left <= right) {
            unsigned left2 = left * left;
            unsigned right2 = right * right;
            unsigned sum = left2 + right2;

            if (sum == c) {
                return true;
            }

            unsigned mid = (left + right) / 2;
            unsigned mid2 = mid * mid;

            if (mid2 + right2 == c || left2 + mid2 == c) {
                return true;
            }

            if (sum < c) {
                if (mid2 + right2 < c) {
                    left = mid + 1;
                    continue;
                }

                ++left;
            } else {
                if (left2 + mid2 > c) {
                    right = mid - 1;
                    continue;
                }

                --right;
            }
        }

        return false;
    }
};
// @lc code=end

auto main(int argc, char const* argv[]) -> int {
    Solution s;
    cout << s.judgeSquareSum(0) << " 0 + 0 " << endl;
    cout << s.judgeSquareSum(1) << " 0 + 1 " << endl;
    cout << s.judgeSquareSum(2) << " 1 + 1 " << endl;
    cout << s.judgeSquareSum(3) << " " << endl;
    cout << s.judgeSquareSum(4) << " 0 + 4" << endl;
    cout << s.judgeSquareSum(5) << " 1 + 4" << endl;
    cout << s.judgeSquareSum(9) << " 0 + 9" << endl;
    cout << s.judgeSquareSum(1000000000) << " 1200**2 + 31600**2 " << endl;
    cout << s.judgeSquareSum(1U << 31U) << " 32768**2 + 32768**2 " << endl;
    cout << s.judgeSquareSum((1U << 31U) - 1U) << " " << endl;

    return 0;
}
