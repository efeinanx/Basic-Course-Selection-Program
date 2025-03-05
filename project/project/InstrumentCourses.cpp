#include "InstrumentCourses.h"
int InstrumentCourses::statEnrolled = 0;//INITIALIZING STATIC MEMBERS 
double InstrumentCourses::statRate[] = { 0.0};



//For constructing the related course infos 

InstrumentCourses::InstrumentCourses() {

    name = "Instrument Course";
    instructor = "Neset ERTAS";
    codediscount = "INS50";
    totalCapacity = 10;
    enStudents = statEnrolled;
    price = 5000;
    level = 4;
    discount_rate = 0.5;
    prerequisites = "Baglama\n Music Book";
    insName = "Baglama";
    songs = "Bir ayrýlýk bir yoksulluk bir de olum\n Kesik Cayir";
    courserates;

}

//If Capacity is not reached increase static enrolled student and object member enrolled student

void InstrumentCourses::addStudent() {
    if (checkCapacity()) {
        cout << "Course is full!" << endl;
    }
    else {
        enStudents++;
        statEnrolled++;
    }



}

//Checking is capacity reached returns as boolean true or false


bool InstrumentCourses::checkCapacity() const {
    if (enStudents < totalCapacity) {
        return false;
    }
    else {
        return true;
    }


}

//Displaying course infos 

void InstrumentCourses::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Capacity: " << totalCapacity << endl;
    cout << "Enrolled students: " << enStudents << endl;
    cout << "Course Rate: " << courserates << endl;
    cout << "Price: " << price << endl;
    cout << "Level: " << level << endl;
    cout << "Discount Rate: " << discount_rate << endl;
    cout << "Prerequisites: " << prerequisites << endl;
    cout << "Instrument Name: " << insName << endl;
    cout << "Songs: \n" << songs << endl;


}