#include "includes/tile.h"

Tile::Tile(int num)
	: m_number{ num }
{

}

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
	if (tile.getNum() > 99) {		// 3 digit number
		out << " " << tile.getNum() << " ";
	}
	else if (tile.getNum() > 9) {	// 2 digit number
		out << "  " << tile.getNum() << " ";
	}
	else if (tile.getNum() > 0) {	// 1 digit number
		out << "   " << tile.getNum() << " ";
	}
	else if (tile.isEmpty()) {
		out << "     ";
	}

	return out;
}