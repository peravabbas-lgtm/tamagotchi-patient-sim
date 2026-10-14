#include "SaveLoad.h"

#include <fstream>
#include <iostream>
#include <string>

#include "Patient.h"
#include "PatientFactory.h"

void saveToFile(const Patient* patient) {
    if (patient == 0) {
        std::cout << "No existing patient" << std::endl;
        return;
    }

    std::string filename;
    std::cout << "Enter the save file's name: ";
    std::getline(std::cin, filename);

    std::ofstream out(filename.c_str());
    if (!out.is_open()) {
        std::cout << "File not open" << std::endl;
        return;
    }

    out << patient->getType() << std::endl;
    patient->saveGame(out);
    std::cout << "Patient saved to " << filename << std::endl;
}

Patient* loadPatient() {
    std::string filename;
    std::cout << "Enter filename to load from: ";
    std::getline(std::cin, filename);

    std::ifstream in(filename.c_str());
    if (!in.is_open()) {
        std::cout << "File not open" << std::endl;
        return 0;
    }

    std::string type;
    std::getline(in, type);

    Patient* patient = createPatient(type, "");
    if (patient == 0) {
        std::cout << "Invalid patient file" << std::endl;
        return 0;
    }

    patient->loadGame(in);
    std::cout << "Patient loaded from " << filename << std::endl;
    return patient;
}
