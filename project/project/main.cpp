#include "Student.h"
#include <iostream>
using namespace std;
#define MAXSTUDENT 50

int main() {


    //Student arr is created with MAXSTUDENT size
    Student s[MAXSTUDENT];

    //number of added students
    int studentCount = 0;
    int choice;
    int curstudent = -1; //Tracking the student count -1 means no student added now
    string prname, prsurname, prmail;
    //Infinity Loop 
    while (true) {
        //Printing the menu
        cout << "1. New Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Select Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Select Your Choice: ";
        cin >> choice; //Taking input

        switch (choice) {
        case 1: //If capacity is reached you cant create student anymore 
            if (studentCount == MAXSTUDENT) {
                cout << "No student can be added anymore" << endl;
                break;
            }
            //Taking inputs and setting the related members with Mutuator functions
            cout << "Enter name: ";
            cin >> prname;
            s[studentCount].setName(prname);

            cout << "Enter surname: ";
            cin >> prsurname;
            s[studentCount].setSurname(prsurname);

            cout << "Enter mail: ";
            cin >> prmail;
            s[studentCount].setMail(prmail);

            // After adding the new student, update the current student to new added student
            curstudent = studentCount;
            studentCount++; //increasing the student number 
            break;
                
        case 2: //Printing all students and infos with overloaded output operator
            for (int i = 0; i < studentCount; i++) {
                cout << i << ".th student: " << s[i] << endl;
            }
            break;

        case 3: // Setting Current student as selected student number for operating the related students courses
            cout << "Select number of student: ";
            int chStu;
            cin >> chStu;
            if (chStu >= 0 && chStu < studentCount) {
                curstudent = chStu;
            }
            else { // if there is no student in that choice print error 
                cout << "That student does not exist" << endl;
            }
            break;

        case 4: // Exit the program
            return 0;

        default: //If user enter any other command than printed commands print error
            cout << "Unknown Command" << endl;
        }


        //Loop for course operations 
        while (curstudent != -1) { //Enter Loop when a student selected
            cout << "\n1. Add Course" << endl;
            cout << "2. Remove Course" << endl;
            cout << "3. View Cart" << endl;
            cout << "4. Confirm Cart" << endl;
            cout << "5. Enter Discount Code" << endl;
            cout << "6. Rate Courses" << endl;
            cout << "7. Exit to main menu " << endl;
            cout << "Select Your Choice: ";
            cin >> choice;
            //Function calling in Student.h for selected choices
            switch (choice) {
            case 1:
                s[curstudent].addCart();
                break;

            case 2:
                s[curstudent].removeCart();
                break;

            case 3:
                s[curstudent].viewCart();
                break;

            case 4:
                s[curstudent].confirmCart();
                break;
            case 5:
                s[curstudent].cdiscount();
            case 6:
                s[curstudent].cRate();
            case 7:
                curstudent = -1;  // Exit to main menu
                break;

            default:
                cout << "No such command" << endl;
                break;
            }
        }
    }

    return 0;
}
