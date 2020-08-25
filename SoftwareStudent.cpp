/*
 * SoftwareStudent.cpp
 *
 *  Created on: Mar 19, 2020
 *      Author: anthonywilliams
 */

#include "SoftwareStudent.h"

#include "degree.h"

#include <iostream>

using namespace std;

SoftwareStudent::SoftwareStudent(string StudentIDc,	string FirstNamec, string LastNamec, string Emailc, int Agec, int DaysInCoursec[], Degree Degreec)
 : Student(StudentIDc, FirstNamec, LastNamec, Emailc, Agec,DaysInCoursec){
	DegreeType = SOFTWARE;
}
SoftwareStudent::SoftwareStudent()
 : Student(){
	DegreeType = SOFTWARE;
}

Degree SoftwareStudent::GetDegreeProgram(){
	return SOFTWARE;
}

SoftwareStudent::~SoftwareStudent(){
	Student::~Student();
}

void SoftwareStudent::print(){
	Student::print();
	cout << "Degree Program: Software" << endl;
}


