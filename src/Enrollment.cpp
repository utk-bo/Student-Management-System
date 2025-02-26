#include <string>   // Pour std::string
#include <list>    // pour les lists


using namespace std;


#include "Enrollment.h"
#include "Course.h"
#include "Student.h"
#include "Professor.h"

void Enrollment::enrollStudentToCourse(Course& course, const Student& student) {
   
    course.enrollStudent(student);
}

// Ajoute un professeur à un cours
void Enrollment::enrollProfessorToCourse(Course& course, const Professor& professor) {
   
    course.enrollProfessor(professor);
}
