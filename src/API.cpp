#include "crow.h"
#include "API.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "Enrollment.h"
#include <iostream>
#include <string>


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
            
            
            curl -X GET http://localhost:8080/api

            curl -X GET http://localhost:8080/api/students

            curl -X GET http://localhost18080/api/professors

            curl -X GET http://localhost:8080/api/courses

            curl -X GET http://localhost:8080/api/students/{id}

            curl -X GET http://localhost:8080/api/professors/{id}

            curl -X GET http://localhost:8080/api/courses/{id}

            curl -X POST -H "ApiKey: YOUR_SECRET_KEY_1" -d '{"Name": "Dr. Smith", "age": 45}' http://localhost:8080/api/professors

            curl -X POST -H "ApiKey: YOUR_SECRET_KEY_1" -d '{"Name": "John Doe", "age": 20, "grades": [85.5, 90.0, 88.0]}' http://localhost:8080/api/students

            curl -X POST -H "ApiKey: YOUR_SECRET_KEY_1" -d '{"courseCode": "CS101", "courseName": "Introduction to Computer Science", "creditHours": 3}' http://localhost:8080/api/courses

            curl -X POST -H "ApiKey: YOUR_SECRET_KEY_1" -d '{"who": "Student", "courseCode": "CS101", "name": "John Doe", "age": 20}' http://localhost:8080/api/enroll

            curl -X POST -H "ApiKey: YOUR_SECRET_KEY_1" -d '{"who": "Professor", "courseCode": "CS101", "name": "Dr. Smith", "age": 45}' http://localhost:8080/api/enroll

        )";
    });
    
    

    CROW_ROUTE(app, "/api/students/<int>").methods("GET"_method)([this](int id) {
        Student* student = Student::getStudentById(id);
        if (!student) {
            return crow::response(404, "no course with this id");
        }
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(student->toJson().dump(4));
        return response;
    });

    CROW_ROUTE(app, "/api/students").methods("GET"_method)([](){

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
        Professor* prof = Professor::getProfessorById(id);
        if (!prof) {
            return crow::response(404, "no course with this id");
        }
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(prof->toJson().dump(4));
        return response;
    });

    CROW_ROUTE(app, "/api/professors").methods("GET"_method)([](){
        nlohmann::json professor_json;
        
        for (const auto& prof : Professor::getAllProfessor()) {    
            professor_json.push_back(prof.toJson());
        }
    
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(professor_json.dump(4));  
        return response;
    });

    CROW_ROUTE(app, "/api/professors").methods("POST"_method)([this](const crow::request& req) {
        auto apikey = req.get_header_value("ApiKey");
        if (apikey != getApiKeys()) {
            return crow::response(403, "Forbidden: Invalid API Key");
        }

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
        Course* course = Course::getCourseById(id);
        if (!course) {
            return crow::response(404, "no course with this id");
        }
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(course->toJson().dump(4));
        return response;
    });

    CROW_ROUTE(app, "/api/courses").methods("GET"_method)([](){
        nlohmann::json courses_json;
        
        for (const auto& course : Course::getAllCourse()) {    
            courses_json.push_back(course.toJson());
        }
    
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(courses_json.dump(4));  
        return response;
    });
    
    CROW_ROUTE(app, "/api/courses").methods("POST"_method)([this](const crow::request& req) {
        auto apikey = req.get_header_value("ApiKey");
        if (apikey != getApiKeys()) {
            return crow::response(403, "Forbidden: Invalid API Key");
        }
   
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
    CROW_ROUTE(app, "/api/enroll").methods("POST"_method)([this](const crow::request& req) {

        
        
        auto apikey = req.get_header_value("ApiKey");
        if (apikey != getApiKeys()) {
            return crow::response(403, "Forbidden: Invalid API Key");
        }
        
        
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
