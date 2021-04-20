/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution {
   public:
    auto rangeBitwiseAnd(int left, int right) -> int {
        int i = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            i += 1;
        }

        return left << i;
    }
};
// @lc code=end

#include <iostream>

using namespace std;

auto naiveRangeBitwiseAnd(int left, int right) -> int {
    unsigned result = left;

    for (unsigned i = left; i <= right; ++i) {
        result &= i;
    }

    return (int)result;
}

#include <cassert>
#include <iostream>

using namespace std;

auto main(int argc, char const* argv[]) -> int {
    Solution s;

    for (int i = 1; i < 20; ++i) {
        for (int j = i; j < 20; ++j) {
            assert(s.rangeBitwiseAnd(i, j) == naiveRangeBitwiseAnd(i, j));
        }
    }

    return 0;
}
