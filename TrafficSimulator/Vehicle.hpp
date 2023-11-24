#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graph.hpp"
using namespace std;

class Vehicle {
public:
	int destination;
	int from, to;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	int rotation;
	sf::RectangleShape shape;
	/*int width;
	int height;*/
	// int a, b;

	Vehicle(Graph& graph, sf::Color color, int from, int destination)  {
		this->position = graph.vertices[from];
		this->color = color;
		this->from = from;
		this->destination = destination;
		
		
		this->to = getClosestVertex(graph, from);
		this->velocity = calcVelocity(position, graph.vertices[to]);
		
		shape.setSize(sf::Vector2f(30, 20));
		shape.setPosition(position);
		rotation = velocity.x ? 0 : 90;
		/*width = 30;
		height = 20;*/
		//cout << "Closest vertex from " << from << " is " << to << endl;
		/*cout << "From: " << from << endl;
		cout << "To: " << to << endl;
		cout << "Position: (" << position.x << ", " << position.y << ")" << endl;
		cout << "Velocity: (" << velocity.x << ", " << velocity.y << ")" << endl << endl;
		*/
	}

	bool near(sf::Vector2f a, sf::Vector2f b) {
		float x = abs(b.x - a.x);
		float y = abs(b.y - a.y);
		return (x < 5.0 && y < 5.0);
	}

	int getClosestVertex(Graph graph, int from) {
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
	}

	sf::Vector2f calcVelocity(sf::Vector2f a, sf::Vector2f b) {
		sf::Vector2f vel = b - a;
		vel.x /= 3;
		vel.y /= 3;
		return vel;
	}

	void update(float dt, Graph graph) {
		//cout << position.x << "," << position.y << "  " << graph.vertices[to].x << "," << graph.vertices[to].y << endl;
		if (near(position, graph.vertices[to])) {
			rotation = (rotation == 90 ? 0 : 90);
			if (to == destination) {
				from = destination;
				to = destination;
				velocity = sf::Vector2f(0, 0);
				//position = sf::Vector2f(-100, -100);
				rotation = 0;
			}
			else {
				from = to;
				to = getClosestVertex(graph, to);
				velocity = calcVelocity(position, graph.vertices[to]);
			}



		}
		else {
			position += velocity * dt;
			//cout << "Velocity: (" << velocity.x << ", " << velocity.y << ")" << endl;
		}


	}

	void draw(sf::RenderWindow& window) {
		shape.setRotation(rotation);
		shape.setPosition(position - sf::Vector2f(20, 20));
		shape.setFillColor(color);
		window.draw(shape);
	}

};
