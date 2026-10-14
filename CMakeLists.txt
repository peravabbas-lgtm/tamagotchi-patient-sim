cmake_minimum_required(VERSION 3.10)
project(TamagotchiPatientSim CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(patient_sim
    src/main.cpp
    src/Game.cpp
    src/Input.cpp
    src/Patient.cpp
    src/PatientOne.cpp
    src/PatientTwo.cpp
    src/PatientThree.cpp
    src/PatientFactory.cpp
    src/SaveLoad.cpp
)

if(MSVC)
    target_compile_options(patient_sim PRIVATE /W4)
else()
    target_compile_options(patient_sim PRIVATE -Wall -Wextra)
endif()
