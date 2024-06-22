#include "includes/board.h"

#include <iostream>

constexpr auto TileNotFoundNullPtr{ nullptr };

// private

void Board::initialiseBoard() {
	for (int i{ 0 }; i < m_rowSize; ++i) {
		m_tiles[i] = new Tile[m_colSize];
	}
}

void Board::populateBoard() {
	int tileValue{ 1 };
	for (int yPosition{ 0 }; yPosition < m_colSize; ++yPosition) {
		for (int xPosition{ 0 }; xPosition < m_rowSize; ++xPosition) {

			if (tileValue < m_rowSize * m_colSize) {
				m_tiles[xPosition][yPosition] = Tile{ tileValue++ };
			}
			else {
				m_tiles[xPosition][yPosition] = Tile{ 0 };
			}
		}
	}
}

void Board::randomiseTiles() {
	int randomMoves{ m_rowSize * m_colSize * 50 };

	for (int i{ 0 }; i < randomMoves; ++i) {
		Command command{ Command::generateRandomDirection() };
		moveTile(command);
	}
}

void Board::assignPoints() {
	Point assignablePoint{ Point{ 0, 0 } };

	for (int xPosition{ 0 }; xPosition < m_rowSize; ++xPosition) {
		assignablePoint.setX(xPosition);

		for (int yPosition{ 0 }; yPosition < m_colSize; ++yPosition) {
			assignablePoint.setY(yPosition);

			m_tiles[xPosition][yPosition].setPoint(assignablePoint);
		}
	}
}

Tile* Board::findEmptyTilePtr() {
	for (int xPosition{ 0 }; xPosition < m_rowSize; ++xPosition) {
		for (int yPosition{ 0 }; yPosition < m_colSize; ++yPosition) {

			if (m_tiles[xPosition][yPosition].isEmpty()) {
				return &m_tiles[xPosition][yPosition];
			}
		}
	}

	assert(0 && "No empty tile found");
	return TileNotFoundNullPtr;
}

Tile* Board::findTileByPointPtr(Point& point) {
	for (int xPosition{ 0 }; xPosition < m_rowSize; ++xPosition) {
		for (int yPosition{ 0 }; yPosition < m_colSize; ++yPosition) {

			if (m_tiles[xPosition][yPosition].getPoint() == point)
				return &m_tiles[xPosition][yPosition];
		}
	}

	// If no tile with the given point is found a nullptr is returned, handle this
	return TileNotFoundNullPtr;
}

//public

Board::Board(int rowSize, int colSize)
	: m_rowSize{ rowSize }
	, m_colSize{ colSize }
	, m_highestTile{ rowSize * colSize - 1 }
{
	initialiseBoard();
	populateBoard();
	assignPoints();
	randomiseTiles();
}

Board::Board()
	: Board(4, 4)	// default size;
{
}

Board::~Board()
{
	for (int i{ 0 }; i < m_rowSize; ++i) {
		delete[] m_tiles[i];
	}

	delete[] m_tiles;
}

void Board::moveTile(Command& command) {
	Tile* emptyTile = findEmptyTilePtr();
	Point adjacentPoint{ emptyTile->getPoint().getAdjacentPoint(-command) };
	Tile* adjacentTile =  findTileByPointPtr(adjacentPoint);

	if (adjacentTile != TileNotFoundNullPtr) {
		Point emptyTilePoint{ emptyTile->getPoint() };
		adjacentTile->setPoint(emptyTilePoint);
		emptyTile->setPoint(adjacentPoint);
	}
}

bool Board::hasWon() {
	Point checkPoint{ 0, 0 };
	for (int xPosition{ 0 }; xPosition < m_rowSize; ++xPosition) {
		checkPoint.setX(xPosition);

		for (int yPosition{ 0 }; yPosition < m_colSize; ++yPosition) {
			checkPoint.setY(yPosition);

			if (checkPoint != m_tiles[xPosition][yPosition].getPoint()) {
				return false;
			}
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& out, Board& board) {
	std::cout << "\x1B[2J\x1B[H";	// ANSI escape code to clear the screen
	Point tempPoint{ 0, 0 };

	for (int yPosition{ 0 }; yPosition < board.m_colSize; ++yPosition) {
		for (int xPosition{ 0 }; xPosition < board.m_rowSize; ++xPosition) {
			tempPoint.setX(xPosition);
			tempPoint.setY(yPosition);
			out << *board.findTileByPointPtr(tempPoint);
		}
		out << '\n';
	}

	return out;
}