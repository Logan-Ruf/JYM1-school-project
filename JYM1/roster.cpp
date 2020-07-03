//
//  roster.cpp
//  JYM1
//
//  Created by Logan Ruf on 6/5/20.
//  Copyright © 2020 Logan Ruf. All rights reserved.
//

#include "roster.hpp"

Roster::Roster(string* studentArray, int studSize){
    //Assign Pointers for student data to roster array
    studentSize = studSize;
    studentRosterArray = new stringPtr[studentSize];
    for(int i = 0; i < studentSize; i++){
        studentRosterArray[i] = &studentArray[i];
        //cout << "Roster unit reference for index " << i << " is: " << studentRosterArray[i] << endl;
    }
    
    //Parse student data and create new student objects using it
    for(int i = 0; i < studentSize; i++){
        vector<string> tempV;
        tempV.clear();
        istringstream streamStud;
        streamStud.clear();
        streamStud.str(studentArray[i]);
        //Parse stream into vector using ',' delimiter
        while (streamStud.good()) {
            string subStream;
            getline(streamStud, subStream, ',');
            tempV.push_back(subStream);
        }
        //clean data and create new student object
        if (tempV.size() == 9) {
            DegreeProgram degreeTmp;
            if (tempV[8] == "SECURITY") {
                degreeTmp = SECURITY;
            }else if (tempV[8] == "NETWORK"){
                degreeTmp = NETWORK;
            }else{
                degreeTmp = SOFTWARE;
            }
            int age, days1, days2, days3;
            
            try {
                istringstream(tempV[4]) >> age;
                istringstream(tempV[5]) >> days1;
                istringstream(tempV[6]) >> days2;
                istringstream(tempV[7]) >> days3;

            } catch (...) {
                cout << "ERROR Parsing Data";
            }
            this->add(tempV[0], tempV[1], tempV[2], tempV[3], age, days1, days2, days3, degreeTmp);
        }else{
            cout << "DATA SIZE MISMATCH" << endl;
        }
    }
    
}

Roster::~Roster(){
    for(int i = 0; i < classRosterArray.size(); i++){
        delete classRosterArray[i];
    }
//    cout << "ROSTER DELETED" << endl;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    Student * tempStudent = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
    classRosterArray.push_back(tempStudent);
    return;
}

void Roster::remove(string studentID){
    for(int i = 0; i < classRosterArray.size(); i++){
        string tmpID = classRosterArray[i]->GetStudentID();
        if(tmpID == studentID){
            delete classRosterArray[i];
            classRosterArray.erase(classRosterArray.begin()+i);
            cout << "Student Removed" << endl << endl;
            return;
        }
    }
    cout << "No Matching Student ID Found" << endl << endl;
    return;
}

void Roster::printAll(){
    for(int i = 0; i < classRosterArray.size(); i++){        classRosterArray[i]->Print();
    }
    return;
}

void Roster::printAverageDaysInCourse(string studentID){
    studentPtr stud = this->findStudent(studentID);
    int * days = stud->GetDaysToComplete();
    double counter = 0;
    for(int i = 0; i < 3; i++){
        counter += days[i];
    }
    double avgDays = counter / 3;
    cout << "Average Days in Program: " << avgDays << endl;
}

studentPtr Roster::findStudent(string studentID){
    for(int i = 0; i < classRosterArray.size(); i++){
        if(classRosterArray[i]->GetStudentID() ==  studentID){
            return classRosterArray[i];
        }
    }
    return nullptr;
}

void Roster::printInvalidEmails(){
    for(int i = 0; i < classRosterArray.size(); i++){
        string tmpEmail = classRosterArray[i]->GetEmail();
        bool isValid = this->isValidEmail(tmpEmail);
        if (!isValid) {
            cout << tmpEmail << endl;
        }
    }
}

bool Roster::isValidEmail(string email){
    bool hasPeriod = false;
    bool hasAt = false;
    for(int i = 0; i < email.size(); i++){
        if(email[i] == ' '){
            return false;
        }
        else if (email[i] == '.'){
            hasPeriod = true;
        }
        else if (email[i] == '@'){
            hasAt = true;
        }
    }
    if(hasPeriod && hasAt){
        return true;
    }
    return false;
}

void Roster::printByDegreeProgram(DegreeProgram degree){
    string degreeKey[3] = {"SECURITY", "NETWORK", "SOFTWARE"};
    for(int i = 0; i < classRosterArray.size(); i++){
        DegreeProgram  tmpDegree = classRosterArray[i]->GetDegreeProgram();
        if (tmpDegree == degree) {
            classRosterArray[i]->Print();
        }
    }
}
