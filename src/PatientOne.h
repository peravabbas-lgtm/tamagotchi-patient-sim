#pragma once

#include "Patient.h"

// Loses more esophageal function when diltiazem is withheld.
class PatientOne : public Patient {
public:
    explicit PatientOne(const std::string& n = "Patient One");

    std::string getType() const override;
    void no_dil() override;
    void next_Year() override;
};
