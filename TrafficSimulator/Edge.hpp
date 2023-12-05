#pragma once
#include <iostream>
#include "ListNode.hpp"
//#include "Vehicle.hpp"
#include "TrafficLight.hpp"
using namespace std;

struct Edge {
	int from;
	int to;
	sf::Vector2f fromPos;
	sf::Vector2f toPos;
	float cost;
	bool trafficSignal;
	TrafficLight* trafficLight;
	ListNode<int>* vehicles;

	Edge(int from, int to, sf::Vector2f fromPos, sf::Vector2f toPos, float cost, bool trafficSignal) : from(from), to(to), fromPos(fromPos), toPos(toPos), cost(cost) {
		vehicles = NULL;
		this->trafficSignal = trafficSignal;
		if (trafficSignal) {
			trafficLight = new TrafficLight(toPos);
		}
		else {
			trafficLight = NULL;
		}
	}
 
	//void pushVehicle(Vehicle& v) {
		//push(vehicles, v);
	//}

	void popFrontVehicle() {
		pop_front(vehicles);
	}

	void stopVehicles() {
		//ListNode<Vehicle>* ptr = vehicles;
		//while (ptr != NULL) {
			//ptr->data.velocity = sf::Vector2f(0, 0);
			//ptr = ptr->next;
		//}
	}
};