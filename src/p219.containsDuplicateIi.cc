/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    auto containsNearbyDuplicate(vector<int> const& nums, int k) -> bool {
        ++k;
        int size = nums.size();
        auto const min_k_size = min(k, size);
        unordered_set<int> window{};
        for (int i = 0; i < min_k_size; ++i) {
            auto [_, success] = window.insert(nums[i]);
            if (!success) {
                return true;
            }
        }
        for (int i = k; i < size; ++i) {
            window.erase(nums[i - k]);
            auto [_, success] = window.insert(nums[i]);
            if (!success) {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

#include <iostream>

auto main(int argc, char const* argv[]) -> int {
    Solution s;
    cout << s.containsNearbyDuplicate({1, 2, 3, 1}, 3) << endl;
    cout << s.containsNearbyDuplicate({1, 0, 1, 1}, 1) << endl;
    cout << s.containsNearbyDuplicate({1, 2, 3, 1, 2, 3}, 2) << endl;
    return 0;
}
