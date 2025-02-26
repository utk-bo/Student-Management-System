#include "Student.h"  // implement Student class
#include "Person.h"    // implement Person class
#include <string>
#include <list>
#include <vector>
#include <nlohmann/json.hpp>      // librairy for json data 

using namespace std;

list<Student> Student::studentList;

int Student::nextID = 0;         // counter for studentID

Student::Student(string name, int age, vector<float> gradesList) : Person(name, age), gradesList(gradesList) {
    this->StudentID = nextID++;
    studentList.push_back(*this);
}

int Student::getStudentID() const {
    return  this->StudentID;
}

list<Student>& Student::getAllStudents() {
    return studentList;
}

const vector<float>& Student::getAllGradesStudent(const Student& student) {
    return student.gradesList;
}

Student* Student::getStudentById(int id) {
    for (auto& student : studentList) {
        if (student.getStudentID() == id) {
            return &student;
        }
    }
    return nullptr;
}

void Student::AddGrades(float grade) {
    gradesList.push_back(grade);
    
}

double Student::getAverageGrade() const {
    if (gradesList.empty()) {
        return 0.0;
    } else {
        double sumGrades = 0;
        for (double g : gradesList) {
            sumGrades += g;
        }
        double average = sumGrades / gradesList.size();
        return round(average * 100) / 100;  
    }
}

string Student::getStatus() const {
    return (getName() + ",  " +  to_string(getAge()) + "years old,"+ " ,Id : " + to_string(getStudentID()));
}

void Student::printInfo() const {
    cout << "ID : " << getStudentID() << ", Student: " << getName() << ", Age: " << getAge() << endl;
}

json Student::toJson() const {
    nlohmann::json j;
    j["StudentId"] = this->getStudentID();
    j["Name"] = this->getName();
    j["age"] = this->getAge();
    j["averageGrade"] = this->getAverageGrade();
    j["grades"] = this->gradesList;
    
    return j;
}
