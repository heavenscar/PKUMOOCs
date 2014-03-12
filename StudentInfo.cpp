#include <iostream>

class StudentInfo {
	// this class is designed to store students' info
	private:
		char * name;
		char * ID;
		int age;
		int first;
		int second;
		int third;
		int fourth;
		int Avergrade;

	public:
		StudentInfo(char * n, char * i, int a, int one, int two, int three, int four);
		char* getName() {
			return name;
		}
		char* getID() {
			return ID;
		}
		int getAge() {
			return age;
		}
		int getAverg() {
			return Avergrade;
		}
};

StudentInfo::StudentInfo(char * n, char * i, int a, int one, int two, int three, int four) {
	name = n; ID = i; age = a; first = one; second = two;
	third = three; fourth = four;
	Avergrade = (one + two + three + four) / 4;
}

int main() {
	char * name;
	char * ID;
	int age;
	int first;
	int second;
	int third;
	int fourth;
	char c;

	name = new char[20];
	ID = new char[20];

	std::cin.getline(name, 15, ',');
	std::cin >> age >> c;
	std::cin.getline(ID, 10, ',');
	std::cin >> first >> c >> second >> c >> third >> c >> fourth;

	StudentInfo student = StudentInfo(name, ID, age, first, second, third, fourth);

	std::cout << student.getName() << ',' << student.getAge() << ',' << student.getID() << ',' << student.getAverg();

	return 0;
}
