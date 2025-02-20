#include "crow.h"
#include "Student.h"

int main() {
    Student A(1, "Alice", 19);

    A.AddGrades(5.5);
    A.AddGrades(15.5);
    A.AddGrades(8.5);
    cout << "Moyenne de l'éléves : " << A.getAverageGrade() << endl;


    
}