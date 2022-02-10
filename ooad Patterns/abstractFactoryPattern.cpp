#include<iostream>
using namespace std;
class Course {
public:
	virtual void printCourses() = 0;
};
class StudentCourses :public Course 
{
public:
	void printCourses() {
		cout << "These are Student courses in *STUDENT* CMS.\n";
	}
};
class TeacherCourses :public Course
{
public:
	void printCourses() {
		cout << "These are student courses in *TEACHER* CMS.\n";
	}
};


class Attendance {
public:
	virtual void printAttendance() = 0;
};
class StudentAttendance :public Attendance
{
public:
	void printAttendance() {
		cout << "This is Student attandance in *STUDENT* CMS.\n";
	}
};
class TeacherAttendance :public Attendance
{
public:
	void printAttendance() {
		cout << "This is student attandance in *TEACHER* CMS.\n";
	}
};


class Grades {
public:
	virtual void printGrades() = 0;
};
class StudentGrades :public Grades
{
public:
	void printGrades() {
		cout << "These are Student grades in *STUDENT* CMS.\n";
	}
};
class TeacherGrades :public Grades
{
public:
	void printGrades() {
		cout << "These are Student grades in *TEACHER* CMS.\n";
	}
};


//abstract factory
class CMS {
public:
	virtual Course* createCourses() = 0;
	virtual Attendance* createAttendance() = 0;
	virtual Grades* createGrades() = 0;
};
class StudentCMS : public CMS {
public:
	Course* createCourses() {
		return new StudentCourses();
	}
	Attendance* createAttendance() {
		return new StudentAttendance();
	}
	Grades* createGrades() {
		return new StudentGrades();
	}
	
};
class TeacherCMS : public CMS {
public:
	Course* createCourses() {
		return new TeacherCourses();
	}
	Attendance* createAttendance() {
		return new TeacherAttendance();
	}
	Grades* createGrades() {
		return new TeacherGrades();
	}

};


class Application {
private:
	Course* course;
	Attendance* attendance;
	Grades* grades;
public:
	Application(CMS* cms) {
		course = cms->createCourses();
		attendance = cms->createAttendance();
		grades = cms->createGrades();
	}
	void print() {
		course->printCourses();
		attendance->printAttendance();
		grades->printGrades();
	}
};

int main()
{
	cout << "Enter 1 for Student CMS...\n";
	cout << "Enter 2 for teacher CMS...\n";
	int choice;
	cin >> choice;
	CMS* cms;
	if (choice == 1) {
		cms = new StudentCMS();
		Application* app = new Application(cms);
		app->print();
	}
	else if (choice == 2) {
		cms = new TeacherCMS();
		Application* app = new Application(cms);
		app->print();
	}
	
	return 0;
}