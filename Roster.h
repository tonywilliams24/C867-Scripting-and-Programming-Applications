/*
 * Roster.h
 *
 *  Created on: Mar 20, 2020
 *      Author: anthonywilliams
 */

#ifndef ROSTER_H_
#define ROSTER_H_

class Roster {
	public:
	Roster();
	~Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree DegreeProgram);
	void parse(string studentDataI);
	void printAll();
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);
	int GetRosterIndex();
	Student * GetclassRosterArray(int x);


	private:

	int RosterIndex;
	Student** classRosterArray;

};

#endif /* ROSTER_H_ */
