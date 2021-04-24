/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    auto hIndex(vector<int> const& citations) -> int {
        int const size = citations.size();
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int value = citations[mid];
            int target = size - mid;
            if (value == target) {
                return value;
            }
            if (value < target) {
                left = mid + 1;
                continue;
            }
            right = mid - 1;
        }

        return size - left;
    }
};
// @lc code=end

#include <iostream>

auto main(int argc, char const* argv[]) -> int {
    Solution s;
    cout << s.hIndex({0, 1, 3, 5, 6, 7}) << endl;
    cout << s.hIndex({0, 1, 4, 5, 6, 7}) << endl;
    cout << s.hIndex({0, 1, 3, 5, 7}) << endl;
    cout << s.hIndex({0, 1, 3, 5, 6}) << endl;
    cout << s.hIndex({1, 2, 100}) << endl;
    cout << s.hIndex({1, 100}) << endl;
    cout << s.hIndex({1}) << endl;
    cout << s.hIndex({0}) << endl;
    return 0;
}
