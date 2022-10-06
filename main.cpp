#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <cstring>

using std::string;



int main() {
	int numStudents = 5;

	//student print out information
	cout << "----------------------------------" << endl;
	cout << "Course: C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "WGU Student ID: 010254612" << endl;
	cout << "Student Name: Katelyn Hewitt" << endl;
	cout << endl;

	//creating class roster
	Roster classRoster;


	//student data to parse in function below
	const string studentData[] =
	{
			"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Katelyn,Hewitt,khewi299@wgu.edu,25,30,32,28,SOFTWARE"
	};

	//function to parse student strings from studentData
	for (int i = 0; i < numStudents; i++) {
		classRoster.parseToAdd(studentData[i]);
	}

	//function to print all of the students added from the above code
	cout << "----------------------------------" << endl;
	cout << "Displaying all students:" << endl;
	classRoster.printAll();
	cout << endl;

	//function to print out all of the invalid emails 
	cout << "----------------------------------" << endl;
	cout << "Displaing invalid emails in classRoster:" << endl;
	classRoster.printInvalidEmails();
	cout << endl;


//function to print students by degree program
	cout << "----------------------------------" << endl;
	cout << "Printing student information by degree program:" << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;


	//function to display average course duration for each student
	cout << "----------------------------------" << endl;
	cout << "Average length of course duration for each student: " << endl;

	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->Student::getStudentID());
	}
	cout << endl;

	//function to remove student ID "A3"
	classRoster.remove("A3");
	cout << endl;

	//Function to display current roster to show student was deleted
	cout << "Displaying all students: \n" << endl;
	classRoster.printAll();
	cout << endl;


	//function to call error on student deleted
	classRoster.remove("A3");
	cout << endl;

	//function to call roster destructor
	classRoster.~Roster();

	return 0;
}