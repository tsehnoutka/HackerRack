// HackerRank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Student {
	int age = 0;
	std::string first_name = "";
	std::string last_name = ""; 
	int standard = 0;
};


int main()
{
	Student myStudent;

	std::cin >> myStudent.age >> myStudent.first_name >> myStudent.last_name >> myStudent.standard;
	std::cout << myStudent.age << " " << myStudent.first_name << " " << myStudent.last_name << " " << myStudent.standard << std::endl;

}
