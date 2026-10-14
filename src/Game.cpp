#include "Game.h"

#include <iostream>
#include <string>

#include "Input.h"
#include "Patient.h"
#include "PatientFactory.h"

void mainMenu() {
    std::cout << "Menu Options" << std::endl;
    std::cout << "[1] Admit new patient" << std::endl;
    std::cout << "[2] Load previous patient" << std::endl;
    std::cout << "[3] Save current patient" << std::endl;
    std::cout << "[4] Administer treatment" << std::endl;
    std::cout << "[5] Show patient's status" << std::endl;
    std::cout << "[6] Quit game" << std::endl;
    std::cout << std::endl;
}

Patient* newPatient() {
    std::cout << "Choose between these patients" << std::endl;
    std::cout << "Patient #1" << std::endl;
    std::cout << "Patient #2" << std::endl;
    std::cout << "Patient #3" << std::endl;

    int admit = validInput(1, 3);

    std::string name;
    std::cout << "Record your patient's name: " << std::endl;
    std::getline(std::cin, name);

    static const char* const types[] = {"PatientOne", "PatientTwo", "PatientThree"};
    return createPatient(types[admit - 1], name);
}

void treatment(Patient* patient) {
    std::cout << "1 to prescribe PPIs, 2 not to" << std::endl;
    if (validInput(1, 2) == 1) {
        patient->take_PPI();
    } else {
        patient->no_PPI();
    }

    std::cout << "1 to prescribe diltiazem, 2 not to" << std::endl;
    if (validInput(1, 2) == 1) {
        patient->take_dil();
    } else {
        patient->no_dil();
    }

    std::cout << "1 to recommend a restricted lifestyle, 2 to allow a normal lifestyle" << std::endl;
    if (validInput(1, 2) == 1) {
        patient->live_bland();
    } else {
        patient->live_live();
    }

    patient->next_Year();
    patient->lowLevels();
}
