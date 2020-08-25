/*
 * SecurityStudent.h
 *
 *  Created on: Mar 19, 2020
 *      Author: anthonywilliams
 */

#ifndef SECURITYSTUDENT_H_
#define SECURITYSTUDENT_H_
#include "Student.h"
#include "degree.h"

#include <iostream>

using namespace std;


	class SecurityStudent : public Student {
		public:
		SecurityStudent(string StudentIDc,	string FirstNamec, string LastNamec, string Emailc, int Agec, int daysInCourse[], Degree degreeTypec);
		SecurityStudent();
		~SecurityStudent();
		Degree GetDegreeProgram();
		void print();
		protected:
	};


#endif /* SECURITYSTUDENT_H_ */
