// Student.h
#ifndef STUDENT_H  // assure que le préprocesseur n'insére pas plusieurs fois le header dans un seul fichier .cpp. c'est un garde / protection 
#define STUDENT_H

#include "Person.h"
#include <vector>

#include <string>   // Pour std::string
#include <list>    // pour les lists
#include <../include_json/json.hpp>

using json = nlohmann::json;


using namespace std;


class Student : public Person {
    private:
        int StudentID;
        static int nextID;
        double averageGrades;
        vector<float> gradesList;
        static list<Student> studentList;

    public:
        Student(string name, int age);     // constructeur pour crée un Objets étudiant

        int getStudentID() const;

        json toJson() const;
        
                              
        

        double getAverageGrade() const;         // methode qui devra retourner un type double qui sera la moyenne de toute les notes de la list "grades" de l'éleve

        const vector<float> getAllGradesStudent() const; 

        static Student* getStudentById(int id);

        static list<Student>& getAllStudents();

        void AddGrades(double grade);        // permettr d'ajouter une note a la liste des notes "grades" de l'éléve

        string getStatus() const override;

        void printInfo() const override;

};

#endif



