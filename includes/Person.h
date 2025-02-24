#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

using namespace std;


class Person {
    private:
        string name;
        int age;
        

    public  :
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        };

        string getName() const;

        int getAge() const;
        
        virtual string getStatus() const = 0;

        virtual void printInfo() const = 0;
    

};
#endif