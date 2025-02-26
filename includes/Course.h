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
        static int nextID; 
        int courseId;
        string courseName;
        string courseCode;
        int creditHours;

        static list<Course> courseList;
        list<string> enrolledStudentsList;   
        list<string> enrolledProfessorList;  

    public:
        Course(string courseCode, string courseName, int creditHour);

        int getCourseID() const;
        string getCourseName() const;
        string getCourseCode() const;
        int getCreditHours() const;

        static Course* getCourseByCode(const string& courseCode);

        static list<Course>& getAllCourse();

        json toJson() const;   

        static Course* getCourseById(int id);
        
        void enrollProfessor(const Professor& professor);         // ajoute un etudiant directement sans 

        list<string> getEnrolledProfessor() const;   // methode pour voir la list des étudiant du cours 

        void enrollStudent(const Student& Student);         // ajoute un etudiant directement sans 

        list<string> getEnrollerdStudents() const;   // methode pour voir la list des étudiant du cours 
};


#endif