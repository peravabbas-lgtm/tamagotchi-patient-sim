#include "PatientThree.h"

PatientThree::PatientThree(const std::string& n) : Patient(n) {}

std::string PatientThree::getType() const { return "PatientThree"; }

void PatientThree::no_PPI() {
    stats.infLvl += 20;
    stats.vitLvl += 15;
    clampStats();
}

void PatientThree::live_bland() {
    stats.infLvl -= 15;
    stats.esoLvl += 15;
    stats.morLvl -= 20;
    clampStats();
}

void PatientThree::next_Year() {
    stats.vitLvl -= 5;
    stats.infLvl += 10;
    stats.esoLvl -= 5;
    stats.bpLvl -= 5;
    stats.morLvl -= 10;
    clampStats();
}
