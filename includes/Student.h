// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>   // Pour std::string
#include <list>    // pour les lists


using namespace std;


class Student {
    private:
        int StudentID;
        string name;
        int age;
        list <double> grades; 

    public:
        Student(int StudentID, string name, int age);     // constructeur pour crée un Objets étudiant

        int getStudentID();
        string getName();
        int getAge();


        void AddGrades(double grade);        // permettr d'ajouter une note a la liste des notes "grades" de l'éléve
        double getAverageGrade();         // methode qui devra retourner un type double qui sera la moyenne de toute les notes de la list "grades" de l'éleve
        
};

#endif



