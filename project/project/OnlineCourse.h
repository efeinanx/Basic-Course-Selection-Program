#ifndef ONLINECOURSE_H
#define ONLINECOURSE_H

#include <iostream>
#include <string>
using namespace std;


class OnlineCourse
{
protected:
    static double statRate[20];
    double discountedprice;
    string name;
    string instructor;
    int totalCapacity;
    int enStudents;
    double courserates;
    int price;
    int level;
    double discount_rate;
    string prerequisites;
    string codediscount;
public:
    OnlineCourse() {
        
        name = "";
        instructor = "";
        totalCapacity = 0;
        enStudents = 0;
        courserates=0;
        price = 0;
        level = 0;
        discount_rate = 0.0;
        prerequisites = "";
        discountedprice = 0;
    }
    // operator overloading of output stream
    friend ostream& operator<<(ostream& output, OnlineCourse& obj) {
        output << "\nName: " << obj.name << "\nInstructor: " << obj.instructor << "\nCapacity: " << obj.totalCapacity << "\nEnrolled Students: " << obj.enStudents << "\nCourse Rates: " << obj.courserates << "\nPrice: " << obj.price << "\nLevel: " << obj.level << "\nDiscount Rate: " << obj.discount_rate << "\nPrerequisites: " << obj.prerequisites;

        return output;
    }

       //checking discount function
    bool cdiscount() {
        string code;
        cout << "Enter discount code for " << name<<":" << endl;
        cin >> code;
        if (code == codediscount) {

            return true;
        }
        else {
            return false;
        }
    }
     //accessor for names enrolled students rates
    string getname() {


        return name;
    }
    int getEnStudents() {
        return enStudents;


   }
    //accessor for static rate (its in array thats why we have parameter)
    double getStatRate(int i) {
        return statRate[i];

    }

    int getPrice() {
        return price;

    }

    double getDiscount() {

        return discount_rate;
    }



    double getRates() {

        return courserates;
    }
    //mutuator for discounted price,static rates 
    void setRate(double pRATE) {


        courserates = pRATE;

    }
    void setStatRate(double pr); // declaration of stat rate


    void setdiscountedPrice(double prPrice) {
        discountedprice = prPrice;




    }

     

     double getDiscountedprice() {

         return discountedprice;
     }
     // pure virtual functions declaration
    virtual void displayInfo() const = 0;
    virtual void addStudent()=0;
    virtual bool checkCapacity() const = 0;
    virtual ~OnlineCourse() {}

};
#endif