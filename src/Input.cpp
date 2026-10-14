#include "Input.h"

#include <iostream>

int validInput(int minVal, int maxVal) {
    int aVal;
    while (true) {
        std::cout << "Enter an option between " << minVal << " to " << maxVal << ": ";
        if (std::cin >> aVal && aVal >= minVal && aVal <= maxVal) {
            std::cin.ignore(1000, '\n');
            return aVal;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input, try again." << std::endl;
    }
}
