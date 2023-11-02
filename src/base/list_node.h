// @author: gezhipeng @ 20231102
// @file: list_node.h
// @brief: list_node
#include <iostream>
#include <vector>
struct ListNode {
    ListNode(int v) {
        val = v;
    }
    int val = 0;
    ListNode* next = nullptr;
}

ListNode* SetListNode(std::vector<int> nums) {
    ListNode* head = new ListNode(0);
    auto p = head;
    for (size_t i = 0; i < nums.size(); ++i) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head->next;
}

void Print(ListNode* head) {
    auto p = head;
    while (p) {
        std:cout << p->val << "->";
    }
    std::cout << "null" << std::endl
}