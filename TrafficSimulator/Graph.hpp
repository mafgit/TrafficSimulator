#pragma once
#include <iostream>
#include <map>
#include <queue>
#include "Edge.hpp"
using namespace std;
#define INF FLT_MAX

class Graph {
	int V;

public:
	map<int, ListNode<Edge>*> adjList;
	map<int, sf::Vector2f> vertices;
	ListNode<TrafficLight>* trafficLights;

	Graph() {
		V = 0;
	}


	void addVertex(int v, sf::Vector2f position) {
		vertices[v] = position;
		V++;
	}

	void draw(sf::RenderWindow& window) {
		int vertexcount = 0;
		// drawing vertices
		int flag = 0;
		for (auto i = vertices.begin(); i != vertices.end(); ++i) {
			if (i->first == 37) {
				sf::RectangleShape shape(sf::Vector2f(120, 120));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);


				//__TEXT___
				sf::Text text;

				sf::Font font;
				if (!font.loadFromFile("Arial.ttf"))
				{
					cout << "Can't load font";
				}

				text.setFont(font);
				text.setString("School");
				text.setCharacterSize(15); //15px
				text.setFillColor(sf::Color::Yellow);
				text.setStyle(sf::Text::Bold);
				text.setPosition(150, 120);



				window.draw(text);
			}
			else if (i->first == 38) {
				sf::RectangleShape shape(sf::Vector2f(130, 120));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);



				sf::Text text;

				sf::Font font;
				if (!font.loadFromFile("Arial.ttf"))
				{
					cout << "Can't load font";
				}

				text.setFont(font);
				text.setString("Park");
				text.setCharacterSize(15); //15px
				text.setFillColor(sf::Color::Yellow);
				text.setStyle(sf::Text::Bold);
				text.setPosition(240, 120);
				window.draw(text);
			}
			else if (i->first == 39) {
				sf::RectangleShape shape(sf::Vector2f(250, 150));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);

				sf::Text text;

				sf::Font font;
				if (!font.loadFromFile("Arial.ttf"))
				{
					cout << "Can't load font";
				}

				text.setFont(font);
				text.setString("Hospital");
				text.setCharacterSize(15); //15px
				text.setFillColor(sf::Color::Yellow);
				text.setStyle(sf::Text::Bold);
				text.setPosition(200, 240);

				window.draw(text);

			}
			else if (i->first == 40)
			{
				sf::RectangleShape shape(sf::Vector2f(110, 170));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);


				sf::Text text;

				sf::Font font;
				if (!font.loadFromFile("Arial.ttf"))
				{
					cout << "Can't load font";
				}

				text.setFont(font);
				text.setString("Mosque");
				text.setCharacterSize(15); //15px
				text.setFillColor(sf::Color::Yellow);
				text.setStyle(sf::Text::Bold);
				text.setPosition(470, 120);

				window.draw(text);



			}
			else if (i->first == 41)
			{
				sf::RectangleShape shape(sf::Vector2f(140, 50));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);


				sf::Text text;

				sf::Font font;
				if (!font.loadFromFile("Arial.ttf"))
				{
					cout << "Can't load font";
				}

				text.setFont(font);
				text.setString("Nadra");
				text.setCharacterSize(15); //15px
				text.setFillColor(sf::Color::Yellow);
				text.setStyle(sf::Text::Bold);
				text.setPosition(600, 120);

				window.draw(text);


			}
			else if (i->first == 42)
			{
				sf::RectangleShape shape(sf::Vector2f(110, 80));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);


				sf::Text text;

				sf::Font font;
				if (!font.loadFromFile("Arial.ttf"))
				{
					cout << "Can't load font";
				}

				text.setFont(font);
				text.setString("Mall");
				text.setCharacterSize(15); //15px
				text.setFillColor(sf::Color::Yellow);
				text.setStyle(sf::Text::Bold);
				text.setPosition(470, 300);

				window.draw(text);

			}
			else if (i->first == 43)
			{
				sf::RectangleShape shape(sf::Vector2f(90, 200));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);


				sf::Text text;

				sf::Font font;
				if (!font.loadFromFile("Arial.ttf"))
				{
					cout << "Can't load font";
				}

				text.setFont(font);
				text.setString("Flats");
				text.setCharacterSize(15); //15px
				text.setFillColor(sf::Color::Yellow);
				text.setStyle(sf::Text::Bold);
				text.setPosition(570, 300);

				window.draw(text);


			}
			else if (i->first == 44)
			{
				sf::RectangleShape shape(sf::Vector2f(50, 200));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);


				sf::Text text;

				sf::Font font;
				if (!font.loadFromFile("Arial.ttf"))
				{
					cout << "Can't load font";
				}

				text.setFont(font);
				text.setString("Hotel");
				text.setCharacterSize(15); //15px
				text.setFillColor(sf::Color::Yellow);
				text.setStyle(sf::Text::Bold);
				text.setPosition(650, 300);

				window.draw(text);


			}
			else if (i->first == 45)
			{
				sf::RectangleShape shape(sf::Vector2f(120, 150));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);

				sf::Text text;

				sf::Font font;
				if (!font.loadFromFile("Arial.ttf"))
				{
					cout << "Can't load font";
				}

				text.setFont(font);
				text.setString("Metro station");
				text.setCharacterSize(15); //15px
				text.setFillColor(sf::Color::Yellow);
				text.setStyle(sf::Text::Bold);
				text.setPosition(100, 500);

				window.draw(text);


			}
			else if (i->first == 46)
			{
				sf::RectangleShape shape(sf::Vector2f(130, 30));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);

				sf::Text text;

				sf::Font font;
				if (!font.loadFromFile("Arial.ttf"))
				{
					cout << "Can't load font";
				}

				text.setFont(font);
				text.setString("University");
				text.setCharacterSize(15); //15px
				text.setFillColor(sf::Color::Yellow);
				text.setStyle(sf::Text::Bold);
				text.setPosition(120, 720);

				window.draw(text);

			}
			else if (i->first == 47)
			{
				sf::RectangleShape shape(sf::Vector2f(120, 100));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);



			}
			else if (i->first == 48)
			{
				sf::RectangleShape shape(sf::Vector2f(130, 220));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);
			}
			else if (i->first == 49) {
				sf::RectangleShape shape(sf::Vector2f(250, 180));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);
			}
			else if (i->first == 50) {
				sf::RectangleShape shape(sf::Vector2f(60, 70));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);
			}
			else if (i->first == 51) {
				sf::RectangleShape shape(sf::Vector2f(190, 35));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);
			}
			else if (i->first == 52) {
				sf::RectangleShape shape(sf::Vector2f(190, 35));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineColor(sf::Color::Black);
				shape.setOutlineThickness(2);
				window.draw(shape);
			}
			else if (i->first < 37) {
				sf::RectangleShape shape(sf::Vector2f(50, 50));
				shape.setPosition(250, 0);
				shape.setPosition(i->second);
				shape.setFillColor(sf::Color::White);
				if (flag == 0) {
					flag = 1;
					continue;
				}
				if (flag == 1)
					window.draw(shape);
			}

		}



		//vertexcount++;

		// drawing edges
		bool flag1 = 0;
		for (auto i = adjList.begin(); i != adjList.end(); i++) {
			ListNode<Edge>* ptr = i->second;
			while (ptr != NULL) {
				sf::RectangleShape road;
				if (flag1 == 0) {
					flag1 = 1;
					continue;
				}
				else {
					road.setPosition(ptr->data.fromPos);
					sf::Vector2f size = ptr->data.toPos - ptr->data.fromPos;

					if (size.x < 50 && size.x > -50) {
						size.x = 50;
					}

					if (size.y < 50 && size.y > -50) {
						size.y = 50;
					}
					road.setSize(size);
					window.draw(road);
				}
				ptr = ptr->next;
			}
		}

		for (auto i = adjList.begin(); i != adjList.end(); i++) {
			ListNode<Edge>* ptr = i->second;

			if ((ptr->data).trafficSignal) {
				(ptr->data).trafficLight->draw(window);

			}
		}

		//sf::Vertex line[] = {
		//	sf::Vertex(sf::Vector2f(0,0)),
		//	sf::Vertex(sf::Vector2f(300,300))
		//};
	}


	void addEdge(int from, int to, float cost, bool trafficSignal = false) {
		//cout << "(" << vertices[to].x << ", ";
		//
		// 
		// 
		// 
		// 
		// 
		// 
		// 
		// 
		//  << vertices[to].y << ")\n";
		//cout << "(" << vertices[from].x << ", ";
		//cout << vertices[from].y << ")\n\n";
		push(adjList[from], Edge(from, to, vertices[from], vertices[to], cost, trafficSignal)); // edge added for from ---> to
		if (trafficSignal) {
			TrafficLight t(vertices[to]);
			push(trafficLights, t);
		}
	}

	double getCost(int from, int to) {
		ListNode<Edge>* ptr = adjList[from]; // ptr = head

		if (ptr == NULL)
			return -1;

		while (ptr->next != NULL) {
			if (ptr->data.to == to)
				return ptr->data.cost;
			ptr = ptr->next;
		}

		return -1;
	}

	//ListNode<float>* dijkstra(int start) {
	//	ListNode<float>* distances = new ListNode<float>(V, INF);

	//	// Priority queue to store nodes with their distances
	//	priority_queue<pair<int, float>, vector<pair<int, float>>, greater<pair<int, float>>> pq;

	//	// Set distance to the start node to 0
	//	ListNode<float>* ptr = distances;
	//	for (int i = 1; i < start; i++) {
	//		ptr = ptr->next;
	//	}
	//	ptr->data = 0;

	//	pq.push({ start, 0 });

	//	while (!pq.empty()) {
	//		int currentNode = pq.top().first;
	//		float currentDist = pq.top().second;
	//		pq.pop();

	//		// Iterate through neighbors of the current node
	//		ListNode<Edge>* ptr = adjList[currentNode];
	//		while (ptr != NULL) {
	//			float newDist = currentDist + ptr->data.cost;

	//			// If a shorter path is found, update the distance and push to the priority queue
	//			ListNode<float>* ptr2 = distances;
	//			for (int i = 1; i < ptr->data.to; i++) {
	//				ptr2 = ptr2->next;
	//			}

	//			if (newDist < ptr2->data) {
	//				ptr2->data = newDist;
	//				pq.push({ ptr->data.to, newDist });
	//			}

	//			ptr = ptr->next;
	//		}
	//	}

	//	return distances;
	//}

};