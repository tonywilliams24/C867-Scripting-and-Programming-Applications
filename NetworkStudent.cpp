/*
 * NetworkStudent.cpp
 *
 *  Created on: Mar 19, 2020
 *      Author: anthonywilliams
 */

#include "NetworkStudent.h"

#include "degree.h"

#include <iostream>

using namespace std;

NetworkStudent::NetworkStudent(string StudentIDc, string FirstNamec, string LastNamec, string Emailc, int Agec, int DaysInCoursec[], Degree Degreec)
 : Student(StudentIDc, FirstNamec, LastNamec, Emailc, Agec, DaysInCoursec){
	DegreeType = NETWORK;
}
NetworkStudent::NetworkStudent()
 : Student(){
	DegreeType = NETWORK;
}

Degree NetworkStudent::GetDegreeProgram(){
	return NETWORK;
}

NetworkStudent::~NetworkStudent(){
	Student::~Student();
}

void NetworkStudent::print(){
	Student::print();
	cout << "Degree Program: Network" << endl;
}


