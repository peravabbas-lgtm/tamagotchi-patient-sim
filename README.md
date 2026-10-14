# Tamagotchi Patient Sim

A console-based hospital simulation written in C++. The player takes the role of a doctor at Trial & Error Hospital and makes treatment decisions for a virtual patient.

Each decision affects the patient's vitamin level, inflammation, esophageal function, blood pressure, and morale. The goal is to keep the patient stable for as long as possible while balancing the benefits and side effects of treatment.

## Features

- Admit and name a new patient
- Choose from three patient types
- Prescribe or withhold proton pump inhibitors
- Prescribe or withhold diltiazem
- Recommend a restricted or normal lifestyle
- Monitor five patient statistics
- Receive warnings when statistics reach dangerous levels
- Advance the simulation by one year after each treatment cycle
- Save patient data to a text file
- Load a previously saved patient
- End the simulation when a critical statistic reaches zero or inflammation reaches 100
- Validate menu input to prevent invalid selections

## Patient Statistics

Each patient is monitored using five statistics ranging from 0 to 100:

- **Vitamin Level:** the patient's nutritional condition
- **Inflammation Level:** the severity of inflammation
- **Esophageal Function:** how effectively the esophagus functions
- **Blood Pressure:** the patient's blood-pressure stability
- **Morale:** the patient's emotional condition

The program displays a warning when a statistic reaches a dangerous level (25 or below, or 75 or above for inflammation). The game ends when vitamin level, esophageal function, blood pressure, or morale reaches 0, or inflammation reaches 100.

## Patient Types

Each type responds differently to certain treatments and to the passage of time.

| Patient | Special behavior |
| ------- | ---------------- |
| **One** | Greater reduction in esophageal function when diltiazem is not prescribed |
| **Two** | Greater vitamin-level reduction when taking a proton pump inhibitor |
| **Three** | Greater inflammation when a proton pump inhibitor is not prescribed, and a larger morale decrease on a restricted lifestyle |

## Treatment Options

During each treatment cycle, the player makes three decisions:

1. Whether to prescribe a proton pump inhibitor
2. Whether to prescribe diltiazem
3. Whether to recommend a restricted or normal lifestyle

Each choice changes several patient statistics. After the treatment decisions are completed, one year passes and the patient's condition changes further.

## Project Structure

```
tamagotchi-patient-sim/
├── src/
│   ├── main.cpp            # entry point and main menu loop
│   ├── Game.h / .cpp       # menu text, admitting a patient, treatment cycle
│   ├── Input.h / .cpp      # validated integer input
│   ├── Stats.h             # the Stats struct
│   ├── Patient.h / .cpp    # abstract Patient base class
│   ├── PatientOne.h / .cpp
│   ├── PatientTwo.h / .cpp
│   ├── PatientThree.h / .cpp
│   ├── PatientFactory.h / .cpp  # creates the right derived Patient from a type name
│   └── SaveLoad.h / .cpp   # saving and loading patients
├── CMakeLists.txt
├── LICENSE
└── README.md
```

## Object-Oriented Design

- An abstract `Patient` base class
- Derived patient classes (`PatientOne`, `PatientTwo`, `PatientThree`)
- Inheritance, virtual functions, and function overriding
- Runtime polymorphism
- Encapsulation
- Dynamic memory allocation
- A `Stats` struct for grouping related data
- A small factory function (`createPatient`) used by both the new-patient menu and the loader

The `Patient` class defines the shared behaviors of all patients, while each derived class overrides selected functions to create different medical responses.

## Saving and Loading

The program can save the following information to a text file:

- Patient type
- Patient name
- Vitamin level, inflammation level, esophageal function, blood pressure, and morale

The patient type is stored first so the program can recreate the correct derived object when the save file is loaded. Save files are plain text; the `.gitignore` excludes files ending in `.sav`, so naming your saves like `sam.sav` keeps them out of the repository.

## How to Build and Run

### Using g++ (no CMake needed)

```
g++ -std=c++11 src/*.cpp -o patient_sim
./patient_sim          # on Windows: patient_sim.exe
```

### Using CMake

```
cmake -S . -B build
cmake --build build
./build/patient_sim    # on Windows: build\Debug\patient_sim.exe
```

## Playing

1. Enter your name.
2. From the menu, admit a new patient (option 1) or load a saved one (option 2).
3. Choose option 4 to administer a treatment and advance one year.
4. Use option 5 to check the patient's status and option 3 to save.
5. Keep the patient alive as long as you can.

## License

Released under the [MIT License](LICENSE).
