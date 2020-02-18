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

	std::cout << line << "\n A* �tvonalkeres� algoritmus vizualiz�ci�\n" << line << std::endl;

	std::cout << "K�rem a m�trix sorait: ";
	std::cin >> rows;
	std::cout << "K�rem a m�trix oszlopait: ";
	std::cin >> cols;
	std::cout << "K�rem a kezd�pont x koordin�t�j�t: ";
	std::cin >> x1;
	std::cout << "K�rem a kezd�pont y koordin�t�j�t: ";
	std::cin >> y1;
	std::cout << "K�rem a v�gpont x koordin�t�j�t: ";
	std::cin >> x2;
	std::cout << "K�rem a v�gpont y koordin�t�j�t: ";
	std::cin >> y2;
	std::cout << std::endl;


	AStarAlgorithm algorithm(rows, cols, x1-1, y1-1, x2-1, y2-1);
	
	algorithm.draw();

	/*Teszt a;
	a.setVector(5, 5);
	a.getVector();*/
}