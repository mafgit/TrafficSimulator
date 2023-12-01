#include <iostream>
#include <SFML/Graphics.hpp>
#include "AddVerticesAndEdges.hpp"
#include "Graph.hpp"
#include "Vehicle.hpp"

using namespace std;

int main() {
    Graph graph;
    AddVerticesAndEdges().add(graph);

    queue<int> route1;
    route1.push(5);
    route1.push(2);
    route1.push(1);
    route1.push(3);
    Vehicle vehicles[] = {
        Vehicle(graph, sf::Color::Red, route1)
        //Vehicle(graph, sf::Color::Green, {2,3,4,5}),

    };
    int numVehicles = sizeof(vehicles) / sizeof(Vehicle);

    TrafficLight light[] = {
        TrafficLight(graph, sf::Vector2f(280, 250)),
        TrafficLight(graph, sf::Vector2f(280, 330)),
        TrafficLight(graph, sf::Vector2f(310, 280)),
        TrafficLight(graph, sf::Vector2f(330, 310))
    };

    sf::RenderWindow window(sf::VideoMode(800, 800), "Traffic Simulator");
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

        for (int i = 0; i < 2; i++) {
            light[i].draw(window);
            for (int i = 1; i < 2; i++) {
                if (light[i].checkTraffic()) {
                    vehicles[i].velocity = sf::Vector2f(0, 0);

                }
            }
        }
        float dt = clock.restart().asSeconds();
        for (int i = 0; i < numVehicles; i++) {
            vehicles[i].update(dt, graph);
            vehicles[i].draw(window);



            //for (int j = 1; j < numVehicles; j++) {
            //    if (i == j) continue;
            //    if (vehicles[i].shape.getGlobalBounds().intersects(vehicles[j].shape.getGlobalBounds())) {
            //        cout << "Collision";
            //       
            //        /vehicles[j].velocity = sf::Vector2f(0, 0);/
            //        

            //        /*vehicles[i].update(0, graph);
            //        vehicles[i].draw(window);*/
            //    }
            //}
        }

        window.display();
    }

    return 0;
}