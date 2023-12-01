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
	queue<int> route;
	/*int width;
	int height;*/
	// int a, b;

	Vehicle(Graph& graph, sf::Color color, queue<int> route) {
		this->position = graph.vertices[route.front()];
		route.pop();
		this->color = color;

		// from is popped, to is in front
		this->velocity = calcVelocity(position, graph.vertices[route.front()]);

		shape.setSize(sf::Vector2f(30, 20));
		shape.setPosition(position);
		rotation = velocity.x ? 0 : 90; // add more conditions
		rotation = velocity.y ? 90 : 0;

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
		return (x < 50.0 && y < 50.0);
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
		vel.x /= 2;
		vel.y /= 2;
		return vel;
	}

	void update(float dt, Graph graph) {
		//cout << position.x << "," << position.y << "  " << graph.vertices[to].x << "," << graph.vertices[to].y << endl;
		if (!route.empty() && near(position, graph.vertices[route.front()])) {
			cout << "NEAR";
			rotation = (rotation == 90 ? 0 : 90);

			int a = route.front();
			route.pop();
			
			if (route.empty()) {
				velocity.x = velocity.y = 0;
				return;
			}

			int b = route.front();
			velocity = calcVelocity(graph.vertices[a], graph.vertices[b]);
		}

		position += velocity * dt;
		//cout << "Velocity: (" << velocity.x << ", " << velocity.y << ")" << endl;
	}

	void draw(sf::RenderWindow& window) {
		shape.setRotation(rotation);
		shape.setPosition(position - sf::Vector2f(-30, -20));
		shape.setFillColor(color);
		window.draw(shape);
	}

};

class TrafficLight {
public:
	sf::Color color;
	sf::Vector2f position;
	sf::RectangleShape box;

	TrafficLight(Graph& graph, sf::Vector2f position) {

		this->position = position;

	}
	void draw(sf::RenderWindow& window) {
		//box.setRotation(rotation);
		box.setSize(sf::Vector2f(30, 20));
		box.setPosition(position);

		window.draw(box);
	}
	bool checkTraffic() {
		// add funtionality
		int flag = 0;
		while (1) {
			if (flag == 0) {

				box.setFillColor(sf::Color::Red);
				sf::sleep(sf::seconds(0.2f));
				box.setFillColor(sf::Color::Green);
				flag = 1;
				return 0;
				continue;

			}
			else {

				box.setFillColor(sf::Color::Green);
				sf::sleep(sf::seconds(0.2f));
				box.setFillColor(sf::Color::Red);
				flag = 0;
				return 1;
				continue;
			}
		}

	}
};