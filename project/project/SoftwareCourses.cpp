#include "SoftwareCourses.h"
#include "SoftwareCourses.h"

int SoftwareCourses::statEnrolled = 0;//INITIALIZING STATIC MEMBERS 
double SoftwareCourses::statRate[] = {0.0};



//For constructing the related course infos 
SoftwareCourses::SoftwareCourses() {
    codediscount = "SOFT10";
    name = "Software Course";
    instructor = "Naresh Kisore";
    totalCapacity = 6;
    enStudents = statEnrolled;
    price = 5000;
    level = 4;
    discount_rate = 0.9;
    prerequisites = "Computer";
    progLanguage = "Python";
    devEnvironment = "Linux";
    courserates;
}



//Checking is capacity reached returns as boolean true or false
bool SoftwareCourses::checkCapacity() const {
    return enStudents >= totalCapacity;
}



//If Capacity is not reached increase static enrolled student and object member enrolled student
void SoftwareCourses::addStudent() {
    if (checkCapacity()) {
        cout << "Course is full!" << endl;

    }
    else {
        enStudents++;
        statEnrolled++;
        
    }
}

//Displaying course infos 
void SoftwareCourses::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Capacity: " << totalCapacity << endl;
    cout << "Enrolled students: " << enStudents << endl;
    cout << "Course Rate: " << courserates << endl;
    cout << "Price: " << price << endl;
    cout << "Level: " << level << endl;
    cout << "Discount Rate: " << discount_rate << endl;
    cout << "Prerequisites: " << prerequisites << endl;
    cout << "Programming Language: " << progLanguage << endl;
    cout << "Development Environment: \n" << devEnvironment << endl;
}
