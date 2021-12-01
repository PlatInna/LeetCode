#pragma once

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
// Return the linked list sorted as well.

//Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

ListNode* deleteDuplicates(ListNode* head) {
    auto temp_head = head;
    while(temp_head->next != nullptr) {
        if (temp_head->next->val == temp_head->val) {
            auto node_to_delete = temp_head->next;
            temp_head->next = temp_head->next->next; 
            delete(node_to_delete);
        }
        else {
            temp_head = temp_head->next;
        }
    }
    return head;
}