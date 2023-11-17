#pragma once
#include <iostream>
#include "ListNode.hpp"
#include "Vehicle.hpp"
using namespace std;

struct Edge {
	int from;
	int to;
	sf::Vector2f fromPos;
	sf::Vector2f toPos;
	double cost;
	//ListNode<Vehicle>* vehicles;

	Edge(int from, int to, sf::Vector2f fromPos, sf::Vector2f toPos, double cost) : from(from), to(to), fromPos(fromPos), toPos(toPos), cost(cost) {
		//vehicles = NULL;
	}
};