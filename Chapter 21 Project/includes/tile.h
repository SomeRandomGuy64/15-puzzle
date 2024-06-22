#pragma once

#include "point.h"

#include <iostream>

class Tile {
private:
	int m_number{ 0 };
	Point m_point{ 0, 0 };

public:
	Tile() = default;
	explicit Tile(int num);

	inline bool isEmpty() const { return m_number == 0; }

	inline int getNum() const { return m_number; }

	inline Point getPoint() const { return m_point; }
	inline void setPoint(Point point) { m_point = point; }

	friend std::ostream& operator<<(std::ostream&, const Tile& tile);
};

std::ostream& operator<<(std::ostream& out, const Tile& tile);