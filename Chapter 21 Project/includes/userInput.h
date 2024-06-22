#pragma once

#include <iostream>
#include "command.h"

namespace UserInput {
    void ignoreLine() {
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

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
        char input{};

        do {
            std::cin >> input;
            ignoreLine();

        } while (!isValidInput(input));

        return input;
    }

	Command getCommandFromUser() {
        return Command{ getCharacter() };
	}
}