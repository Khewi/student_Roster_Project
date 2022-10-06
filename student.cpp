#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
#include "student.h"

using std::string;
using std::cout;
using std::endl;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->courseDays == new int[3];
	this->degreeProgram = DegreeProgram::INVALID;
};



Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int CD1, int CD2, int CD3, DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->courseDays == new int[3];
	courseDays[0] = CD1;
	courseDays[1] = CD2;
	courseDays[2] = CD3;
	this->degreeProgram = degreeProgram;

}
//deconstructor
Student::~Student() {};

//accessors aka getters
string Student::getStudentID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmailAddress() {
	return this->emailAddress;
}

int Student::getAge() {
	return this->age;
}

int* Student::getCourseDays() {
	return this->courseDays;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

//mutattors aka setter
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
};

void Student::setFirstName(string firstName) {
	this->firstName = firstName;

};

void Student::setLastName(string lastName) {
	this->lastName = lastName;

};

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
};

void Student::setAge(int age) {
	this->age = age;
};

void Student::setCourseDays(int* CD) {
	courseDays[0] = CD[0];
	courseDays[1] = CD[1];
	courseDays[2] = CD[2];
	return;
};

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
};


void Student::printHeader() //displays header for student data
{
	cout << "Student Roster = Student ID | First Name | Last Name | Email | Age | Days In Course | Degree Program \n";
} 

void Student::print()  //displays the students data
{
	cout << this->getStudentID() << "\t";
	cout << this->getFirstName() << "\t";
	cout << this->getLastName() << "\t";
	cout << this->getEmailAddress() << "\t";
	cout << this->getAge() << "\t";
	cout << this->getCourseDays()[0] << "\t";
	cout << this->getCourseDays()[1] << "\t";
	cout << this->getCourseDays()[2] << "\t";
	cout << degreeTypeStings[this->getDegreeProgram()] << "\t\n";
};




