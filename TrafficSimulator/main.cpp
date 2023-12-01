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
    route1.push(7);
    route1.push(17);
    route1.push(19);
    route1.push(29);
    route1.push(31);
    route1.push(32);
    route1.push(35);
    route1.push(36);
    route1.push(34);
    route1.push(24);
    route1.push(23);
    route1.push(49);

    queue<int> route2;
    route2.push(1);
    route2.push(13);
    route2.push(15);
    route2.push(25);
    route2.push(27);
    route2.push(28);
    route2.push(31);
    route2.push(32);
    route2.push(30);
    route2.push(50);

    Vehicle vehicles[] = {
        Vehicle(graph, sf::Color::Cyan, route1),
        Vehicle(graph, sf::Color::Green, route2)

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

        // Drawing traffic lights
        /*
        for (int i = 0; i < 2; i++) {
            light[i].draw(window);
            for (int i = 1; i < 2; i++) {
                if (light[i].checkTraffic()) {
                    vehicles[i].velocity = sf::Vector2f(0, 0);

                }
            }
        }*/

        float dt = clock.restart().asSeconds();
        for (int i = 0; i < numVehicles; i++) {
            if (vehicles[i].onScreen) {
                vehicles[i].update(dt, graph);
                vehicles[i].draw(window);
            }



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