#ifndef API_H
#define API_H
#include "crow.h"
#include "API.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "Enrollment.h"
#include <iostream>
#include <string>
#include <cstdlib> // Pour getenv




using namespace std;

class API {
    private:
       string getApiKeys() const;
       nlohmann::json homemessage = {
            {"Bienvenue dans mon API"}, 
            {"Voici les différentes routes de l'API. Attention, les requêtes POST nécessitent une clé API."},
            {"routes", {
                "/api",
                "/api/students",
                "/api/professors",
                "/api/courses",
                "/api/students/{id}",
                "/api/professors/{id}",
                "/api/courses/{id}"
            }},
            {"GET", {
                "/api/students/{id}", "Récupérer les informations d'un étudiant par son ID",
                "/api/students", "Récupérer la liste de tous les étudiants",
                "/api/professors/{id}", "Récupérer les informations d'un professeur par son ID",
                "/api/professors", "Récupérer la liste de tous les professeurs",
                "/api/courses/{id}", "Récupérer les informations d'un cours par son ID",
                "/api/courses", "Récupérer la liste de tous les cours"
            }},
            {"POST", {
                "/api/students", "Ajouter un étudiant -> {Name: <Nom>, Age: <age>, Grades: [<double>, <double>]}",
                "/api/professors", "Ajouter un professeur -> {Name: <Nom>, Age: <age>}",
                "/api/courses", "Ajouter un cours -> {courseCode: <Code du cours>, courseName: <Nom du cours>, creditHours: <Nombre de crédits>}",
                "/api/enroll", "Enregistrer un étudiant ou un professeur à un cours -> {\"who\": \"Professor\" or \"Student\", \"courseCode\": <CourseCode>, \"name\": <Name>, \"age\": <Age>}"
            }},
            
            {"curl_examples", {
                "GET /api", "curl -X GET http://localhost:8080/api",
                "GET /api/students", "curl -X GET http://localhost:8080/api/students",
                "GET /api/professors", "curl -X GET http://localhost:8080/api/professors",
                "GET /api/courses", "curl -X GET http://localhost:8080/api/courses",
                "GET /api/students/{id}", "curl -X GET http://localhost:8080/api/students/{id}",
                "GET /api/professors/{id}", "curl -X GET http://localhost:8080/api/professors/{id}",
                "GET /api/courses/{id}", "curl -X GET http://localhost:8080/api/courses/{id}",
                "POST /api/professors", "curl -X POST -H \"ApiKey: VOTRE_CLE_API\" -d '{\"Name\": \"Dr. Smith\", \"age\": 45}' http://localhost:8080/api/professors",
                "POST /api/students", "curl -X POST -H \"ApiKey: VOTRE_CLE_API\" -d '{\"Name\": \"John Doe\", \"age\": 20, \"grades\": [85.5, 90.0, 88.0]}' http://localhost:8080/api/students",
                "POST /api/courses", "curl -X POST -H \"ApiKey: VOTRE_CLE_API\" -d '{\"courseCode\": \"CS101\", \"courseName\": \"Introduction to Computer Science\", \"creditHours\": 3}' http://localhost:8080/api/courses",
                "POST /api/enroll (Student)", "curl -X POST -H \"ApiKey: VOTRE"
            }}
            
        };
        
    public:
        json getHomemessage() const;
        void APIStart();
};




#endif
