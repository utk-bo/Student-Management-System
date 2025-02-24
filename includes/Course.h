//Course.h
#ifndef COURSE_H
#define COURSE_H

#include <string>   // Pour std::string
#include <vector>    // pour les lists

#include "Student.h"    // composition ou association car ici on utilise la classe STUDENT
#include "Professor.h"  // composition ou association car ici on utilise la classe Professor

using namespace std;

class Course {
    private:
        string courseCode;
        string courseName;
        int creditHours;
        vector<Student> studentsList;   // plus léger que list et permet l'accés au valeur par index
        vector<Professor> professorList;  

    public:
        Course(string courseCode, string courseName, int creditHour);

        string getCourseName() {
            return this->courseName;
        };
        string getCourseCode() {
            return this->courseCode;
        };
        int getCreditHours() {
            return this->creditHours;
        };
        


        void enrollStudent(Student Student);         // ajoute un etudiant directement sans 
        vector<Student> getEnrollerdStudents();   // methode pour voir la list des étudiant du cours 
};


#endif