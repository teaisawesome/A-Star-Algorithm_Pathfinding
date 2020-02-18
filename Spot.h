#pragma once
#include <vector>
#include <iostream>

class Spot
{

public:

	int x;
	int y;

	// max rows, cols
	int ROWS;
	int COLS;
	
	// f(n) = g(h) + h(n)
	int f = 0;
	int g = 0;
	int h = 0;

	// az aktuális spot szomszédai
	std::vector<Spot*> neighbours;

	// elõzõ node a helyes út rajzoláshoz
	Spot* previous = nullptr;

	// wall
	bool wall = false;

	// saját mezõ, ami ahhoz kell, hogy megjelenítsem, hogy openSet vagy closeSet
	char set = '_';

public:
	Spot() = default;
	
	Spot(const int& x, const int& y, const int& rows, const int& cols);

	// itt is lehet bug :D
	void addNeighbours( std::vector<std::vector<Spot*>> matrix );

	bool operator==(const Spot& s) const;

	~Spot();
};

