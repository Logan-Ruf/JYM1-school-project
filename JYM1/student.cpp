//
//  student.cpp
//  JYM1
//
//  Created by Logan Ruf on 6/5/20.
//  Copyright © 2020 Logan Ruf. All rights reserved.
//

#include "student.hpp"

using namespace std;

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int* daysToComplete,
                 DegreeProgram degreeProgram){
    studID = studentID;
    fName = firstName;
    lName = lastName;
    emailAddr = emailAddress;
    age = studentAge;
    for(int i = 0; i < 3; i++){
        days[i] = daysToComplete[i];
    };
    program = degreeProgram;
        
}

void Student::SetStudentID(string studentID){
    studID = studentID;
    return;
}

string Student::GetStudentID(){
    return studID;
}

void Student::SetFirstName(string firstName){
    fName = firstName;
    return;
}

string Student::GetFirstName(){
    return fName;
}

void Student::SetLastName(string lastName){
    lName = lastName;
    return;
}

string Student::GetLastName(){
    return lName;
}

void Student::SetEmail(string emailAddress){
    emailAddr = emailAddress;
    return;
}

string Student::GetEmail(){
    return emailAddr;
}

void Student::SetAge(int studentAge){
    age = studentAge;
    return;
}

int Student::GetAge(){
    return age;
}

DegreeProgram Student::GetDegreeProgram(){
    return program;
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram){
    program = degreeProgram;
    return;
}

void Student::SetDaysToComplete(int daysToComplete[3]){
    for(int i = 0; i < 3; i++){
        days[i] = daysToComplete[i];
    };
    return;
}

int * Student::GetDaysToComplete(){
    return days;
}

void Student::Print(){
    cout << "Student ID: " << studID << "    ";
    cout << "First: " << fName << "    ";
    cout << "Last: " << lName << "   ";
    cout << "Email: " << emailAddr << "   ";
    cout << "Age: " << age << "   ";
    cout << "Days to completion: " << days[0] << ", " << days[1] << ", " << days[2] << "   ";
    if (program == SECURITY) {
        cout << "Degree: Security" << endl;
    }else if (program == NETWORK){
        cout << "Degree: Network" << endl;
    }else{
        cout << "Degree: Software" << endl;
    }
}

Student::~Student(){
//    cout << studID << " DELETED" << endl;
}
