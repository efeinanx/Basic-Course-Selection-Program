#include "LanguageCourses.h"

int LanguageCourses::statEnrolled = 0;//INITIALIZING STATIC MEMBERS 
double LanguageCourses::statRate[]= {0.0};



//For constructing the related course infos 

LanguageCourses::LanguageCourses() {
    codediscount = "LAN30";
    enStudents = statEnrolled;
    name = "Language Course";
    instructor = "Fatih Kabadayý";
    totalCapacity = 5;
    price = 10000;
    level = 2;
    discount_rate = 0.7;
    prerequisites = "Spanish Dictionary\nBook";
    lang = "Spanish";
    bool native = false;
    courserates;


}

//If Capacity is not reached increase static enrolled student and object member enrolled student

void LanguageCourses::addStudent() {
    if (checkCapacity()) {
        cout << "Course is full!" << endl;
    }
    else {
        statEnrolled++;
        enStudents++;
    }


}



//Checking is capacity reached returns as boolean true or false

bool LanguageCourses::checkCapacity() const {
    if (enStudents < totalCapacity) {
        return false;
    }
    else {
        return true;
    }


}
//Displaying course infos 

void LanguageCourses::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Capacity: " << totalCapacity << endl;
    cout << "Enrolled students: " << enStudents << endl;
    cout << "Course Rate: " << courserates << endl;
    cout << "Price: " << price << endl;
    cout << "Level: " << level << endl;
    cout << "Discount Rate: " << discount_rate << endl;
    cout << "Prerequisites: " << prerequisites << endl;
    cout << "Language: \n" << lang << endl;

}

