#include "Professor.h"
#include "Person.h"

#include <string>   // Pour std::string

#include <iostream>


using namespace std;

list<Professor> Professor::professorList;


Professor::Professor(int professorID, string name, int age)
        : Person(name, age), professorID(professorID)
         {
            this->professorID += (professorList.size() + 1);
            professorList.push_back(*this);
        }


int Professor::getProfessorID() const {
    return  this->professorID;
}

        

string Professor::getStatus() const {
    return "Professor";
};

void Professor::printInfo() const {
    cout << "ID : " << getProfessorID() << " Professor: " << getName() << ", Âge: " << getAge() << endl;


};