//
//  roster.hpp
//  JYM1
//
//  Created by Logan Ruf on 6/5/20.
//  Copyright © 2020 Logan Ruf. All rights reserved.
//

#ifndef roster_hpp
#define roster_hpp

#include "student.hpp"
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include "degree.hpp"


using namespace std;

typedef string * stringPtr;
typedef Student * studentPtr;

class Roster{

private:
    stringPtr *studentRosterArray;
    int studentSize;
    vector<studentPtr> classRosterArray;

    studentPtr findStudent(string studentID);
    
    bool isValidEmail(string email);
    
public:
    
    
    Roster(string* studentArray, int studSize); //declare classRosterArray inside of constructor when data is available
    ~Roster();
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    //Sets of instance variables for student objects
    void remove(string studentID);
    //Removes students by studentID
    void printAll();
    //prints tab separated list of all student data
    void printAverageDaysInCourse(string studentID);
    //prints a students average number of days in 3 courses
    void printInvalidEmails();
    //verifies student emails and prints invalid emails
    void printByDegreeProgram(DegreeProgram degree);
    //prints all student information for a degree program
};


#endif /* roster_hpp */
