/*
 * Student.h
 *
 *  Created on: Mar 16, 2020
 *      Author: anthonywilliams
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include "degree.h"

using namespace std;

class Student{
	public:

	Student(string StudentIDc,	string FirstNamec, string LastNamec, string Emailc, int Agec, int DaysInCourse[3]);
	Student();
	virtual ~Student();

	void 	SetStudentID(string x);
	string	GetStudentID();

	void 	SetAge(int x);
	int		GetAge();

	void 	SetDaysInCourse(int x[]);
	int		GetDaysInCourse(int x);
	double	GetAverageDaysInCourse();


	void 	SetFirstName(string x);
	string	GetFirstName();

	void 	SetLastName(string x);
	string 	GetLastName();

	void 	SetEmail(string x);
	string	GetEmail();

	void SetDegree(Degree x);

	virtual Degree GetDegreeProgram();
	virtual void print();

	protected:
	int Age;
	int DaysInCourse[3];
	string StudentID, FirstName, LastName, Email;
	Degree DegreeType;
};


#endif /* STUDENT_H_ */
