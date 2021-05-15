/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    auto thirdMax(vector<int>& nums) -> int {
        auto first = INT64_MIN;
        auto second = INT64_MIN;
        auto third = INT64_MIN;

        for (decltype(first)&& i : nums) {
            if (i == first || i == second || i == third) {
                continue;
            }
            if (i > first) {
                swap(i, first);
            }
            if (i > second) {
                swap(i, second);
            }
            if (i > third) {
                swap(i, third);
            }
        }

        return static_cast<int>(third == INT64_MIN ? first : third);
    }
};
// @lc code=end

#include <iostream>

auto main(int argc, char const* argv[]) -> int {
    Solution s;

    auto* a = new vector<int>{3, 2, 1};

    cout << s.thirdMax(*a) << endl;

    auto* b = new vector<int>{1, 2};

    cout << s.thirdMax(*b) << endl;

    auto* c = new vector<int>{2, 2, 3, 1};

    cout << s.thirdMax(*c) << endl;

    return 0;
}
