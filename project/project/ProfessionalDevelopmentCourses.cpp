#include "ProfessionalDevelopmentCourses.h"

int ProfessionalDevelopmentCourses::statEnrolled = 0; //INITIALIZING STATIC MEMBERS 
double ProfessionalDevelopmentCourses::statRate[20] = { 0, 0 };  
//For constructing the related course infos 

ProfessionalDevelopmentCourses::ProfessionalDevelopmentCourses() {
    name = "Professional Development Course";
    instructor = "Lucifer Michealson";
    totalCapacity = 7;
    price = 10000;
    discount_rate = 0.5;
    level = 1;
    prerequisites = "Confidence";
    topics = "How to be sigma";
    cert = true;
    enStudents = statEnrolled;
    codediscount = "PROF50";
    courserates;
}

//If Capacity is not reached increase static enrolled student and object member enrolled student

void ProfessionalDevelopmentCourses::addStudent() {
    if (checkCapacity()) {
        cout << "Course is full!" << endl;
    }
    else {
        statEnrolled++;
        enStudents++;
    }
}
//Checking is capacity reached returns as boolean true or false

bool ProfessionalDevelopmentCourses::checkCapacity() const {
    return enStudents >= totalCapacity;
}
//Displaying course infos 

void ProfessionalDevelopmentCourses::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Capacity: " << totalCapacity << endl;
    cout << "Enrolled students: " << enStudents << endl;
    cout << "Course Rate: " << courserates << endl;
    cout << "Price: " << price << endl;
    cout << "Level: " << level << endl;
    cout << "Discount Rate: " << discount_rate << endl;
    cout << "Prerequisites: " << prerequisites << endl;
    cout << "Topics: " << topics << endl;
}
