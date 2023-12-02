#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graph.hpp"
using namespace std;

class Vehicle {
public:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	float rotation;
	sf::RectangleShape shape;
	queue<int>& route;
	bool onScreen;
	/*int width;
	int height;*/
	// int a, b;

	Vehicle(Graph& graph, sf::Color color, queue<int>& route) : route(route) {
		onScreen = true;
		this->position = graph.vertices[route.front()];
		route.pop();
		this->color = color;

		// from is popped, to is in front
		this->velocity = calcVelocity(position, graph.vertices[route.front()]);

		shape.setSize(sf::Vector2f(30, 20));
		shape.setPosition(position);
		rotation = velocity.x ? 0.f : 90.f; // add more conditions
		rotation = velocity.y ? 90.f : 0.f;

		/*width = 30;
		height = 20;*/
		/*cout << "Closest vertex from " << from << " is " << to << endl;
		cout << "From: " << from << endl;
		cout << "To: " << to << endl;
		cout << "Position: (" << position.x << ", " << position.y << ")" << endl;
		cout << "Velocity: (" << velocity.x << ", " << velocity.y << ")" << endl << endl;*/

	}


	bool near(sf::Vector2f a, sf::Vector2f b) {
		float x = abs(b.x - a.x);
		float y = abs(b.y - a.y);
		return (x < 5.f && y < 5.f);
	}

	/*int getClosestVertex(Graph graph, int from) {
		ListNode<float>* ptr = graph.dijkstra(from);

		int i = 1;
		int closestVertex = 0;
		float leastCost = FLT_MAX;
		while (ptr != NULL) {
			if (i != from && ptr->data < leastCost) {
				closestVertex = i;
				leastCost = ptr->data;
			}
			ptr = ptr->next;
			i++;
		}

		return closestVertex;
	}*/

	sf::Vector2f calcVelocity(sf::Vector2f a, sf::Vector2f b) {
		sf::Vector2f vel = (b - a);
		float maxLimit = 200;

		/*if (abs(vel.x) < 10) vel.x = 0;
		if (abs(vel.y) < 10) vel.y = 0;*/

		if (vel.y == 0 && vel.x != 0) {
			if (vel.x > maxLimit) vel.x = maxLimit;
			else if (vel.x > 0 && vel.x < maxLimit) vel.x = maxLimit;
			else if (vel.x < 0 && vel.x > -maxLimit) vel.x = -maxLimit;
			else if (vel.x < -maxLimit) vel.x = -maxLimit;
		}
		else if (vel.x == 0 && vel.y != 0) {
			if (vel.y > maxLimit) vel.y = maxLimit;
			else if (vel.y > 0 && vel.y < maxLimit) vel.y = maxLimit;
			else if (vel.y < 0 && vel.y > -maxLimit) vel.y = -maxLimit;
			else if (vel.y < -maxLimit) vel.y = -maxLimit;
		}
		/*else {
			vel.x = 0;
			vel.y = 0;
		}*/

		return vel;
	}

	void print2f(sf::Vector2f v) {
		cout << '(' << v.x << ", " << v.y << ')' << endl;
	}

	void update(float dt, Graph graph) {
		cout << "Pos: ";
		print2f(position);
		if (!route.empty()) {
			cout << "To:  ";
			print2f(graph.vertices[route.front()]);
		}

		if (!route.empty() && near(position, graph.vertices[route.front()])) {
			cout << endl << "NEAR";

			int a = route.front(); // from
			route.pop();

			if (route.empty()) {
				velocity.x = velocity.y = 0;
				onScreen = false;
				return;
			}

			int b = route.front(); // to
			velocity = calcVelocity(graph.vertices[a], graph.vertices[b]);
			//rotation
			if (velocity.x > 0) rotation = 0.f;
			else if (velocity.x < 0) rotation = 180.f;
			else if (velocity.y > 0) rotation = 90.f;
			else if (velocity.y < 0) rotation = 270.f;
		}

		position += velocity * dt;
	}

	void draw(sf::RenderWindow& window) {
		shape.setRotation(rotation);
		shape.setPosition(position - sf::Vector2f(-30, -20));
		shape.setFillColor(color);
		window.draw(shape);
	}

};
