#pragma once

#include "command.h"

class Point {
public:
	Point(int x, int y);

	Point getAdjacentPoint(const Command& command);

	int getX() { return m_x; }
	int getY() { return m_y; }

	void setX(int x) { m_x = x; }
	void setY(int y) { m_y = y; }

	friend const bool operator==(Point p1, Point p2);
	friend const bool operator!=(Point p1, Point p2);

private:
	int m_x{ 0 };
	int m_y{ 0 };
};

bool const operator==(Point p1, Point p2);
bool const operator!=(Point p1, Point p2);