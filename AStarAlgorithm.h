#pragma once
#include <vector>
#include "Spot.h"

class AStarAlgorithm
{
private:

	int ROWS;
	int COLS;
	
	std::vector< std::vector<Spot*> > matrix;

	std::vector<Spot*> openSet;
	std::vector<Spot*> closedSet;

	Spot *start;
	Spot *end;

	std::vector<Spot*> path;

public:

	AStarAlgorithm(const int& rows, const int& cols, const int& x1, const int& y1, const int& x2, const int& y2);

	int heuristic(Spot *s, Spot *end);

	void draw();

	~AStarAlgorithm();
};

