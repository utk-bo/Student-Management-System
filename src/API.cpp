#include "crow.h"
#include "API.h"
#include "Student.h"
#include "Professor.h"
#include <iostream>

void API() {

    crow::SimpleApp app;  
    Student A("papete", 19);
    Student B("Ali", 19);
    Student C("ice", 19);
    
    A.AddGrades(10.0);
    A.AddGrades(5.5);
    A.AddGrades(15.5);
    A.AddGrades(8.5);

    B.AddGrades(12.0);
    B.AddGrades(14.5);

    C.AddGrades(9.0);
    C.AddGrades(7.5);

    Professor Z(1, "patate", 35);


    CROW_ROUTE(app, "/api")([](){
        return "bienvenue dans mon api";  
    });

    CROW_ROUTE(app, "/api/students/<int>").methods("GET"_method)([] (int id) {
        auto student = Student::getStudentById(id);

        
      
        return crow::response(student->toJson().dump(5));
        
    });

    CROW_ROUTE(app, "/api/students")([](){
        nlohmann::json students_json;
    
        for (auto& student : Student::getAllStudents()) {
            students_json.push_back(student.toJson());
        }
        
        // Ajout d'un log pour vérifier l'état de la réponse JSON avant de l'envoyer
        std::cout << "Sending students data: " << students_json.dump(4) << std::endl;
    
        return crow::response(students_json.dump());
    });
    
    
   
    app.port(18080).multithreaded().run();  
   
}

/*
✔ POST /students – Create a new student.
✔ POST /courses – Create a new course.
✔ POST /enrollments – Enroll a student in a course.
✔ GET /students/{id} – Retrieve a student’s details.
✔ GET /courses/{id} – Retrieve course details including enrolled students.
*/
