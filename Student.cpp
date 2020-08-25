/*
 * Student.cpp
 *
 *  Created on: Mar 16, 2020
 *      Author: anthonywilliams
 */

#include "Student.h"
#include "degree.h"
#include <iostream>
#include <string>

using namespace std;

	Student::Student(string StudentIDc,	string FirstNamec, string LastNamec, string Emailc, int Agec, int DaysInCoursec[])
	{
		this->StudentID = StudentIDc;
		this->FirstName = FirstNamec;
		this->LastName = LastNamec;
		this->Email = Emailc;
		this->Age = Agec;
	 	for (int i=0; i<3; i++) this->DaysInCourse[i] = DaysInCoursec[i];
}

	Student::Student()
	{
		this->StudentID = "";
		this->FirstName = "";
		this->LastName = "";
		this->Email = "";
		this->Age = 0;
		for (int i=0; i<3; i++) this->DaysInCourse[i] = 0;
	}

	Student::~Student(){
	}

	void 	Student::SetStudentID(string x){
			StudentID = x;
	}
	string 	Student::GetStudentID(){
			return StudentID;
	}

	void 	Student::SetFirstName(string x){
			FirstName = x;
	}

	string 	Student::GetFirstName(){
			return FirstName;
	}

	void 	Student::SetLastName(string x){
			LastName = x;
	}

	string 	Student::GetLastName(){
			return LastName;
	}

	void 	Student::SetEmail(string x){
			Email = x;
	}

	string	Student::GetEmail(){
			return Email;
	}

	void 	Student::SetAge(int x){
			Age = x;
	}
	int 	Student::GetAge(){
			return Age;
	}

	void 	Student::SetDaysInCourse(int x[]){
			for (int i=0; i<3; i++) DaysInCourse[i] = x[i];
	}
	double	Student::GetAverageDaysInCourse(){
			double avg = (DaysInCourse[0] + DaysInCourse[1] + DaysInCourse[2]) / 3;
			return avg;
	}
	int	Student::GetDaysInCourse(int x){
			return DaysInCourse[x];
	}



	void Student::print(){
		cout	<< GetStudentID() << "\t"
				<< "First Name: " << GetFirstName() << "\t"
				<< "Last Name: " << GetLastName() << "\t"
				<< "Email: " << GetEmail() << "\t"
				<< "Age: " << GetAge() << "\t"
				<< "daysInCourse: {" << GetDaysInCourse(0) << ", " << GetDaysInCourse(1) << ", " << GetDaysInCourse(2) << "} \t";
	}

	Degree Student::GetDegreeProgram(){}
