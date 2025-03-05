#ifndef STUDENT_H
#define STUDENT_H

#include "Cart.h"

class Student
{
public:
    
    //Mutuator functions for entering the infos 

    void setName(string prName) {
        studentName = prName;

    }
    void setSurname(string prSurname) {
        surname = prSurname;

    }
    void setMail(string prMail) {

        email = prMail;
    }


    //ACCESSING CART FUNCTIONS FOR MAIN FUNCTION (ITS NOT DIRECTLY ACCESSIBLE FROM MAIN)
    void cRate() {

        c.rateCourses();
    }

    void addCart() {
        c.adding();
    }
    void viewCart() {
        c.view();

    }
    void confirmCart() {

        c.confirm(&confirmedCourses[3]);  //STUDENT'S CONFIRMED COURSE ARRAY
    }

    void removeCart() {
        c.removing();
    }
    void cdiscount() {
        c.enterdiscount();

    }
    //Operator overloading for output stream
    friend ostream& operator<<(ostream& output, Student& obj) {
        output << "\nName: " << obj.studentName << "\nSurname: " << obj.surname << "\nStudent Email: " << obj.email;

        return output;
    }



private: //student infos 
    Cart c; //cart object of class

    string confirmedCourses[3];
    string studentName;
    string surname;
    string email;
    string enCourses[3];
};
#endif