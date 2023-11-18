#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graph.hpp"
#include "Vehicle.hpp"
using namespace std;

int main() {
    Graph graph;
    graph.addVertex(1, sf::Vector2f(10, 10));
    graph.addVertex(2, sf::Vector2f(300, 10));
    graph.addVertex(3, sf::Vector2f(300, 300));
    graph.addVertex(4, sf::Vector2f(10, 300));
    graph.addVertex(5, sf::Vector2f(300, 600));
    
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 1, 1);
    graph.addEdge(5, 3, 1);

    Vehicle vehicle1(graph, sf::Color::Green, sf::Vector2f(10,10), 1, 4);

    ListNode<float>* distances = graph.dijkstra(2);
    ListNode<float>* ptr = distances;
    while (ptr != NULL) {
        //cout << ptr->data << endl;
        ptr = ptr->next;
    }
    
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

        window.clear();
        graph.draw(window);

        float dt = clock.restart().asSeconds();
        vehicle1.update(dt, graph);
        vehicle1.draw(window);
        
        window.display();
    }

    return 0;
}

