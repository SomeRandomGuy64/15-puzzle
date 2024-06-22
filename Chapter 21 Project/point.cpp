#include "includes/point.h"

#include <cassert>

Point::Point(int x, int y)
	: m_x{ x }
	, m_y{ y }
{
}

Point Point::getAdjacentPoint(const Command& command) {
	switch (command.getCommand()) {
	case Command::Up:			return Point(m_x, --m_y);
	case Command::Down:			return Point(m_x, ++m_y);
	case Command::Left:			return Point(--m_x, m_y);
	case Command::Right:		return Point(++m_x, m_y);
	case Command::MaxOptions:	return *this;
	}

	assert(0 && "Unsupported option was passed!");
	return *this;
}

bool const operator==(Point p1, Point p2) {
	return (p1.m_x == p2.m_x) && (p1.m_y == p2.m_y);
}

bool const operator!=(Point p1, Point p2) {
	return !(p1 == p2);
}