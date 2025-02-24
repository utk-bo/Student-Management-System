#include "Person.h"


#include <string>



using namespace std;



string Person::getName() const {
    return this->name;
};

int Person::getAge() const {
    return this->age;
};