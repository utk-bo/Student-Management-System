#include <string>   // Pour std::string
#include <list>    // pour les lists

#include "Course.h"

using namespace std;



Course::Course(string courseCode, string courseName, int creditHours) {
    this->courseCode = courseCode;
    this->courseName = courseName;
    this->creditHours = creditHours;
}
