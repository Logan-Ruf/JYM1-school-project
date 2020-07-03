//
//  student.hpp
//  JYM1
//
//  Created by Logan Ruf on 6/5/20.
//  Copyright © 2020 Logan Ruf. All rights reserved.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "degree.hpp"

using namespace std;

class Student {
    public:
        void   SetStudentID(string studentID);
        string GetStudentID();
        void   SetFirstName(string firstName);
        string GetFirstName();
        void   SetLastName(string lastName);
        string GetLastName();
        void   SetEmail(string emailAddress);
        string GetEmail();
        void   SetAge(int studentAge);
        int    GetAge();
        void   SetDaysToComplete(int daysToComplete[3]);
        int *  GetDaysToComplete();
        void   SetDegreeProgram(DegreeProgram degreeProgram);
        DegreeProgram GetDegreeProgram();
        ~Student();
    
        void Print();
    
        Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysToComplete[3],
                DegreeProgram degreeProgram);

    private:
        string studID, fName, lName, emailAddr;
        int age;
        int days[3];
        DegreeProgram program;

};

#endif /* student_hpp */
