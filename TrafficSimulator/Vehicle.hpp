#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
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

	void update(float dt) {
		position += velocity * dt;
	}

	void draw(sf::RenderWindow& window) {
		sf::RectangleShape vehicleShape(sf::Vector2f(30, 20));
		vehicleShape.setPosition(position);
		vehicleShape.setFillColor(sf::Color::Blue);
		window.draw(vehicleShape);

	}

};
