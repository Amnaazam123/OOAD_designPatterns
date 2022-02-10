#include<iostream>
#include<Windows.h>
#include<exception>
using namespace std;
class HOD final{
private:
	static HOD* hod;
public:
	string value;
	HOD(string value) {
		try {
			Sleep(100);
		}
		catch (exception& e) {
			e.what();
		}
		this->value = value;
	}
	static HOD* getHOD(string value) {
		if (hod==NULL) {
			hod = new HOD(value);
		}
		return hod;
	}
};
HOD* HOD::hod = NULL;
int main() 
{
	cout << "Two HODs are created but they are instantiated once.\n";
	HOD* hod1 = HOD::getHOD("Sir Murtaza Yousaf");
	HOD* hod2 = HOD::getHOD("Sir Fareed Ul Hassan Baig");
	cout << hod1->value << "\n";
	cout << hod2->value << "\n";
	return 0;
}