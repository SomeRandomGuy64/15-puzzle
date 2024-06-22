#pragma once

#include <iostream>
#include <conio.h>
#include "command.h"

namespace UserInput {
    bool isValidInput(char input) {
        return(
            input == 'w' ||
            input == 'a' ||
            input == 's' ||
            input == 'd' ||
            input == 'q'
            );
    }

    char getCharacter() {
        return static_cast<char>(_getch());
    }

	Command getCommandFromUser() {
        return Command{ getCharacter() };
	}
}