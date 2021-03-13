#include <array>
#include <bitset>
#include <string>
#include <string_view>

using namespace std;
/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
   public:
    auto minWindow(string const& s, string_view t) -> string {
        size_t const s_size = s.size();
        size_t const t_size = t.size();

        if (s_size == 0 || t_size == 0 || s_size < t_size) {
            return "";
        }

        array<int, 128> t_count{};
        bitset<128> flag{};

        for (auto const& i : t) {
            ++t_count[i];
            flag[i] = true;
        }

        // distance 为 0 的时候代表满足条件
        int distance = t_size;

        size_t min_left = 0;
        size_t min_size = s_size + 1;

        // [left, right)
        for (size_t left = 0, right = 0; right < s_size; ++right) {
            auto const right_char = s[right];
            if (!flag[right_char]) {
                continue;
            }

            if (t_count[right_char] > 0) {
                --distance;
            }
            --t_count[right_char];

            for (; distance == 0; ++left) {
                // 右指针在外层循环结束时才移动，这里提前 +1
                size_t size = (right + 1) - left;
                if (size < min_size) {
                    min_size = size;
                    min_left = left;
                }

                auto const left_char = s[left];
                if (!flag[left_char]) {
                    continue;
                }

                if (t_count[left_char] == 0) {
                    ++distance;
                }
                ++t_count[left_char];
            }
        }

        return min_size > s_size ? "" : s.substr(min_left, min_size);
    }
};
// @lc code=end

#include <iostream>

auto main() -> int {
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << s.minWindow("a", "a") << endl;
    return 0;
}
