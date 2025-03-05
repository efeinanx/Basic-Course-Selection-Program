#ifndef SOFTWARECOURSES_H
#define SOFTWARECOURSES_H

#include "OnlineCourse.h"

class SoftwareCourses : public OnlineCourse {
private:
    static int statEnrolled; // Static variable for track total enrolled students (in class not in object)
    string progLanguage;
    string devEnvironment;

public:
    static void setStatRate(double pr);
    static double statRate[20]; //static array for tracking students ratings about class
    SoftwareCourses(); //Default Constructor for initializing the infos 
    // Override base class virtual functions
    

    //virtual functions overriding
    bool checkCapacity() const override;
    void addStudent() override;
    void displayInfo() const override;


    //Operator overloading for output stream <<

    friend ostream& operator<<(ostream& output, SoftwareCourses& obj);
    ~SoftwareCourses() {
        cout << "Destructor - Software Course: " << endl;
    }

};

#endif
