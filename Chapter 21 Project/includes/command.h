#pragma once

#include "random.h"
#include <cassert>
#include <array>
#include <iostream>
#include <string>

class Command {
public:
	enum Type {
		Up,
		Down,
		Left,
		Right,
		Quit,
		MaxOptions,
	};

	static inline std::array<std::string, MaxOptions> commandsArray{
		"Up",
		"Down",
		"Left",
		"Right",
		"Quit",
	};

	static_assert(std::ssize(commandsArray) == MaxOptions);

	Command() = default;
	Command(Command::Type command);
	Command(char command);

	Command::Type getCommand() const { return m_command; }

	Command operator-();
	friend std::ostream& operator<<(std::ostream& out, Command command);

	static inline Command generateRandomDirection() {
		Command::Type randomDirection{ static_cast<Command::Type>(Random::get(0, Command::MaxOptions - 2)) };
		// MaxOptions - 2 makes it so that MaxOptions and Quit aren't included, only the directions
		return Command{ randomDirection };
	}

private:
	Command::Type m_command{ Command::Quit };

};

std::ostream& operator<<(std::ostream& out, Command command);