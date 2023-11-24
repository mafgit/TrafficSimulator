#pragma once
#include <iostream>
#include <map>
#include <queue>
#include "Edge.hpp"
using namespace std;
#define INF FLT_MAX

class Graph {
	map<int, ListNode<Edge>*> adjList;
	int V;

public:
	map<int, sf::Vector2f> vertices;
	Graph() {
		V = 0;
	}

	void addVertex(int v, sf::Vector2f position) {
		vertices[v] = position;
		V++;
	}

	void draw(sf::RenderWindow& window) {

		// drawing lines
		for (auto i = adjList.begin(); i != adjList.end(); i++) {
			ListNode<Edge>* ptr = i->second;
			while (ptr != NULL) {
				sf::RectangleShape road;
				road.setPosition(ptr->data.fromPos);
				sf::Vector2f size = ptr->data.toPos - ptr->data.fromPos;

				if (size.x < 50 && size.x > -50) {
					size.x = 50;
				}

				if (size.y < 50 && size.y > -50) {
					size.y = 50;
				}
				road.setSize(size);
				window.draw(road);
				ptr = ptr->next;
			}
		}

		// drawing vertices
		for (auto i = vertices.begin(); i != vertices.end(); i++) {
			sf::RectangleShape shape(sf::Vector2f(50, 50));
			shape.setPosition(i->second);
			shape.setFillColor(sf::Color::White);
			window.draw(shape);
		}


		//sf::Vertex line[] = {
		//	sf::Vertex(sf::Vector2f(0,0)),
		//	sf::Vertex(sf::Vector2f(300,300))
		//};
	}


	void addEdge(int from, int to, float cost) {
		//cout << "(" << vertices[to].x << ", ";
		//cout << vertices[to].y << ")\n";
		//cout << "(" << vertices[from].x << ", ";
		//cout << vertices[from].y << ")\n\n";
		push(adjList[from], Edge(from, to, vertices[from], vertices[to], cost)); // edge added for from ---> to
	}

	double getCost(int from, int to) {
		ListNode<Edge>* ptr = adjList[from]; // ptr = head

		if (ptr == NULL)
			return -1;

		while (ptr->next != NULL) {
			if (ptr->data.to == to)
				return ptr->data.cost;
			ptr = ptr->next;
		}

		return -1;
	}

	ListNode<float>* dijkstra(int start) {
		ListNode<float>* distances = new ListNode<float>(V, INF);

		// Priority queue to store nodes with their distances
		priority_queue<pair<int, float>, vector<pair<int, float>>, greater<pair<int, float>>> pq;

		// Set distance to the start node to 0
		ListNode<float>* ptr = distances;
		for (int i = 1; i < start; i++) {
			ptr = ptr->next;
		}
		ptr->data = 0;

		pq.push({ start, 0 });

		while (!pq.empty()) {
			int currentNode = pq.top().first;
			float currentDist = pq.top().second;
			pq.pop();

			// Iterate through neighbors of the current node
			ListNode<Edge>* ptr = adjList[currentNode];
			while (ptr != NULL) {
				float newDist = currentDist + ptr->data.cost;

				// If a shorter path is found, update the distance and push to the priority queue
				ListNode<float>* ptr2 = distances;
				for (int i = 1; i < ptr->data.to; i++) {
					ptr2 = ptr2->next;
				}

				if (newDist < ptr2->data) {
					ptr2->data = newDist;
					pq.push({ ptr->data.to, newDist });
				}

				ptr = ptr->next;
			}
		}

		return distances;
	}

};