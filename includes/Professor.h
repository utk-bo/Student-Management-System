#ifndef PROFESSSOR_H
#define PROFESSOR_H

#include "Person.h"


#include <string>   // Pour std::string
#include <list>    // pour les lists

using namespace std;


class Professor : public Person {
    private:
        int professorID;
        static list <Professor> professorList;
       
    public:
        Professor(int professorID, string name, int age);

        int getProfessorID() const;
    
      

        string getStatus() const override;
        void printInfo() const override;
       
       
       
};





#endif