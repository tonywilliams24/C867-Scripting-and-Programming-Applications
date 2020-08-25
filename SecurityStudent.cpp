/*
 * SecurityStudent.cpp
 *
 *  Created on: Mar 19, 2020
 *      Author: anthonywilliams
 */

#include "SecurityStudent.h"

#include "degree.h"

#include <iostream>

using namespace std;

SecurityStudent::SecurityStudent(string StudentIDc,	string FirstNamec, string LastNamec, string Emailc, int Agec, int DaysInCoursec[], Degree Degreec)
 : Student(StudentIDc, FirstNamec, LastNamec, Emailc, Agec,DaysInCoursec){
	DegreeType = SECURITY;
}
SecurityStudent::SecurityStudent()
 : Student(){
	DegreeType = SECURITY;
}

Degree SecurityStudent::GetDegreeProgram(){
	return SECURITY;
}

SecurityStudent::~SecurityStudent(){
	Student::~Student();
}

void SecurityStudent::print(){
	Student::print();
	cout << "Degree Program: Security" << endl;
}


