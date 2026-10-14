#pragma once

#include "Patient.h"

// Loses more vitamin level when taking a proton pump inhibitor.
class PatientTwo : public Patient {
public:
    explicit PatientTwo(const std::string& n = "Patient Two");

    std::string getType() const override;
    void take_PPI() override;
    void next_Year() override;
};
