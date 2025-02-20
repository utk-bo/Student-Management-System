#include "Student.h" // implémentation de la classe Student
#include <string>   // Pour std::string
#include <list>    // pour les lists


using namespace std;






Student::Student(int StudentID, string name, int age) {
    this->StudentID = StudentID;
    this->name = name;
    this->age = age;
    
};


void Student::AddGrades(double grade) { // permettr d'ajouter une note a la liste des notes "grades" de l'éléve
    grades.push_back(grade);
    
}      
double Student::getAverageGrade() {      //calcule la moyen des notes de l'éléves
    if (grades.empty()) {
        return 0.0;
    } else {
        double sumOFgrade;
        for (double grade : grades) {
            sumOFgrade += grade;
        }
        return (sumOFgrade / grades.size());
    }
}