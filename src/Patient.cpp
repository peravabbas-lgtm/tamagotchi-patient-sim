#include "Patient.h"

#include <iostream>

namespace {
int clampStat(int value) {
    if (value < 0) return 0;
    if (value > 100) return 100;
    return value;
}
}  // namespace

Patient::Patient(const std::string& n) {
    name = n;
    stats.vitLvl = 85;
    stats.infLvl = 15;
    stats.esoLvl = 85;
    stats.bpLvl = 85;
    stats.morLvl = 85;
}

void Patient::clampStats() {
    stats.vitLvl = clampStat(stats.vitLvl);
    stats.infLvl = clampStat(stats.infLvl);
    stats.esoLvl = clampStat(stats.esoLvl);
    stats.bpLvl = clampStat(stats.bpLvl);
    stats.morLvl = clampStat(stats.morLvl);
}

void Patient::take_PPI() {
    stats.infLvl -= 15;
    stats.vitLvl -= 15;
    clampStats();
}

void Patient::no_PPI() {
    stats.infLvl += 15;
    stats.vitLvl += 15;
    clampStats();
}

void Patient::take_dil() {
    stats.esoLvl += 15;
    stats.bpLvl -= 15;
    clampStats();
}

void Patient::no_dil() {
    stats.esoLvl -= 15;
    stats.bpLvl += 15;
    clampStats();
}

void Patient::live_bland() {
    stats.infLvl -= 15;
    stats.esoLvl += 15;
    stats.morLvl -= 15;
    clampStats();
}

void Patient::live_live() {
    stats.infLvl += 15;
    stats.esoLvl -= 15;
    stats.morLvl += 15;
    clampStats();
}

void Patient::next_Year() {
    stats.vitLvl -= 5;
    stats.infLvl += 5;
    stats.esoLvl -= 5;
    stats.bpLvl -= 5;
    stats.morLvl -= 5;
    clampStats();
}

void Patient::printStats() const {
    std::cout << name << "'s Status" << std::endl;
    std::cout << "Vitamin Level: " << stats.vitLvl << std::endl;
    std::cout << "Inflammation Level: " << stats.infLvl << std::endl;
    std::cout << "Esophageal Function Level: " << stats.esoLvl << std::endl;
    std::cout << "Blood Pressure Level: " << stats.bpLvl << std::endl;
    std::cout << "Morale Level: " << stats.morLvl << std::endl;
}

void Patient::saveGame(std::ostream& out) const {
    out << name << std::endl;
    out << stats.vitLvl << " " << stats.infLvl << " " << stats.esoLvl << " "
        << stats.bpLvl << " " << stats.morLvl << std::endl;
}

void Patient::loadGame(std::istream& in) {
    std::getline(in, name);
    in >> stats.vitLvl >> stats.infLvl >> stats.esoLvl >> stats.bpLvl >> stats.morLvl;
    in.ignore(10000, '\n');
    clampStats();
}

bool Patient::lowLevels() const {
    if (stats.vitLvl <= 25) {
        std::cout << name << " has low vitamin levels!" << std::endl;
        return true;
    }
    if (stats.infLvl >= 75) {
        std::cout << name << " has high inflammation levels!" << std::endl;
        return true;
    }
    if (stats.esoLvl <= 25) {
        std::cout << name << " has low esophageal function levels!" << std::endl;
        return true;
    }
    if (stats.bpLvl <= 25) {
        std::cout << name << " has low blood pressure levels!" << std::endl;
        return true;
    }
    if (stats.morLvl <= 25) {
        std::cout << name << " has low morale levels!" << std::endl;
        return true;
    }
    return false;
}

bool Patient::gameIsOver() const {
    const char* outcome = 0;

    if (stats.vitLvl <= 0) {
        outcome = " suffered hypovitaminosis, game over!";
    } else if (stats.infLvl >= 100) {
        outcome = " contracted stomach cancer, game over!";
    } else if (stats.esoLvl <= 0) {
        outcome = " experienced respiratory failure, game over!";
    } else if (stats.bpLvl <= 0) {
        outcome = "'s organs failed, game over!";
    } else if (stats.morLvl <= 0) {
        outcome = " now has severe depression, game over!";
    }

    if (outcome == 0) {
        return false;
    }

    std::cout << name << outcome << std::endl;
    std::cout << name << " has been taken out of your care" << std::endl;
    return true;
}
