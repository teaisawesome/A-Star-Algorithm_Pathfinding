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

	// az aktu�lis spot szomsz�dai
	std::vector<Spot*> neighbours;

	// el�z� node a helyes �t rajzol�shoz
	Spot* previous = nullptr;

	// wall
	bool wall = false;

	// saj�t mez�, ami ahhoz kell, hogy megjelen�tsem, hogy openSet vagy closeSet
	char set = '_';

public:
	Spot() = default;
	
	Spot(const int& x, const int& y, const int& rows, const int& cols);

	// itt is lehet bug :D
	void addNeighbours( std::vector<std::vector<Spot*>> matrix );

	bool operator==(const Spot& s) const;

	~Spot();
};

