// Chapter 21 Project

// Step 1

// A)
// Board Things:
//	Display the game board
//	Display an individual tile
//	Randomise starting state
//	Numbers should move
//	Display lose or win state

// User Things:
//	Get commands from the user
//	Handle invalid input
//	Quit game


// B)

// class Board
//	Top Level Implementation
//		Display the game board
//		Randomise starting state
//		Slide tiles
//		Determine win condition
//	Members
//		Tile array, 2D

// class Tile
//	Top Level Implementation
//		Display Individual tiles
//	Members
//		Number

// class Point
//	Top Level Implementation
//		Indexing the game board tiles
//	Members
//		int x coordinate
//		int y coordinate

// class Direction
//	Top Level Implementation
//		Make working with directional commands easier and more intuitive
//	Members
//		enum directions

// namespace UserInput
//	Top Level Implementation
//		Get Input from user
//		Handle invalid input
//	Members
//		None

// function main
//	Top Level Implementation
//		Main game loop
//		Should handle quitting the game
//	Members
//		None

#include "includes/board.h"
#include "includes/userInput.h"
#include "includes/command.h"
#include "includes/point.h"
#include <iostream>
#include <string_view>
#include <limits>

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction() { // Check for failed extraction
    if (!std::cin) {    // If the previous extraction failed
        if (std::cin.eof()) { // If the stream was closed
            exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

int getSize(std::string_view type) {
    int size{};

    while (true) {
        std::cout << "Enter the size of the " << type << " you want: ";
        std::cin >> size;

        if (!std::cin) {
            std::cout << "Invalid Input, try again\n";
            ignoreLine();
            clearFailedExtraction();
            continue;
        }

        if (size <= 1) {
            std::cout << "Number must be greater than 1, try again\n";
            ignoreLine();
            clearFailedExtraction();
            continue;
        }

        break;
    }
    return size;
}

int getRowSize() {
    return getSize("row");
}

int getColSize() {
    return getSize("column");
}

char getConfirmation() {
    // Ask for confirmation, if input is invalid just assume the user pressed 'n'
    std::cout << "\nAre you sure you want to quit? (y/n): ";
    char confirmation{};
    std::cin >> confirmation;

    if (confirmation != 'y' && confirmation != 'n') {
        ignoreLine();
        clearFailedExtraction();
        confirmation = 'n';
    }

    return confirmation;
}

int main() {
    Board board{ getRowSize(), getColSize() };

    while (true) {
        std::cout << board;

        if (board.hasWon()) {
            std::cout << "\n\nYou won!\n\n";
            break;
        }

        Command input{ UserInput::getCommandFromUser() };
        char confirmation{ getConfirmation() };

        if (input.getCommand() == Command::Quit && confirmation == 'y') {
            std::cout << "\n\n\nBye!\n\n\n";
            break;
        }
        else if (input.getCommand() == Command::Quit && confirmation == 'n') {
            continue;
        }
        else {
            board.moveTile(input);
        }
    }

    return 0;
}