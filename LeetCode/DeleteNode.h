#pragma once

//Write a function to delete a node in a singly - linked list.You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.
//It is guaranteed that the node to be deleted is not a tail node in the list.

// tricky problem, actually it is not deleted node 

void deleteNode(ListNode* node) {

	node->val = node->next->val;
	node->next = node->next->next;
	//node->val = node->next->val; 
}

// or actually delete next node after copied its data to cur node
void deleteNode_1(ListNode* node) {
	ListNode* tmp = node->next;
	*node = *tmp;
	delete tmp;
}