#ifndef LEETCODE_STRUCTS_HH
#define LEETCODE_STRUCTS_HH

#include <array>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val{0};
    ListNode* next{nullptr};
    ListNode() = default;
    explicit ListNode(int x) : val(x) {}

    ListNode(std::initializer_list<int> const array) {
        auto* p = this;

        for (auto&& i : array) {
            p->val = i;
            if (&i != std::prev(end(array))) {
                p = p->next = new ListNode();
            }
        }
    }
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

auto isSameList(ListNode* p, ListNode* q) -> bool {
    if (p == nullptr || q == nullptr) {
        return p == q;
    }

    return p->val == q->val && isSameList(p->next, q->next);
}

auto operator<<(std::ostream& out, ListNode const* head) -> std::ostream& {
    for (auto const* p = head; p != nullptr; p = p->next) {
        out << p->val << " -> ";
    }
    out << "nullptr";
    return out;
}

struct TreeNode {
    int val{0};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};
    TreeNode()  {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

#endif
