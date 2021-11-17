#pragma once

//Given the head of a singly linked list, return the middle node of the linked list.
//If there are two middle nodes, return the second middle node.

void recursiveCount(ListNode* head, int& size) {
	if (head->next) {
		recursiveCount(head->next, ++size);
	}
	else {
		++size;
	}
}

ListNode* middleNode(ListNode* head) {
	int item_pos = 0;
	int list_size = 0;
	recursiveCount(head, list_size);
	while (item_pos != list_size / 2) {
		head = head->next;
		++item_pos;
	}
	return head;
}

ListNode* middleNode_1(ListNode* head) {
	int item_pos = 0;
	int list_size = 0;
	ListNode* first_head = head;
	while (head) {
		head = head->next;
		++list_size;
	}
	head = first_head;
	while (item_pos != list_size / 2) {
		head = head->next;
		++item_pos;
	}
	return head;
}

ListNode* middleNode_2(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != nullptr and fast != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}