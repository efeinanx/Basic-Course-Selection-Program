#ifndef INSTRUMENTCOURSES_H
#define INSTRUMENTCOURSES_H


#include "OnlineCourse.h"


class InstrumentCourses :
    public OnlineCourse
{
private:
    static void setStatRate(double pr);
    static double statRate[20]; //static array for tracking students ratings about class
    static int statEnrolled; // Static variable for track total enrolled students (in class not in object)
    string insName; //instrunment name
    string songs;  //songs 
public:
    //Destructor 
    ~InstrumentCourses() {
        cout << "Destructor -Instrument Courses " << endl;
    }

    ////Default Constructor for initializing the infos 
    InstrumentCourses();
    // Override base class virtual functions

    void addStudent() override;
    bool checkCapacity() const override;
    void displayInfo() const override;


    //Operator overloading for output stream <<

    friend ostream& operator<<(ostream& output, InstrumentCourses& obj) {
        output << "\nName: " << obj.name << "\nInstructor: " << obj.instructor << "\nCapacity: " << obj.totalCapacity << "\nEnrolled Students: " << obj.enStudents << "\nCourse Rates: " << obj.courserates << "\nPrice: " << obj.price << "\nLevel: " << obj.level << "\nDiscount Rate: " << obj.discount_rate << "\nPrerequisites: " << obj.prerequisites << "\nInstrument Name: " << obj.insName << "\nSongs: " << obj.songs;

        return output;
    }
};
#endif