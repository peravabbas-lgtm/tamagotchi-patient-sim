#pragma once

#include <string>

class Patient;

// Creates the derived Patient matching `type` ("PatientOne", "PatientTwo",
// "PatientThree"). Returns nullptr for an unknown type. Caller owns the result.
Patient* createPatient(const std::string& type, const std::string& name);
