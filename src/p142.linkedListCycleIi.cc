#include "structs.hh"

using namespace std;

/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    auto detectCycle(ListNode* head) -> ListNode* {
        auto* fast = head;
        auto* slow = head;

        do {
            if (fast == nullptr || fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);

        fast = head;

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};
// @lc code=end

auto main(int argc, char const* argv[]) -> int {
    /* code */
    return 0;
}
