#pragma once
#include <iostream>
#include <map>
#include "Edge.hpp"
using namespace std;
#define INF INT_MAX

class Graph {
	map<int, ListNode<Edge>*> adjList;
	int V;

public:
	map<int, sf::Vector2f> vertices;
	Graph(int V) : V(V) {}

	void addVertex(int v, sf::Vector2f position) {
		vertices[v] = position;
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
			shape.setFillColor(sf::Color::Blue);
			window.draw(shape);
		}

		sf::Vertex line[] = {
			sf::Vertex(sf::Vector2f(0,0)),
			sf::Vertex(sf::Vector2f(300,300))
		};
	}


	void addEdge(int from, int to, double cost) {
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

	ListNode<int>* dijkstra(int start) {
		ListNode<int>* distances = new ListNode<int>(V, INF);

		return distances;
	}
};