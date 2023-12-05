#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class TrafficLight {
public:
	sf::Color color;
	sf::Vector2f position;
	sf::CircleShape* circle;
	bool red;
	float timer;

	TrafficLight(sf::Vector2f position) {
		this->position = position;
		color = sf::Color::Red;
		red = true;
		timer = 0;
		circle = new sf::CircleShape();
	}

	void draw(sf::RenderWindow& window) {
		//box.setRotation(rotation);
		circle->setPosition(position);
		circle->setRadius(20);
		circle->setFillColor(color);
		window.draw(*circle);
	}

	bool isRed() const { return red; }

	void updateTraffic(float dt) {
		timer += dt;

		if (timer > 5) {
			color = sf::Color::Green;
			circle->setFillColor(sf::Color::Green);
			red = false;
		}
		else {
			color = sf::Color::Red;
			circle->setFillColor(sf::Color::Red);
			red = true;
		}

		if (timer > 10) {
			timer = 0;
		}
	}
};