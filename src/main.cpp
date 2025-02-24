#include "API.h"
#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    


    // Créer quelques étudiants
    Student student1("Alice", 20);
    student1.AddGrades(15.0);
    student1.AddGrades(18.0);

    Student student2("Bob", 22);
    student2.AddGrades(12.0);
    student2.AddGrades(13.5);

    // Afficher les informations des étudiants
    for (const auto& student : Student::getAllStudents()) {
        student.printInfo();  // Affiche les infos de chaque étudiant
    }

    // Afficher les informations sous forme de JSON
    cout << "Student 1 JSON: " << student1.toJson().dump(4) << endl;
    cout << "Student 2 JSON: " << student2.toJson().dump(4) << endl;



    API();

    return 0;

}
