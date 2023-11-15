#pragma once
#include <iostream>
using namespace std;

template <typename T> struct ListNode {
	T data;
	ListNode* next;

	ListNode(T data) : data(data) {}
	ListNode(int size, T data) {
		this->data = data;
		ListNode<T>* ptr = this;

		for (int i = 2; i <= size; i++) {
			ptr->next = new ListNode(data);
			ptr = ptr->next;
		}
	}
};

template <typename T> void push(ListNode<T>* head, T data) {
	if (head == NULL) {
		head = new ListNode<T>(data);
		return;
	}

	ListNode<T>* ptr = head;

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	ptr->next = new ListNode<T>(data);
}