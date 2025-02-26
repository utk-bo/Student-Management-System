#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <vector>
#include <string>
#include <list>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

class Student : public Person {   // inherit from class Person
private:
    int StudentID;
    static int nextID;
    vector<float> gradesList;  
    static list<Student> studentList;   

public:
    Student(string name, int age, vector<float> gradesList); // Constructor for new Student Objects

    int getStudentID() const;

    json toJson() const;    

    double getAverageGrade() const;

    static list<Student>& getAllStudents();  // return a list of all student

    static Student* getStudentById(int id);

    void AddGrades(float grade);    
   
    const vector<float>& getAllGradesStudent(const Student& student);  // Return const ref to grades
    ///////////Methode requierd inherit from Person class
    string getStatus() const override;
    void printInfo() const override;
};

#endif
