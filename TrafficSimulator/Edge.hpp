#pragma once
#include <iostream>
#include "ListNode.hpp"
using namespace std;

struct Edge {
	int from;
	int to;
	sf::Vector2f fromPos;
	sf::Vector2f toPos;
	float cost;
	//ListNode<Vehicle>* vehicles;

	Edge(int from, int to, sf::Vector2f fromPos, sf::Vector2f toPos, float cost) : from(from), to(to), fromPos(fromPos), toPos(toPos), cost(cost) {
		//vehicles = NULL;
	}
};