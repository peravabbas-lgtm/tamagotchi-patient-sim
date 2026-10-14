#pragma once

class Patient;

void mainMenu();

// Prompts for a patient type and name; returns the new patient (caller owns it).
Patient* newPatient();

// Runs one treatment cycle: three decisions, then one year passes.
void treatment(Patient* patient);
