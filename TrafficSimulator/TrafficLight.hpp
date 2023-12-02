#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class TrafficLight {
public:
	sf::Color color;
	sf::Vector2f position;
	sf::RectangleShape box;
	bool red;
	float timer;

	TrafficLight(sf::Vector2f position) {
		this->position = position;
		color = sf::Color::Red;
		box.setFillColor(color);
		red = true;
		timer = 0;
	}

	void draw(sf::RenderWindow& window) {
		//box.setRotation(rotation);
		box.setSize(sf::Vector2f(30, 20));
		box.setPosition(position);
		window.draw(box);
	}

	bool isRed() const { return red; }

	void updateTraffic(float dt) {
		timer += dt;

		if (timer > 5) {
			box.setFillColor(sf::Color::Green);
			red = false;
		}
		else {
			box.setFillColor(sf::Color::Red);
			red = true;
		}

		if (timer >= 10) {
			timer = 0;
		}
	}
};