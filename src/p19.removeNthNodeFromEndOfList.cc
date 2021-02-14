#include "structs.hh"

using namespace std;
/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    auto removeNthFromEnd(ListNode* head, int n) -> ListNode* {
        auto dummy = ListNode{0, head};
        auto* fast = head;
        auto* slow = &dummy;

        while (n-- > 0) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return dummy.next;
    }
};
// @lc code=end

#include <iostream>

auto main() -> int {
    Solution s;

    cout << s.removeNthFromEnd(new ListNode{1, 2, 3, 4, 5}, 2) << endl;
    cout << s.removeNthFromEnd(new ListNode{1, 2}, 1) << endl;
    cout << s.removeNthFromEnd(new ListNode{1, 2}, 2) << endl;
    cout << s.removeNthFromEnd(new ListNode{1}, 1) << endl;
    return 0;
}
