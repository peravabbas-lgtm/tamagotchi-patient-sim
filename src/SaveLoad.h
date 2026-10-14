#pragma once

class Patient;

// Prompts for a filename and writes the patient (type first) to it.
void saveToFile(const Patient* patient);

// Prompts for a filename and rebuilds the saved patient.
// Returns nullptr if the file can't be opened or has an unknown patient type.
Patient* loadPatient();
