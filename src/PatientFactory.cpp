#include "PatientFactory.h"

#include "PatientOne.h"
#include "PatientThree.h"
#include "PatientTwo.h"

Patient* createPatient(const std::string& type, const std::string& name) {
    if (type == "PatientOne") return new PatientOne(name);
    if (type == "PatientTwo") return new PatientTwo(name);
    if (type == "PatientThree") return new PatientThree(name);
    return nullptr;
}
