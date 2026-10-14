#include <iostream>
#include <string>

#include "Game.h"
#include "Input.h"
#include "Patient.h"
#include "SaveLoad.h"

int main() {
    Patient* currentPat = nullptr;
    bool running = true;

    std::string player;
    std::cout << "Enter your name" << std::endl;
    std::cin >> player;
    std::cout << "Welcome to Trial & Error Hospital, Dr. " << player << std::endl;
    std::cout << std::endl;

    while (running) {
        mainMenu();
        int option = validInput(1, 6);

        if (option == 1) {
            delete currentPat;
            currentPat = newPatient();
            currentPat->printStats();
            std::cout << std::endl;
        } else if (option == 2) {
            delete currentPat;
            currentPat = loadPatient();
            if (currentPat != nullptr) {
                currentPat->printStats();
            }
            std::cout << std::endl;
        } else if (option == 3) {
            saveToFile(currentPat);
            std::cout << std::endl;
        } else if (option == 4) {
            if (currentPat != nullptr) {
                treatment(currentPat);
                if (currentPat->gameIsOver()) {
                    delete currentPat;
                    currentPat = nullptr;
                }
            } else {
                std::cout << "No patients currently" << std::endl;
            }
            std::cout << std::endl;
        } else if (option == 5) {
            if (currentPat != nullptr) {
                currentPat->printStats();
            } else {
                std::cout << "No patients currently" << std::endl;
            }
            std::cout << std::endl;
        } else if (option == 6) {
            running = false;
        }
    }

    delete currentPat;
    std::cout << "Goodbye, Dr. " << player << std::endl;
    return 0;
}
