#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include "Course.h"
#include "Student.h"

using namespace std;

class Enrollment {
    private:
        Student student;
        Course  course;
    public:
        Enrollment(Student student, Course cours);
        
        void Register(Student student, Course course);  //inscription d'un étudiant a un cours avec ces informations personelle

};


#endif