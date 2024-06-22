#include "includes/command.h"

Command::Command(Command::Type command)
	: m_command{ command } 
{
}

Command::Command(char command)
{
	switch (command) {
	case 'w':	m_command = Up;			break;
	case 's':	m_command = Down;		break;
	case 'a':	m_command = Left;		break;
	case 'd':	m_command = Right;		break;
	case 'q':	m_command = Quit;		break;
	default:	m_command = MaxOptions;	break; // Use MaxOptions as error
	}
}

Command Command::operator-() {
	switch (m_command) {
	case Up:			return Command{ Down };
	case Down:			return Command{ Up };
	case Left:			return Command{ Right };
	case Right:			return Command{ Left };
	case MaxOptions:	return Command{ MaxOptions }; // Use MaxOptions as error
	}
	
	assert(0 && "Unsupported option was passed!");
	return Command{ Up };
}

std::ostream& operator<<(std::ostream& out, Command command) {
	out << Command::commandsArray[command.getCommand()];
	return out;
}