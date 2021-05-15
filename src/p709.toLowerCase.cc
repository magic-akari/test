/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
   public:
    auto toLowerCase(string str) -> string {
        for (auto&& i : str) {
            if ('A' <= i && i <= 'Z') {
                i -= 'A' - 'a';
            }
        }
        return str;
    }
};
// @lc code=end

#include <iostream>

auto main(int argc, char const* argv[]) -> int {
    Solution s;

    cout << s.toLowerCase("Hello") << endl;
    cout << s.toLowerCase("here") << endl;
    cout << s.toLowerCase("LOVELY") << endl;

    return 0;
}
