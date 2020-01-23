#pragma once
#include <vector>

class Spot
{
public:

	int x;
	int y;
	
	// f(n) = g(h) + h(n)
	int f = 0;
	int g = 0;
	int h = 0;

	// az aktu�lis spot szomsz�dai
	std::vector<Spot*> neighbours;

	// el�z� node a helyes �t rajzol�shoz
	Spot* previous = nullptr;

	// saj�t mez�, ami ahhoz kell, hogy megjelen�tsem, hogy openSet vagy closeSet
	char set = '_';

public:
	Spot() = default;

	Spot(const int& x, const int& y);

	// itt is lehet bug :D
	void addNeighbours(Spot* matrix[25][25]);

	bool operator==(const Spot& s) const;

	~Spot();
};

