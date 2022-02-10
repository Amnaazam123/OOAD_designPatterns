/*
This is Teacher-Student CMS example.
Respective CMS will be displayed and visited by student and teacher.
Here CMS creator class is CMSdashboard which will either contains student CMS or teacher CMS in it.
*/

#include<iostream>
using namespace std;

class CMS {
public:
	virtual void display() = 0;
	virtual void onVisit() = 0;
};
/*Student CMS implementation.*/
class StudentCMS : public CMS {
	void display() {
		cout << "\nThis is Student CMS.\n";
		onVisit();
	}

	void onVisit() {
		cout << "\nVisit! StudentCMS says - 'Hello fellow, Welcome to your CMS'\n";
	}
};
/*Teacher CMS implementation.*/
class TeacherCMS : public CMS
{
	void display()
	{
		cout << "\nThis is Teacher CMS.\n";
		onVisit();
	}
	void onVisit()
	{
		cout << "\nVisit! TeacherCMS says - 'Hello Teacher, Welcome to your CMS'\n";
	}
};
//Creator for CMS
class CMSdashBoard
{
public:
	virtual CMS* createCMS() = 0;
	void renderTeacher()
	{
		CMS* cms = createCMS();
		cms->display();
	}
};
/*Student CMS dashboard will show student cms.*/
class StudentCMSDashBoard : public CMSdashBoard
{
public:
	CMS* createCMS() {
		return new StudentCMS();
	}
};
/* Teacher cms dashboard will show teacher CMS. */
class TeacherCMSDashBoard : public CMSdashBoard {
public:
	CMS* createCMS() {
		return new TeacherCMS();
	}
};

int main() {
	CMSdashBoard* dashboard=NULL;
	int choice;
	cout << "Enter 1 for student CMS\n";
	cout << "Enter 2 for teacher CMS\n";
	cout << "Enter choice: ";
	cin >> choice;
	if (choice == 1)
	{
		StudentCMSDashBoard Tcms;
		dashboard = &Tcms;
	}
	else if (choice == 2)
	{
		TeacherCMSDashBoard Scms;
		dashboard = &Scms;
	}
	dashboard->renderTeacher();
	return 0;
}


