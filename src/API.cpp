#include "crow.h"
#include "API.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "Enrollment.h"
#include <iostream>
#include <string>

using namespace std;

extern crow::SimpleApp app;

string API::getApiKeys() const {
    return ApiKeys;
};

void API::APIStart() {
    CROW_ROUTE(app, "/api")([](){
        return R"(
            Bienvenue dans mon API
    
            GET :
            /api/students/<int>  -> Récupérer les informations d'un étudiant par son ID
            /api/students        -> Récupérer la liste de tous les étudiants
            /api/professors/<int> -> Récupérer les informations d'un professeur par son ID
            /api/professors      -> Récupérer la liste de tous les professeurs
            /api/courses/<int>   -> Récupérer les informations d'un cours par son ID
            /api/courses         -> Récupérer la liste de tous les cours
    
            POST :
            /api/students        -> Ajouter un étudiant -> {Name: <Nom>, Age: <age>, Grades: [<double>, <double>]}
            /api/professors      -> Ajouter un professeur -> {Name: <Nom>, Age: <age>}
            /api/courses         -> Ajouter un cours -> {courseCode: "<Code du cours>", courseName: "<Nom du cours>", creditHours: <Nombre de crédits>}
            /api/enrollments     -> Enregistrer un étudiant ou un professeur à un cours -> {"who": "Professor" or "Student", "courseCode": "<CourseCode>", "name": "<Name>", "age": "<Age>"}
        )";
    });
    
    

    CROW_ROUTE(app, "/api/students/<int>").methods("GET"_method)([this](int id) {
        Student* student = Student::getStudentById(id);
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(student->toJson().dump(4));
        return response;
    });

    CROW_ROUTE(app, "/api/students")([](){

        nlohmann::json students_json;
        
        for (const auto& student : Student::getAllStudents()) {    
            students_json.push_back(student.toJson());
        }
    
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(students_json.dump(4));  
        return response;
    });

    CROW_ROUTE(app, "/api/students").methods("POST"_method)([this](const crow::request& req) {
        auto apikey = req.get_header_value("ApiKey");
        if (apikey != getApiKeys()) {
            return crow::response(403, "Forbidden: Invalid API Key");
        }
        auto data = crow::json::load(req.body);
    
        string name = data["Name"].s();
        int age = data["age"].i();
        vector<float> grades;


        if (!data) {
            return crow::response(400);  // invalid request 
        }
    
    
        for (const auto& grade : data["grades"]) {
            grades.push_back(grade.d());
        }
        
    
        Student new_student(name, age, grades);
    
    
        return crow::response(201, "201 student created successfully!");
    });
    
    CROW_ROUTE(app, "/api/professors/<int>").methods("GET"_method)([] (int id) {
        auto prof = Professor::getProfessorById(id);
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(prof->toJson().dump(4));
        return response;
    });

    CROW_ROUTE(app, "/api/professors")([](){
        nlohmann::json professor_json;
        
        for (const auto& prof : Professor::getAllProfessor()) {    
            professor_json.push_back(prof.toJson());
        }
    
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(professor_json.dump(4));  
        return response;
    });

    CROW_ROUTE(app, "/api/professors").methods("POST"_method)([](const crow::request& req) {

        auto data = crow::json::load(req.body);
      
        string name = data["Name"].s();
        int age = data["age"].i();
       

        if (!data) {
            return crow::response(400);  // 
        }
        
    
        Professor new_professor(name, age);
    
        
        return crow::response(201, "201 Found !");
    });


    CROW_ROUTE(app, "/api/courses/<int>").methods("GET"_method)([] (int id) {
        auto student = Course::getCourseById(id);
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(student->toJson().dump(4));
        return response;
    });

    CROW_ROUTE(app, "/api/courses")([](){
        nlohmann::json courses_json;
        
        for (const auto& course : Course::getAllCourse()) {    
            courses_json.push_back(course.toJson());
        }
    
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(courses_json.dump(4));  
        return response;
    });
    
    CROW_ROUTE(app, "/api/courses").methods("POST"_method)([](const crow::request& req) {
   
        auto data = crow::json::load(req.body);
        
      
        if (!data) {
            return crow::response(400, "Requête invalide. JSON manquant ou mal formaté.");
        }
        
     
        string courseCode = data["courseCode"].s();  
        string courseName = data["courseName"].s(); 
        int creditHours = data["creditHours"].i();  
   
        Course new_course(courseCode, courseName, creditHours);
        

        return crow::response(201, "Cours ajouté avec succès.");
    });


    /////////////////////////////////////// enroll student or professor //////////////////////////////////////
    CROW_ROUTE(app, "/api/enroll").methods("POST"_method)([](const crow::request& req) {
        auto data = crow::json::load(req.body);
        if (!data) {
            return crow::response(400);
        }
    
        string who = data["who"].s(); 
        string courseCode = data["courseCode"].s(); 
        string name = data["name"].s();
        int age = data["age"].i();
    
     
        Course* course = Course::getCourseByCode(courseCode);
        if (!course) {
            return crow::response(404);
        }
    
       
        if (who == "Student") {
          
            Student student(name, age, {});
            Enrollment::enrollStudentToCourse(*course, student);
            return crow::response(201, "Student added successfully");
        } else if (who == "Professor") {
           
            Professor professor(name, age);
            Enrollment::enrollProfessorToCourse(*course, professor);
            return crow::response(201, "Professor added successfully");
        } else {
            return crow::response(400, "your who is unknown try again with <Professor> or <Student>");
        }
    
        
    });
      
   
}


/*
✔ POST /students – Create a new student.            ✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔
✔ POST /courses – Create a new course.               ✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔
✔ POST /enrollments – Enroll a student in a course.   ✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔
✔ GET /students/{id} – Retrieve a student’s details.   ✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔
✔ GET /courses/{id} – Retrieve course details including enrolled students.  ✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔
*/
