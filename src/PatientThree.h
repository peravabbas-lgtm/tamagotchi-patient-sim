#pragma once

#include "Patient.h"

// More inflammation without a PPI, bigger morale drop on a restricted lifestyle.
class PatientThree : public Patient {
public:
    explicit PatientThree(const std::string& n = "Patient Three");

    std::string getType() const override;
    void no_PPI() override;
    void live_bland() override;
    void next_Year() override;
};
