#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graph.hpp"
#include "Vehicle.hpp"
using namespace std;

int main() {
    Graph graph;
    graph.addVertex(1, sf::Vector2f(30, 30));
    graph.addVertex(2, sf::Vector2f(390, 30));
    graph.addVertex(3, sf::Vector2f(390, 390));
    graph.addVertex(4, sf::Vector2f(30, 390));
    graph.addVertex(5, sf::Vector2f(60, 60));
    graph.addVertex(6, sf::Vector2f(360, 60));
    graph.addVertex(7, sf::Vector2f(360, 360));
    graph.addVertex(8, sf::Vector2f(60, 360));
    
    graph.addEdge(5, 6, 1);
    graph.addEdge(6, 7, 1);
    graph.addEdge(7, 8, 1);
    graph.addEdge(8, 5, 1);

    graph.addEdge(4, 3, 1);
    graph.addEdge(3, 2, 1);
    graph.addEdge(2, 1, 1);
    graph.addEdge(1, 4, 1);
    
    Vehicle vehicles[] = { 
        Vehicle(graph, sf::Color::Green, 4, 1),
        Vehicle(graph, sf::Color::Red, 5, 8),
        Vehicle(graph, sf::Color::Blue, 3, 2)
    };
    int numVehicles = sizeof(vehicles) / sizeof(Vehicle);

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
        for (int i = 0; i < numVehicles; i++) {
            vehicles[i].update(dt, graph);
            vehicles[i].draw(window);

            for (int j = 0; j < numVehicles; j++) {
                if (i == j) continue;
                if (vehicles[i].shape.getGlobalBounds().intersects(vehicles[j].shape.getGlobalBounds())) {
                    cout << "Collision";
                    vehicles[i].velocity = sf::Vector2f(0,0);
                }
            }
        }
        
        window.display();
    }

    return 0;
}

