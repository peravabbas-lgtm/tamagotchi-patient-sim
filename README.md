# Tamagotchi Patient Sim

A console-based hospital simulation written in C++. The player takes the role of a doctor at Trial & Error Hospital and makes treatment decisions for a virtual patient.

Each decision affects the patient’s vitamin level, inflammation, esophageal function, blood pressure, and morale. The goal is to keep the patient stable for as long as possible while balancing the benefits and side effects of treatment.

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

- **Vitamin Level:** Represents the patient’s nutritional condition
- **Inflammation Level:** Represents the severity of inflammation
- **Esophageal Function:** Represents how effectively the esophagus functions
- **Blood Pressure:** Represents the patient’s blood-pressure stability
- **Morale:** Represents the patient’s emotional condition

The program displays a warning when a statistic reaches a dangerous level.

## Patient Types

The simulation contains three patient types. Each type responds differently to certain treatments and to the passage of time.

### Patient One

Patient One experiences a greater reduction in esophageal function when diltiazem is not prescribed.

### Patient Two

Patient Two experiences a greater vitamin-level reduction when taking a proton pump inhibitor.

### Patient Three

Patient Three experiences greater inflammation when a proton pump inhibitor is not prescribed and a larger morale decrease when following a restricted lifestyle.

## Treatment Options

During each treatment cycle, the player makes three decisions:

1. Whether to prescribe a proton pump inhibitor
2. Whether to prescribe diltiazem
3. Whether to recommend a restricted or normal lifestyle

Each choice changes several patient statistics. After the treatment decisions are completed, one year passes and the patient’s condition changes further.

## Object-Oriented Design

This project demonstrates several object-oriented programming concepts:

- An abstract `Patient` base class
- Derived patient classes
- Inheritance
- Virtual functions
- Function overriding
- Runtime polymorphism
- Encapsulation
- Dynamic memory allocation
- Structures for grouping related data

The `Patient` class defines the shared behaviors of all patients, while each derived class overrides selected functions to create different medical responses.

## Saving and Loading

The program can save the following information to a text file:

- Patient type
- Patient name
- Vitamin level
- Inflammation level
- Esophageal function
- Blood pressure
- Morale

The patient type is stored so that the program can recreate the correct derived object when the save file is loaded.

## How to Run

### Using g++

Compile the program:

```bash
g++ Source.cpp -o patient_sim
