#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"


using namespace std;
using std::string;


void Roster::parseToAdd(string studentData) {
	std::vector<string> input;
	DegreeProgram degreeProgram;
	for (int i = 0; i < 5; ++i) {
		std::stringstream ss(studentData);

		while (ss.good()) {
			string subStr;
			std::getline(ss, subStr, ',');
			input.push_back(subStr);
		}

		if (input[8] == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}
		if (input[8] == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORKS;
		}
		if (input[8] == "SOFTWARE") {
			degreeProgram = DegreeProgram::SOFTWARE;
		}
	}
	Roster::add(input.at(0), input.at(1), input.at(2), input.at(3), stoi(input.at(4)), stoi(input.at(5)),
		stoi(input.at(6)), stoi(input.at(7)), degreeProgram);
}




void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int CD1, int CD2, int CD3, DegreeProgram degreeProgram) {

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, CD1, CD2, CD3, degreeProgram);
}


void Roster::remove(string studentID) {
	std::cout << "Removing student record with student ID: " << studentID << "..." << std::flush;
	for (int k = 0; k < 5; ++k) {
		if (classRosterArray[k] == nullptr) {
			std::cout << "...Record does not exist!" << std::endl;
			break;
		}
		else if (studentID == classRosterArray[k]->Student::getStudentID()) {
			classRosterArray[k] = nullptr;
			std::cout << "Student record removed!" << std::endl;
		}
	}
}

void Roster::printAll() {
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->getStudentID() != "invlaid") {
			cout << "  ";
			classRosterArray[i]->print();
		}
	}
};

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int* day = classRosterArray[i]->getCourseDays();
			cout << "The average number of days to complete a course for " <<
				classRosterArray[i]->getFirstName() << " " <<
				classRosterArray[i]->getLastName() << " is: " <<
				((day[1] + day[2] + day[3]) / 3) << "." << endl;
		}
	}
};

void Roster::printInvalidEmails() {
	cout << endl << "\nPrint invalid emails: \n" << endl;
	for (int i = 0; i < 5; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		size_t atSign = email.find("@");
		size_t dot = email.find(".", atSign);

		if (atSign == string::npos) {
			cout << "Email address invalid. Email does not contain '@': " << email << endl;
		}
		else if (dot == string::npos) {
			cout << "Email address invalid. Email does not contain '.' after '@': " << email << endl;
		}
		else if (email.find(" ") != string::npos) {
			cout << "Email address invalid. Email cannot contain spaces: " << email << endl;
		}
	}

};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
};


Roster::~Roster() {
	delete[] * classRosterArray;
};