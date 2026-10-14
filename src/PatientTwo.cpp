#include "PatientTwo.h"

PatientTwo::PatientTwo(const std::string& n) : Patient(n) {}

std::string PatientTwo::getType() const { return "PatientTwo"; }

void PatientTwo::take_PPI() {
    stats.infLvl -= 15;
    stats.vitLvl -= 20;
    clampStats();
}

void PatientTwo::next_Year() {
    stats.vitLvl -= 10;
    stats.infLvl += 5;
    stats.esoLvl -= 5;
    stats.bpLvl -= 5;
    stats.morLvl -= 5;
    clampStats();
}
