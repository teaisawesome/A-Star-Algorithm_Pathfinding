#include "Spot.h"
#include "AStarAlgorithm.h"

Spot::Spot(const int& x, const int& y, const int& rows, const int& cols)
{
	this->x = x;
	this->y = y;
	this->ROWS = rows;
	this->COLS = cols;
}

bool Spot::operator==(const Spot& s) const
{
	if (x == s.x && y == s.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Spot::addNeighbours( std::vector<std::vector<Spot*>> matrix )
{
	int x = this->x;
	int y = this->y;

	if (x < this->ROWS - 1)
	{
		this->neighbours.push_back(matrix.at(x + 1).at(y));
	}
	if (x > 0)
	{
		this->neighbours.push_back(matrix.at(x - 1).at(y));
	}
	if (y < this->COLS - 1)
	{
		this->neighbours.push_back(matrix.at(x).at(y + 1));
	}
	if (y > 0)
	{
		this->neighbours.push_back(matrix.at(x).at(y - 1));
	}
}

Spot::~Spot() = default;