/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
   public:
    auto inline strictValidPalindrome(string const& s, size_t left, size_t right) -> bool {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }

    auto validPalindrome(string const& s) -> bool {
        size_t left = 0;
        size_t right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return strictValidPalindrome(s, left, right - 1) || strictValidPalindrome(s, left + 1, right);
            }

            ++left;
            --right;
        }

        return true;
    }
};
// @lc code=end

#include <iostream>

auto main(int argc, char const* argv[]) -> int {
    Solution s;
    cout << s.validPalindrome("aba") << endl;
    cout << s.validPalindrome("abababbababa") << endl;
    cout << s.validPalindrome("ababbabbababa") << endl;
    cout << s.validPalindrome("ababaabbababa") << endl;
    cout << s.validPalindrome("mlcupuufxoohddhooxfuupuculm") << endl;

    return 0;
}
