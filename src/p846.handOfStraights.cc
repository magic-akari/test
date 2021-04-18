/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    auto isNStraightHand(vector<int>& hand, int W) -> bool {
        int const size = hand.size();

        if (size % W != 0) {
            return false;
        }

        sort(begin(hand), end(hand));

        map<int, int> record{};
        for (auto&& i : hand) {
            record[i] += 1;
        }

        auto const loop = size / W;

        for (int i = 0; i < loop; ++i) {
            auto const start = begin(record)->first;

            for (int j = 0; j < W; ++j) {
                auto const key = start + j;

                if (record.find(key) == end(record)) {
                    return false;
                }

                record[key] -= 1;

                if (record[key] == 0) {
                    record.erase(key);
                }
            }
        }

        return true;
    }
};
// @lc code=end

auto main(int argc, char const* argv[]) -> int {
    /* code */

    Solution s;
    vector<int> h{1, 2, 3, 6, 2, 3, 4, 7, 8};
    cout << s.isNStraightHand(h, 3) << endl;

    vector<int> h2{1, 2, 3, 6, 2, 3, 4, 7, 9};
    cout << s.isNStraightHand(h2, 3) << endl;

    return 0;
}
