#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graph.hpp"
#include "Vehicle.hpp"
using namespace std;

int main() {
    Graph graph(4);
    graph.addVertex(1, sf::Vector2f(10, 10));
    graph.addVertex(2, sf::Vector2f(300, 10));
    graph.addVertex(3, sf::Vector2f(300, 300));
    graph.addVertex(4, sf::Vector2f(10, 300));

    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 1, 1);

    sf::RenderWindow window(sf::VideoMode(640, 640), "Traffic Simulator");
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //float dt = clock.restart().asSeconds();
        //vehicle1.update(dt);
        graph.draw(window);
        window.display();
    }

    return 0;
}

