#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graph.hpp"
using namespace std;

class AddVerticesAndEdges {
public:
void add(Graph& graph) {
	graph.addVertex(1, sf::Vector2f(0, 0));
	graph.addVertex(2, sf::Vector2f(50, 0)); //1st corner
	graph.addVertex(3, sf::Vector2f(0, 50));
	graph.addVertex(4, sf::Vector2f(50, 50));

	graph.addVertex(5, sf::Vector2f(350, 0));
	graph.addVertex(6, sf::Vector2f(400, 0)); //2nd corner
	graph.addVertex(7, sf::Vector2f(350, 50));
	graph.addVertex(8, sf::Vector2f(400, 50));


	graph.addVertex(9, sf::Vector2f(700, 0));
	graph.addVertex(10, sf::Vector2f(750, 0)); //3rd corner   
	graph.addVertex(11, sf::Vector2f(700, 50));
	graph.addVertex(12, sf::Vector2f(750, 50));

	graph.addVertex(13, sf::Vector2f(0, 350));
	graph.addVertex(14, sf::Vector2f(50, 350)); //4th corner
	graph.addVertex(15, sf::Vector2f(0, 400));
	graph.addVertex(16, sf::Vector2f(50, 400));

	graph.addVertex(17, sf::Vector2f(350, 350));
	graph.addVertex(18, sf::Vector2f(400, 350)); //5th corner
	graph.addVertex(19, sf::Vector2f(350, 400));
	graph.addVertex(20, sf::Vector2f(400, 400));

	graph.addVertex(21, sf::Vector2f(700, 350));
	graph.addVertex(22, sf::Vector2f(750, 350));
	graph.addVertex(23, sf::Vector2f(700, 400)); //6th corner
	graph.addVertex(24, sf::Vector2f(750, 400));

	graph.addVertex(25, sf::Vector2f(0, 700));
	graph.addVertex(26, sf::Vector2f(50, 700)); //7th corner
	graph.addVertex(27, sf::Vector2f(0, 750));
	graph.addVertex(28, sf::Vector2f(50, 750));

	graph.addVertex(29, sf::Vector2f(350, 700));
	graph.addVertex(30, sf::Vector2f(400, 700)); //8th corner
	graph.addVertex(31, sf::Vector2f(350, 750));
	graph.addVertex(32, sf::Vector2f(400, 750));

	graph.addVertex(33, sf::Vector2f(700, 700));
	graph.addVertex(34, sf::Vector2f(750, 700)); //9th corner
	graph.addVertex(35, sf::Vector2f(700, 750));
	graph.addVertex(36, sf::Vector2f(750, 750));

	graph.addVertex(37, sf::Vector2f(100, 100)); //School
	graph.addVertex(38, sf::Vector2f(220, 100)); //park         1st corner
	graph.addVertex(39, sf::Vector2f(100, 200));   //Hospital 


	graph.addVertex(40, sf::Vector2f(450, 100)); //Mosque
	graph.addVertex(41, sf::Vector2f(560, 100)); //NADRA
	graph.addVertex(42, sf::Vector2f(450, 270));   //Shopping mall    2nd corner
	graph.addVertex(43, sf::Vector2f(560, 150)); //Apartments
	graph.addVertex(44, sf::Vector2f(650, 150));   //police Station

	graph.addVertex(45, sf::Vector2f(100, 450)); // Train Station
	graph.addVertex(46, sf::Vector2f(220, 450)); // Pool             3rd Corner
	graph.addVertex(47, sf::Vector2f(100, 600)); // University
	graph.addVertex(48, sf::Vector2f(220, 480)); // Park

	graph.addVertex(49, sf::Vector2f(450, 450));   // Airport
	graph.addVertex(50, sf::Vector2f(450, 630));   // Store          4th corner
	graph.addVertex(51, sf::Vector2f(510, 630));   // Mechanic
	graph.addVertex(52, sf::Vector2f(510, 665)); // Resturant




	graph.addEdge(9, 6, 1);  // R1 outer- left
	graph.addEdge(5, 1, 1);

	graph.addEdge(3, 13, 1);  // R2 outer - down
	graph.addEdge(15, 21, 1);

	graph.addEdge(28, 31, 1); // R3 outer -left
	graph.addEdge(32, 35, 1);

	graph.addEdge(34, 24, 1); // R4 outer -up
	graph.addEdge(22, 12, 1);

	graph.addEdge(15, 25, 1);

	//______inner______
	graph.addEdge(7, 17, 1, true);
	graph.addEdge(17, 14, 1);

	graph.addEdge(14, 4, 1);
	graph.addEdge(4, 7, 1);

	graph.addEdge(8, 11, 1);
	graph.addEdge(11, 21, 1);

	graph.addEdge(21, 18, 1, true);
	graph.addEdge(18, 8, 1);


	graph.addEdge(30, 20, 1, true);
	graph.addEdge(20, 23, 1);

	graph.addEdge(23, 33, 1);
	graph.addEdge(33, 30, 1);

	graph.addEdge(16, 19, 1, true);
	graph.addEdge(19, 29, 1);

	graph.addEdge(29, 26, 1);
	graph.addEdge(26, 16, 1);

	graph.addEdge(20, 23, 1);
	// ____1st corner_____
	graph.addEdge(2, 4, 1);
	graph.addEdge(2, 1, 1);
	graph.addEdge(1, 3, 1);
	graph.addEdge(4, 3, 1);

	// ____2nd corner_____
	graph.addEdge(6, 8, 1);
	graph.addEdge(6, 5, 1);
	graph.addEdge(5, 7, 1);


	graph.addEdge(8, 6, 1);
	graph.addEdge(6, 5, 1);
	graph.addEdge(8, 7, 1);


	graph.addEdge(7, 5, 1);
	graph.addEdge(7, 8, 1);

	// ____3rd corner_____
	graph.addEdge(11, 9, 1);
	graph.addEdge(12, 10, 1);
	graph.addEdge(10, 9, 1);

	graph.addEdge(12, 11, 1);

	// ____4th corner_____
	graph.addEdge(13, 14, 1);
	graph.addEdge(14, 13, 1);
	graph.addEdge(13, 15, 1);

	graph.addEdge(15, 16, 1);
	graph.addEdge(16, 15, 1);
	graph.addEdge(14, 16, 1);

	//____5th corner______
	graph.addEdge(17, 18, 1);
	graph.addEdge(18, 17, 1);

	graph.addEdge(18, 20, 1);
	graph.addEdge(20, 18, 1);

	graph.addEdge(19, 20, 1);
	graph.addEdge(20, 19, 1);

	graph.addEdge(17, 19, 1);
	graph.addEdge(19, 17, 1);



	// ____6th corner_____
	graph.addEdge(21, 22, 1);
	graph.addEdge(24, 22, 1);

	graph.addEdge(22, 21, 1);
	graph.addEdge(23, 24, 1);

	graph.addEdge(24, 23, 1);
	graph.addEdge(23, 21, 1);

	// ____7th corner_____
	graph.addEdge(25, 26, 1);
	graph.addEdge(25, 27, 1);

	graph.addEdge(27, 28, 1);
	graph.addEdge(26, 28, 1);

	// ____8th corner_____
	graph.addEdge(29, 30, 1);
	graph.addEdge(29, 31, 1);

	graph.addEdge(31, 29, 1);
	graph.addEdge(31, 32, 1);

	graph.addEdge(32, 30, 1);
	graph.addEdge(30, 32, 1);


	// ____9th corner_____
	graph.addEdge(33, 34, 1);
	graph.addEdge(35, 33, 1);

	graph.addEdge(35, 36, 1);
	graph.addEdge(36, 34, 1);
}
};