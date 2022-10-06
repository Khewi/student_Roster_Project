#pragma once
#include "degree.h"
#include "student.h"

class Roster {


	static const unsigned int numStudents = 5;

public:

	//array of pointers
	Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	void parseToAdd(string record);


	void add(string studentID,
		string firstName,
		string lstName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);

	void remove(string studentID);

	void printAll();

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);


	//deconstructor
	~Roster();

private:
	int lastIndex = -1;

};