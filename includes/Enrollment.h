#ifndef ENROLL_H
#define ENROLL_H

#include <string>
#include <list>
#include "Course.h"
#include "Student.h"
#include "Professor.h"

class Enrollment {
    public:
        static void enrollStudentToCourse(Course& course, const Student& student);
        static void enrollProfessorToCourse(Course& course, const Professor& professor);
        static void RegisterStudentToCourse( Course& course, const Student& student);  //inscription d'un étudiant a un cours avec ces informations personelle
        static void RegisterProfessorToCourse( Course& course, const Professor& professor);  //inscription d'un étudiant a un cours avec ces informations personelle
    };

#endif 


