#include "OnlineCourse.h"
//INITIALIZING STATIC MEMBERS 
double OnlineCourse::statRate[20] = {0.0};

void OnlineCourse::setStatRate(double pr) { //For setting static rate array with the parameter of user prompted rate
    if (enStudents < 20) {
        statRate[enStudents] = pr;
        enStudents++;
    }
    else {
        cout << "Rate array is full!" << std::endl;
    }
}
 