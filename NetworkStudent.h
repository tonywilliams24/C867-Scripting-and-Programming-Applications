/*
 * NetworkStudent.h
 *
 *  Created on: Mar 19, 2020
 *      Author: anthonywilliams
 */

#ifndef NETWORKSTUDENT_H_
#define NETWORKSTUDENT_H_
#include "Student.h"
#include "degree.h"

#include <iostream>

using namespace std;


	class NetworkStudent : public Student {
		public:
		NetworkStudent(string StudentIDc,	string FirstNamec, string LastNamec, string Emailc, int Agec, int daysInCourse[], Degree degreeTypec);
		NetworkStudent();
		~NetworkStudent();
		Degree GetDegreeProgram();
		void print();
		protected:
	};


#endif /* NETWORKSTUDENT_H_ */
