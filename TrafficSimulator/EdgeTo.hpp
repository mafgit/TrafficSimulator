#include <iostream>
#pragma once
#include "ListNode.hpp"
#include "Vehicle.hpp"
using namespace std;

struct EdgeTo {
	int destination;
	double cost;
	ListNode<Vehicle>* vehicles;

	EdgeTo(int destination, double cost) : destination(destination), cost(cost) {
		vehicles = NULL;
	}
};