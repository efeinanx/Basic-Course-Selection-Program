#ifndef CART_H
#define CART_H
#include "OnlineCourse.h"
#include "ProfessionalDevelopmentCourses.h"
#include "SoftwareCourses.h"
#include "InstrumentCourses.h"
#include "LanguageCourses.h"
#include <iostream>
using namespace std;


class Cart
{
private:
    int coursenumber = 0;
    bool islan=false, issoft=false, isprof=false, isns = false;  //Confirmation for is that courses added or not
    bool isconfirmed=false; //Confirmation for is cart confirmed?
    OnlineCourse* courses[3];  //The array which we keeping our courses with 
public:


     // integer for tracking how many course we added to cart


    //Function for adding course

    //Adding Course function
    void adding() {
        //First we checking if the cart is confirmed or not 
        if (isconfirmed == true) {

            cout << "You Can't add any course anymore because you confirmed the cart" << endl;
        }
        else {
            //We cant add course more than 3 thats why we are checking it with if else
            if (coursenumber < 3) {
                int ch; // Choice
                cout << "1 - Software Course" << endl;
                cout << "2 - Professional Development Course" << endl;
                cout << "3 - Instrument Course" << endl;
                cout << "4 - Language Course" << endl;
                cout << "5 - Quit Menu" << endl;
                cin >> ch;
                switch (ch) {
                case 1:
                    //If that course is not added than allocate that related course derived class into our base pointer array
                    if (issoft == false){
                        courses[coursenumber] = new SoftwareCourses();
                        issoft = true;
                        coursenumber++;
                }
            else { // if that course alreaddy added than create an error message
                        cout << "Software Course is already added" << endl;

            }
                    break;

                case 2:
                    //If that course is not added than allocate that related course derived class into our base pointer array

                    if (isprof == false) {
                        courses[coursenumber] = new ProfessionalDevelopmentCourses();
                        isprof = true;
                        coursenumber++;
                    }
                    else {
                        cout << "Professional Development Course is already added" << endl;

                    }
                    break;
                case 3:
                    //If that course is not added than allocate that related course derived class into our base pointer array

                    if (isns == false) {
                        courses[coursenumber] = new InstrumentCourses();
                        isns = true;
                        coursenumber++;

                    }
                    else {
                        cout << "Instrument Course is already added" << endl;

                    }
                    
                    break;
                case 4:
                    //If that course is not added than allocate that related course derived class into our base pointer array

                    if (islan == false) {
                        courses[coursenumber] = new LanguageCourses();
                        islan = true;
                        coursenumber++;
                    }
                    else {
                        cout << "Language Course is already added" << endl;

                    }
                    break;

                case 5:
                    //return to our main menu when user want 
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
                    break;
                }
            }
            //Course number shouldn't be bigger than 3 
            else {
                cout << "No more courses can be added to cart!" << endl;
            }
        }
    }




    //Calculating rate system
    //Template for work on all objects(language course,softwarecourses,etc...)
    template<typename T>
    void calculaterateCourse(T& obj) {
        double prRate, sum=0;
        cout << "\nRate This Course 1-5:  " << endl;
        cin >> prRate;
        if (prRate < 0 || prRate > 5) {
            cout << "You can't enter any number bigger than 5 or less than 1" << endl;

        }
        else {
            //Setting the static Rate array in related rate (index of array is enrolled student number)
            obj.setStatRate(prRate);

            //Calculate summation of all rates in class (not in object)
            for (int i = 0; i < obj.getEnStudents(); i++)
            {
                sum += obj.getStatRate(i);
            }
            if (obj.getEnStudents() > 0) {
                //setting course rates as summation of all rates / Enrolled Students in that object
                obj.setRate(sum / obj.getEnStudents());
            }
            else {
                cout << "No students enrolled to calculate rates." << endl;
            }
            cout << "\nNew Rates: " << obj.getRates()<<endl;

        }
        
    }
    
    void rateCourses(){
        //We cant rate courses if we didnt confirmed cart
           if (isconfirmed == true) {
               for (int i = 0; i < coursenumber; i++)
               {
                   cout << "Rate For " << courses[i]->getname();
                   calculaterateCourse(*courses[i]); //We can Rate the related object with template functions
               }
           }
           
           else {
               cout << "Firstly Confirm Your Cart!" << endl;

           }
    }
    //Removing Function
    void removing() {
        if (coursenumber == 0) { //If cart empty we cant remove any course
            cout << "Cart is empty, You cant remove any course" << endl;
        }
        //If its confirmed you cant remove any course anymore
        if (isconfirmed == true) {
            cout << "You Can't remove any course anymore because you confirmed the cart" << endl;

        }
        
        else {
            int x;
            for (int i = 0; i < coursenumber; i++)
                //Writing the course names and numbers
            {
                cout <<i<< "-" << courses[i]->getname() << endl;
            }


            cout << "Enter desired course to remove" << endl;
            cin >> x;

            //If user remove related course mark that course as unadded
            if (courses[x]->getname() == "Software Course") {
                issoft = false;

            }
            else if (courses[x]->getname() =="Language Course") {
                islan = false;

            }
            else if (courses[x]->getname() == "Professional Development Course") {
                isprof = false;

            }
            else if (courses[x]->getname() == "Instrument Course") {
                isns = false;

            }
            //Deallocating related course from our base array
            delete courses[x];
            //slide the course (when we delete the course it becomes empty)
            for (int i = x; i < coursenumber; i++)
            {
                courses[i] = courses[i + 1];
            }
            //decreasing the course number
            coursenumber--;
            cout << "Course removed successfully..." << endl;
        }
    }

    //Confirmation function
    void confirm(string a[]) { //That parameter is the address of array students confirmed courses
        if (isconfirmed == false) { // we can confirm only once
            double card, totalprice = 0, totaldiscountedprice = 0;


            //Printing the price of our undiscounted price
            for (int i = 0; i < coursenumber; i++)
            {
                totalprice += courses[i]->getPrice();
            }

            //Calculating the discounted and undiscounted prices
            for (int i = 0; i < coursenumber; i++)
            {
                totaldiscountedprice += courses[i]->getDiscountedprice();
            }
            cout << "Enrolled Courses: " << endl;
            //Printing the our course names in the cart  
            for (int i = 0; i < coursenumber; i++)
            {
                cout << "\n-" << courses[i]->getname() << endl;
            }

            //Printing the Prices and asking the user for payement infos
            cout << "Total Price is: " << totalprice << endl;
            cout << "Total Discounted Price is: " << totaldiscountedprice << endl;
            cout << "Enter Your Card Information:\n" <<"JUST NUMBERS!" << endl;
            cin >> card;
            cout << "Payement is successfull...";
            //when payement is successfull adding student number in the course 
            for (int i = 0; i < coursenumber; i++)
            {
                courses[i]->addStudent();
            }
            //Mark the cart as confirmed 
            isconfirmed = true;

            //Send the confirmed courses to array of students confirmed courses
            for (int i = 0; i < coursenumber; i++)
            {
                a[coursenumber] = courses[i]->getname();
            }


            
        }
        //print an error if cart is already confirmed 
        else {
            cout << "Cart is already Confirmed";

        }
    }
     
    void enterdiscount(){

        for (int i = 0; i < coursenumber; i++)
        {
            if (courses[i]->cdiscount() == true) { //Firstly checking is user entered Discount code correct, if user entered than calculate from discounted price 
                double prPrice; 
                prPrice = makeDiscount(*courses[i]);
                courses[i]->setdiscountedPrice(prPrice); // setting the discounted price as discounted price if user entered code correctly 
            }
            else {
                cout << "INVALID CODE" << endl; //If code is not correct than set the discounted price as normal price 
                courses[i]->setdiscountedPrice(courses[i]->getPrice());
            }
        }


    }

     // Template for discount to calculate objects
    template<typename T>
    double makeDiscount(T& obj) {
        return obj.getPrice() * obj.getDiscount();

    }


    //Function for viewing the enrolled courses
    void view() {
        if (coursenumber == 0) {
            cout << "Cart is empty" << endl;
        }


        cout << "Enrolled Courses:" << endl;
        for (int i = 0; i < coursenumber; i++)
        {
            cout << "\n\n"<<i<< ".Course: ";
            cout << "\n" << *courses[i] << endl;

        }

    }
};
#endif