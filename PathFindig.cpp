// PathFindig.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <locale>

#include "AStarAlgorithm.h"
#include "Teszt.h"

int main()
{
	setlocale(LC_ALL, "");

	int rows, cols, x1, y1, x2, y2;

	std::string line = "##########################################";

	std::cout << line << "\n A* útvonalkeresõ algoritmus vizualizáció\n" << line << std::endl;

	std::cout << "Kérem a mátrix sorait: ";
	std::cin >> rows;
	std::cout << "Kérem a mátrix oszlopait: ";
	std::cin >> cols;
	std::cout << "Kérem a kezdõpont x koordinátáját: ";
	std::cin >> x1;
	std::cout << "Kérem a kezdõpont y koordinátáját: ";
	std::cin >> y1;
	std::cout << "Kérem a végpont x koordinátáját: ";
	std::cin >> x2;
	std::cout << "Kérem a végpont y koordinátáját: ";
	std::cin >> y2;
	std::cout << std::endl;


	AStarAlgorithm algorithm(rows, cols, x1-1, y1-1, x2-1, y2-1);
	
	algorithm.draw();

	/*Teszt a;
	a.setVector(5, 5);
	a.getVector();*/
}