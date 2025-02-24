#include "Student.h" // implémentation de la classe Student
#include "Person.h"
#include <string>   // Pour std::string
#include <list>    // pour les lists
#include <vector>


using namespace std;


list<Student> Student::studentList;

int Student::nextID = 1;

Student::Student(string name, int age) : Person(name, age) {
    this->StudentID = nextID++;
    studentList.push_back(*this);
    this->gradesList = gradesList;
    
};


int Student::getStudentID() const {
    return  this->StudentID;
}

list<Student>& Student::getAllStudents() {
    return studentList;
}

Student* Student::getStudentById(int id) {
    for (auto& student : studentList) {
        if (student.getStudentID() == id) {
            return &student;
        }
    }
    return nullptr;
}



void Student::AddGrades(double grade) {
    gradesList.push_back(grade);
    cout << "Grade added: " << grade << " for student ID " << getStudentID() << endl;
}


const vector<float> Student::getAllGradesStudent() const {
    return gradesList;  
}




double Student::getAverageGrade() const {      //calcule la moyen des notes de l'éléves
    if (gradesList.empty()) {
        return 0.0;
    } else {
        double sumGrades;
        for (double g : gradesList) { 
            sumGrades += g;
        }
        
        return (sumGrades / gradesList.size());
        
    }
    
}

string Student::getStatus() const {
    return "Student";
};

void Student::printInfo() const {
    cout << "ID : " << getStudentID() << ", Student: " << getName() << ", Âge: " << getAge() << endl;
}

json Student::toJson() const {
    nlohmann::json j;

    
    j["Id"] = this->StudentID;
    j["Name"] = this->getName();
    j["Age"] = this->getAge();
    
    j["grades"] = gradesList;
    return j;
}

