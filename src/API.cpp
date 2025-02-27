#include "crow.h"
#include "API.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "Enrollment.h"
#include <iostream>
#include <string>


extern crow::SimpleApp app;

json API::getHomemessage() const {
    return this->homemessage;
}

string API::getApiKeys() const {
    const char* apiKey = getenv("API_SECRET_KEY");
    if (apiKey != nullptr) {
        return string(apiKey);
    } else {
        return "";
    }
}

void API::APIStart() {
    CROW_ROUTE(app, "/api")([this](){
        auto response = crow::response(200);
        response.set_header("Content-Type", "application/json");
        response.write(getHomemessage().dump(1));
        return response;
        
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
        
        for (const Student& student : Student::getAllStudents()) {      //&Student est une références a students Éviter une copie de chaque student dans la boucle. // Empêcher la modification des Student dans la boucle.
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
