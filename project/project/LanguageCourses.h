#ifndef LANGUAGECOURSES_H
#define LANGUAGECOURSES_H



#include "OnlineCourse.h"


class LanguageCourses :
    public OnlineCourse
{
private:
    static double statRate[20];//static array for tracking students ratings about class
    static int statEnrolled; // Static variable for track total enrolled students (in class not in object)
    string lang; 
    bool native;
public:

    //Declaration of Static function to update course ratings array

    //DESTRUCTOR 
    ~LanguageCourses() {
        cout << "Destructor -Language Courses: " << endl;
    }
    //Default Constructor for initializing the infos 
    LanguageCourses();

    // Override base class virtual functions

    void addStudent() override;
    bool checkCapacity() const override;
    void displayInfo() const override;

    //Operator overloading for output stream <<
    friend ostream& operator<<(ostream& output, LanguageCourses& obj) {
        output << "\nName: " << obj.name << "\nInstructor: " << obj.instructor << "\nCapacity: " << obj.totalCapacity << "\nEnrolled Students: " << obj.enStudents << "\nCourse Rates: " << obj.courserates << "\nPrice: " << obj.price << "\nLevel: " << obj.level << "\nDiscount Rate: " << obj.discount_rate << "\nPrerequisites: " << obj.prerequisites << "\nLanguage: " << obj.lang << "\nIs native: " << obj.native;

        return output;
    }
};
#endif