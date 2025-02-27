#include <string>   // Pour std::string
#include <list>    // pour les lists

#include "Professor.h"
#include "Student.h"
#include "Person.h"

#include "Course.h"

using namespace std;
list<Course> Course::courseList;
int Course::nextID = 0;         


Course::Course(string courseCode, string courseName, int creditHours) {
    this->courseId = nextID++;
    this->courseCode = courseCode;
    this->courseName = courseName;
    this->creditHours = creditHours;
    courseList.push_back(*this);
}


const Course* Course::getCourseById(int id) {
    for (auto& course : courseList) {
        if (course.getCourseID() == id) {
            return &course;
        }
    }
    return nullptr;
}

const Course* Course::getCourseByCode(const string& courseCode) {
    for (auto& course : courseList) {
        if (course.getCourseCode() == courseCode) {
            return &course;
        }
    }
    return nullptr; 
}


int Course::getCourseID() const {
    return courseId;
};

string Course::getCourseName() const {
    return this->courseName;
};
string Course::getCourseCode() const {
    return this->courseCode;
};
int Course::getCreditHours() const {
    return this->creditHours;
};

list<Course>& Course::getAllCourse() {
    return courseList;
}

void Course::enrollProfessor(const Professor& professor) {
    enrolledProfessorList.push_back(professor.getStatus());
}

list<string> Course::getEnrolledProfessor() const {

    return enrolledProfessorList;
};

void Course::enrollStudent(const Student& student) {
    enrolledStudentsList.push_back(student.getStatus());

};

list<string> Course::getEnrollerdStudents() const {
    return enrolledStudentsList;
}; 

json Course::toJson() const {
    nlohmann::json j;
    j["CourseId"] = this->getCourseID();
    j["course code"] = this->getCourseCode();
    j["Name"] = this->getCourseName();
    j["credit Hours"] = this->getCreditHours();
    
    vector<string> professors(enrolledProfessorList.begin(), enrolledProfessorList.end());

    vector<string> students(enrolledStudentsList.begin(), enrolledStudentsList.end());

    j["enrolled professor"] = professors;
    j["enrolled student"] = students;
    
    return j;
};


