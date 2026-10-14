#pragma once

#include <iosfwd>
#include <string>

#include "Stats.h"

// Abstract base class for all patients. Derived classes override selected
// treatments / yearly changes to model different medical responses.
class Patient {
protected:
    std::string name;
    Stats stats;

    // Keeps every stat inside 0-100. Derived overrides must call this.
    void clampStats();

public:
    explicit Patient(const std::string& n = "unnamed");
    virtual ~Patient() {}

    virtual std::string getType() const = 0;

    // Treatments
    virtual void take_PPI();
    virtual void no_PPI();
    virtual void take_dil();
    virtual void no_dil();
    virtual void live_bland();
    virtual void live_live();

    // Advance the simulation by one year
    virtual void next_Year();

    // Display
    virtual void printStats() const;

    // Persistence (type is written separately by the save/load code)
    virtual void saveGame(std::ostream& out) const;
    virtual void loadGame(std::istream& in);

    // Status checks
    bool lowLevels() const;   // prints a warning, returns true if any stat is dangerous
    bool gameIsOver() const;  // prints the outcome, returns true if the patient is lost
};
