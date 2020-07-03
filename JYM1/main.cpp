//
//  main.cpp
//  JYM1
//
//  Created by Logan Ruf on 6/5/20.
//  Copyright © 2020 Logan Ruf. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

//#include "degree.hpp"
#include "student.hpp"
#include "roster.hpp"

int main() {

    cout << "------------------------------------------------------------------" << endl;
    cout << "Course: Scripting and Programming  - Applications    Language: C++" << endl;
    cout << "Student ID: 001118367              Author: Christopher 'Logan' Ruf" << endl;
    cout << "------------------------------------------------------------------" << endl << endl;

    //Declare string arry size *ARRAY IS NOT CONSTANT ONLY PASS BY CONST REFERENCE*
    string studentData[5];
    //Declare individual indexes of array
    studentData[0] = "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY";
    studentData[1] = "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK";
    studentData[2] = "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE";
    studentData[3] = "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY";
    studentData[4] = "A5,Logan,Ruf,cruf3@wgu.edu,22,14,40,28,SOFTWARE";
    
    //Create Class Roster object and pass through student data array
    Roster studentRoster(studentData, 5);
    
    cout << "Student Roster:" << endl;
    cout << "---------------" << endl;
    studentRoster.printAll();
    cout << endl;
    
    cout << "Invalid Emails:" << endl;
    cout << "---------------" << endl;
    studentRoster.printInvalidEmails();
    cout << endl;
    
    cout << "Software Students:" << endl;
    cout << "------------------" << endl;
    studentRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    studentRoster.remove("A3");
    
    cout << "Student Roster:" << endl;
    cout << "---------------" << endl;
    studentRoster.printAll();
    cout << endl;
    
    studentRoster.remove("A3");
    
    return 0;
}
