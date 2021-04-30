/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

#include <array>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    inline static string const base64abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";

    // generated from base64abc
    inline static array<unsigned, 123> const base64code = {
        255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        255, 255, 255, 62,  255, 255, 52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  255, 255, 255, 255, 255,
        255, 255, 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,  15,  16,  17,  18,
        19,  20,  21,  22,  23,  24,  25,  255, 255, 255, 255, 63,  255, 26,  27,  28,  29,  30,  31,  32,  33,
        34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,
    };

    auto encodeRbase64(unsigned input) -> string {
        string output;
        do {
            output += base64abc[input & 0b111111U];
            input >>= 6U;
        } while (input != 0);

        return output;
    }

    auto decodeRbase64(const string& input) -> unsigned {
        unsigned output = 0;
        for (auto i = rbegin(input); i != rend(input); ++i) {
            output <<= 6U;
            output += base64code[*i];
        }

        return output;
    }

    unordered_map<string, unsigned> record_map{};
    vector<string> record_vec{};

   public:
    // Encodes a URL to a shortened URL.
    auto encode(const string& longUrl) -> string {
        auto result = record_map.find(longUrl);
        if (result != end(record_map)) {
            return encodeRbase64(result->second);
        }

        auto const size = record_map.size();

        record_map.emplace(longUrl, size);
        record_vec.push_back(longUrl);

        return encodeRbase64(size);
    }

    // Decodes a shortened URL to its original URL.
    auto decode(const string& shortUrl) -> string {
        auto const key = decodeRbase64(shortUrl);

        return record_vec[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

#include <iostream>

auto main(int argc, char const* argv[]) -> int {
    Solution s;

    cout << s.encode("https://leetcode.com/problems/design-tinyurl") << endl;
    cout << s.decode("A") << endl;

    return 0;
}
