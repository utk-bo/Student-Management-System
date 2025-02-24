# Version minimale de CMake
cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(StudentManagementSystem)

# Définir la norme C++ (par exemple, C++17)
set(CMAKE_CXX_STANDARD 17)

# Ajouter Crow à l'inclusion
include_directories(${PROJECT_SOURCE_DIR}/crow/include/)
include_directories(${PROJECT_SOURCE_DIR}/crow/include/crow)

include_directories(${PROJECT_SOURCE_DIR}/include_json/)



# Inclure le dossier avec les en-têtes de ton projet (par exemple, includes/)
include_directories(${PROJECT_SOURCE_DIR}/includes)

# Ajouter les fichiers source
add_executable(StudentManagementSystem
    src/main.cpp
    src/Course.cpp
    src/Enrollment.cpp
    src/Student.cpp
    src/UndergaduateStudent.cpp
    src/GraduateStudent.cpp
    src/Professor.cpp
    src/Person.cpp
    src/API.cpp
)


