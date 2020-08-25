/*
 * SoftwareStudent.h
 *
 *  Created on: Mar 19, 2020
 *      Author: anthonywilliams
 */

#ifndef SOFTWARESTUDENT_H_
#define SOFTWARESTUDENT_H_
#include "Student.h"
#include "degree.h"

#include <iostream>

using namespace std;


	class SoftwareStudent : public Student {
		public:
		SoftwareStudent(string StudentIDc,	string FirstNamec, string LastNamec, string Emailc, int Agec, int daysInCourse[], Degree degreeTypec);
		SoftwareStudent();
		~SoftwareStudent();
		Degree GetDegreeProgram();
		void print();
		protected:
	};


#endif /* SOFTWARESTUDENT_H_ */
