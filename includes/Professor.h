#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


#include <string>   // Pour std::string
#include <list>    // pour les lists

using namespace std;


class Professor : public Person {
    private:
        static int nextID;
        int professorID;
        static list<Professor> professorList;
       
    public:
        Professor(string name, int age);

        int getProfessorID() const;

        json toJson() const;   

        static list<Professor>& getAllProfessor();  // return a list of all professor

        static Professor* getProfessorById(int id);
    
      

        string getStatus() const override;
        void printInfo() const override;
       
       
       
};





#endif