#pragma once
#include <iostream>
#include <map>
#include "EdgeTo.hpp"
using namespace std;
#define INF INT_MAX

class Graph {
	map<int, ListNode<EdgeTo>*> adjList;
	// int:   list:
	// 	1:	 { {2, 2.5}, {3, 1.5}, {4, 2.3} }
	// 	2:   { {3, 2.5}, {4, 5}, {1, 3} }
	// 	3:  ...
	// 	4:  ...
	int V;

public:
	Graph(int V) : V(V) {}

	void addEdge(int from, int to, double cost) {
		push(adjList[from], EdgeTo(to, cost)); // edge added for from ---> to
	}

	double getCost(int from, int to) {
		ListNode<EdgeTo>* ptr = adjList[from]; // ptr = head

		if (ptr == NULL)
			return -1;

		while (ptr->next != NULL) {
			if (ptr->data.destination == to)
				return ptr->data.cost;
			ptr = ptr->next;
		}

		return -1;
	}

	ListNode<int>* dijkstra(int start) {
		ListNode<int>* distances = new ListNode<int>(V, INF);

		return distances;
	}
};