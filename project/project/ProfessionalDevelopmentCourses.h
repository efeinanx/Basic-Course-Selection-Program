#ifndef PROFESSIONALDEVELOPMENTCOURSES_H
#define PROFESSIONALDEVELOPMENTCOURSES_H


#include "OnlineCourse.h"



class ProfessionalDevelopmentCourses :
    public OnlineCourse
{
private:
    static double statRate[20];  //static array for tracking students ratings about class

    static int statEnrolled;// Static variable for track total enrolled students (in class not in object)
    bool cert;
    string topics;
public:

    ~ProfessionalDevelopmentCourses() {
        cout << "Destructor -Professional Development Courses: "<< endl;
    }

    ProfessionalDevelopmentCourses();
    void addStudent() override;
    bool checkCapacity() const override;

    void displayInfo() const override;

    friend ostream& operator<<(ostream& output, ProfessionalDevelopmentCourses& obj) {
        output << "\nName: " << obj.name << "\nInstructor: " << obj.instructor << "\nCapacity: " << obj.totalCapacity << "\nEnrolled Students: " << obj.enStudents << "\nCourse Rates: " << obj.courserates << "\nPrice: " << obj.price << "\nLevel: " << obj.level << "\nDiscount Rate: " << obj.discount_rate << "\nPrerequisites: " << obj.prerequisites << "\nIs Certificated: " << obj.cert << "\nTopics: " << obj.topics;

        return output;
    }
};

#endif