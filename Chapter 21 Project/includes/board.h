#pragma once

#include "tile.h"
#include "command.h"
#include "point.h"

class Board {
private:
	int m_rowSize{ 4 };
	int m_colSize{ 4 };
	int m_highestTile{ m_rowSize * m_colSize - 1 };
	Tile** m_tiles = new Tile*[m_rowSize];

	void initialiseBoard();
	void populateBoard();
	void randomiseTiles();
	void assignPoints();
	Tile* findEmptyTilePtr();
	Tile* findTileByPointPtr(Point& point);

public:
	Board(); // default size of 4
	Board(int rowSize, int colSize);

	~Board();

	void moveTile(Command& command);
	bool hasWon();

	friend std::ostream& operator<<(std::ostream& out, Board& board);
};

std::ostream& operator<<(std::ostream& out, Board& board);