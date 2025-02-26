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



using namespace std;

class API {
    private:
        string ApiKeys =  "5fvfb65r4h5ht54dhvvFB54hth5hytKHB54551650";

    public:
        
        string getApiKeys() const;
        void APIStart();
};




#endif
