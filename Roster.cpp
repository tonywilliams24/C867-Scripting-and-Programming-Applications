/*
 * Roster.cpp
 *
 *  Created on: Mar 20, 2020
 *      Author: anthonywilliams
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include "NetworkStudent.h"
#include "degree.h"
#include "Roster.h"
using namespace std;



int main(){

	const string studentData[5] =
	 {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,Anthony,Williams,awi1508@student.wgu.edu,31,21,31,45,SOFTWARE"};

	cout << endl;
	cout << "Course Title: Scripting and Programming Applications - C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: 001064846" << endl;
	cout << "Name: Anthony Williams" << endl;
	cout << endl;

	Roster *classRoster = new Roster();

	for(int i=0; i < 5; i++){
		classRoster->parse(studentData[i]);
	}

	classRoster->printAll();

	classRoster->printInvalidEmails();

	for(int i=0; i <= classRoster->GetRosterIndex(); i++){
	classRoster->printAverageDaysInCourse(classRoster->GetclassRosterArray(i)->GetStudentID());
	}

	cout << endl;

	classRoster->printByDegreeProgram(SECURITY);

	classRoster->remove("A3");

	classRoster->remove("A3");

	classRoster->printAll();

	delete classRoster;

}
	Roster::Roster(){
		RosterIndex = -1;
		classRosterArray = new Student*[5];
	}
	Roster::~Roster(){
		for(int i = 0; i < RosterIndex; i++){
			delete classRosterArray[i];
		}
		delete classRosterArray;
	}

	void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree DegreeProgram){
		int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
		if(DegreeProgram == SECURITY){
			classRosterArray[RosterIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, DegreeProgram);
		}
		else if(DegreeProgram == NETWORK){
			classRosterArray[RosterIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, DegreeProgram);

		}
		else{
			classRosterArray[RosterIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, DegreeProgram);
		}

	}

	void Roster::parse(string studentDataI){
		string studentDataArray[9];
		Degree degreeType;
		RosterIndex++;
		int commaLeft = 0;
		for(int i = 0; i < 9; i++){
		int commaRight = studentDataI.find(",", commaLeft);
		studentDataArray[i] = studentDataI.substr(commaLeft, commaRight - commaLeft);
		commaLeft = commaRight + 1;
		}
		string studentID = studentDataArray[0];
		string firstName = studentDataArray[1];
		string lastName = studentDataArray[2];
		string emailAddress = studentDataArray[3];
		int age = stod(studentDataArray[4]);
		int daysInCourse1 = stod(studentDataArray[5]);
		int daysInCourse2 = stod(studentDataArray[6]);
		int daysInCourse3 = stod(studentDataArray[7]);
		if (studentDataArray[8] == "SECURITY"){
				degreeType = SECURITY;
		}
		else if (studentDataArray[8] == "NETWORK"){
				degreeType = NETWORK;
		}
		else{
				degreeType = SOFTWARE;
		}
		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeType);
	}

	void Roster::remove(string studentID){
		bool found = false;
		for(int i = 0; i <= RosterIndex; i++){
			string sID = classRosterArray[i]->GetStudentID();
			if(sID == studentID){
				int j = i;
				delete classRosterArray[i];
				while (j < RosterIndex){
					classRosterArray[j] = classRosterArray[j+1];
					j++;
				}
				RosterIndex--;
				found = true;

			}
		}
		if(found == false){
			cout << "Student with Student ID: " << studentID << " was NOT found!!!\n" << endl;
		}
	}

	void Roster::printAll(){
		for(int i = 0; i <= RosterIndex; i++){
			classRosterArray[i]->print();
		}
		cout << endl;
	}

	void Roster::printAverageDaysInCourse(string studentID){
		for(int i = 0; i <= RosterIndex; i++){
				string sID = classRosterArray[i]->GetStudentID();
				if(sID == studentID){
					double avg = ((double)classRosterArray[i]->GetDaysInCourse(0) + (double)classRosterArray[i]->GetDaysInCourse(1) + (double)classRosterArray[i]->GetDaysInCourse(2)) / 3;
					cout << "Average Days Per Course For Student " << studentID << " is " << setprecision(4) << avg << endl;
				}
		}
	}

	void Roster::printInvalidEmails(){
		for(int i = 0; i <= RosterIndex; i++){
				string sEmail = classRosterArray[i]->GetEmail();
				int foundAt = sEmail.find("@");
				int foundPeriod = sEmail.find(".");
				int foundSpace = sEmail.find(" ");
				if(foundAt == string::npos || foundPeriod == string::npos || foundSpace != string::npos){
					cout << "Invalid Email Address:\t" << classRosterArray[i]->GetStudentID() << "\t" << sEmail << endl;
				}
		}
		cout << endl;
	}

	void Roster::printByDegreeProgram(Degree degreeProgram){
		bool invalid = false;
		switch(degreeProgram){
		case SECURITY	:	cout << "Students with the Security Degree Program:" << endl;
							break;
		case NETWORK	:	cout << "Students with the Network Degree Program:" << endl;
							break;
		case SOFTWARE	:	cout << "Students with the Software Degree Program:" << endl;
							break;
		default 		:	cout << "Invalid Degree Program" << endl;
							invalid = true;
		}
		if (invalid != true) {

			for(int i = 0; i <= RosterIndex; i++){

			Degree dProgram = classRosterArray[i]->GetDegreeProgram();

			if(dProgram == degreeProgram) classRosterArray[i]->print();
			}
		}
		cout << endl;
	}
	int Roster::GetRosterIndex(){
		return RosterIndex;
	}

	Student * Roster::GetclassRosterArray(int x)
	{
		return classRosterArray[x];
	}
