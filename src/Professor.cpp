#include "Professor.h"
#include "Person.h"

#include <nlohmann/json.hpp>      // librairy for json data 
#include <string>   // Pour std::string
#include <iostream>

using json = nlohmann::json;
using namespace std;

list<Professor> Professor::professorList;
int Professor::nextID = 0;         


Professor::Professor(string name, int age) : Person(name, age) {
    this->professorID = nextID++;
    professorList.push_back(*this);
}

list<Professor>& Professor::getAllProfessor() {
    return professorList;
}

int Professor::getProfessorID() const {
    return  this->professorID;
}

Professor* Professor::getProfessorById(int id) {
    for (auto& professor : professorList) {
        if (professor.getProfessorID() == id) {
            return &professor;
        }
    }
    return nullptr;
}

json Professor::toJson() const {
    nlohmann::json j;
    j["Id"] = this->getProfessorID();
    j["Name"] = this->getName();
    j["age"] = this->getAge();
    return j;
}

        

string Professor::getStatus() const {
    return (getName() + ",  " +  to_string(getAge()) + "years old,"+ " Id : " + to_string(getProfessorID()));
};

void Professor::printInfo() const {
    cout << "ID : " << getProfessorID() << " Professor: " << getName() << ", Âge: " << getAge() << endl;


};