#include "PatientOne.h"

PatientOne::PatientOne(const std::string& n) : Patient(n) {}

std::string PatientOne::getType() const { return "PatientOne"; }

void PatientOne::no_dil() {
    stats.esoLvl -= 20;
    stats.bpLvl += 15;
    clampStats();
}

void PatientOne::next_Year() {
    stats.vitLvl -= 5;
    stats.infLvl += 5;
    stats.esoLvl -= 10;
    stats.bpLvl -= 5;
    stats.morLvl -= 5;
    clampStats();
}
