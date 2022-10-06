#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;

class Student {
public:
	const static int numDays = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseDays[numDays];
	DegreeProgram degreeProgram;

public:
	//parameterless constructor to set defaults
	Student();
	//constructor for student class
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int CD1, int CD2, int CD3, DegreeProgram degreeProgram);

	//deconstructor for student class
	~Student();

	//accessors aka getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getCourseDays();
	DegreeProgram getDegreeProgram();

	//mutattors aka setter
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setCourseDays(int courseDays[]);
	void setDegreeProgram(DegreeProgram dp);


	static void printHeader(); //displays header for data

	void print(); //displays the students data

};