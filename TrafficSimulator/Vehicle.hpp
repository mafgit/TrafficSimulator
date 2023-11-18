#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graph.hpp"
using namespace std;

class Vehicle {
public:
	int from, to;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	// int a, b;

	Vehicle(sf::Color color, sf::Vector2f position, sf::Vector2f velocity, int from, int to) {
		this->position = position;
		this->color = color;
		this->velocity = velocity;
		this->from = from;
		this->to = to;
	}

	bool near(sf::Vector2f a, sf::Vector2f b) {
		float x = abs(b.x - a.x);
		float y = abs(b.y - a.y);
		return (x < 5.0 && y < 5.0);
	}

	void update(float dt, map<int, sf::Vector2f> vertices) {
		cout << position.x << "," << position.y << "  " << vertices[to].x << "," << vertices[to].y << endl;
		if (!near(position, vertices[to])) {
			position += velocity * dt;
		}
		else {
			velocity = sf::Vector2f(0, 0);
		}
	}

	void draw(sf::RenderWindow& window) {
		sf::RectangleShape vehicleShape(sf::Vector2f(30, 20));
		vehicleShape.setPosition(position);
		vehicleShape.setFillColor(sf::Color::Green);
		window.draw(vehicleShape);

	}

};
