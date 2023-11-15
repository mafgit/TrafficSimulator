#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graph.hpp"

using namespace std;

int main() {
	Graph network(6);
	network.addEdge(1, 2, 4);
	network.addEdge(1, 5, 4);
	network.addEdge(1, 6, 4);
	network.addEdge(2, 3, 4);
	network.addEdge(3, 4, 4);
	network.addEdge(4, 6, 4);
	network.addEdge(5, 4, 4);
	network.addEdge(6, 5, 4);

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}