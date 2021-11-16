#pragma once

#include<iostream>
#include<vector>
#include<cmath>

//Given head which is a reference node to a singly - linked list.The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
//Return the decimal value of the number in the linked list.

//Definition for singly - linked list
struct ListNode {
	int val;
	ListNode* next;
	ListNode* head;
	ListNode() : val(0), next(nullptr), head(nullptr) {}
	//ListNode(int x) : val(x), next(nullptr) {}
	//ListNode(int x, ListNode* next) : val(x), next(next) {}
	
	void PushFront(int value) {
		ListNode* new_node = new ListNode;
		new_node->next = head;
		new_node->val = value;
		head = new_node;
	}

	~ListNode() {
		while (head != nullptr) {
			ListNode* next_head = head->next;
			head->next = nullptr; 
			delete head;
			head = next_head;
		}
	}
};

/* recursive approach:  
   recursion is used to find the size of a list and to calculate the power of two for each element in the list and then to
   summarize the result from LSB to MSB
   -------------------------
   |  1  |  0  |  1  |  1  |
   -------------------------
     MSB  <==========  LSB
   result = (2^0 * 1) + (2^1 * 1) + (2^2 * 0) + (2^3 * 1) = 11
*/

void recursiveSum(ListNode* list_head, int& result, int item_number, int& list_size) {
	if (list_head->next) {
		recursiveSum(list_head->next, result, ++item_number, ++list_size);
	}
	else {
		++item_number;
		++list_size;
	}

	if (list_head->val) {
		int power_of_two = list_size - item_number;
		result += std::pow(2, power_of_two);
	}
}

int getDecimalValue(ListNode* head) {
	int res = 0;
	int item_num = -1;
	int size = -1;
	recursiveSum(head, res, item_num, size);
	return res;
}

// iterative approache: summarizing from LSB to MSB ------- hmmmm???? need to reverse the list


/* Two iterative and two more recursive approaches use summarizing from MSB to LSB (doubling method). The difference is just that we use different operators to multiply by two : bitwise left shift << and ordinary multiplicator *

    ------------------------- 
    |  1  |  0  |  1  |  1  |
    -------------------------
      MSB  ==========>  LSB

    result = result << 1 | value = 11

	result = result * 2 + value = 11
*/

int getDecimalValue_1(ListNode* head) {
	int res = 0;
	while (head) {
		res <<= 1;
		res |= head->val;
		head = head->next;
	}
	return res;
}

int getDecimalValue_2(ListNode* head) {
	int res = 0;
	while (head) {
		res *= 2;
		res += head->val;
		head = head->next;
	}
	return res;
}

int getDecimalValue_3(ListNode* head, int res = 0) {
	return head ? getDecimalValue_3(head->next, res * 2 + head->val) : res;
}

int getDecimalValue_4(ListNode* head, int res = 0) {
	return head ? getDecimalValue_3(head->next, res << 1 | head->val) : res;
}


// use vector instead of list
int getDecimalValue(std::vector<bool> v) {
	int res = 0;
	int n = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		//if (v[i]) res += std::pow(2, n);
		//n++;
		if (v[i]) res += std::pow(2, v.size() - 1 - i);
	}
	return res;
}

