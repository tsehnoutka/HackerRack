#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
private:

    string name;
    int age;
public:
    Person() :name(""), age(0) {
    }
    virtual void getdata() {
        std::cin >> name >> age;
    }
    virtual void putdata() {
        std::cout << name << " " << age << " ";
    }

};
class Professor : public Person {
private:
    static int id_num;
    int publications;
    int cur_id;
public:
    Professor() :publications(0), cur_id(0) {
        id_num++;
    }
    void getdata() {
        Person::getdata();
        std::cin >> publications;
        cur_id = id_num;
    }
    void putdata() {
        Person::putdata();
        std::cout << publications << " " << cur_id << std::endl;
    }
};
class Student : public Person {
private:
    static int id_num;
    const static int MAX_MARKS = 6;
    int marks[MAX_MARKS];
    int cur_id;
public:
    Student() {
        for (int x = 0; x < MAX_MARKS; x++)
            marks[x] = 0;
        cur_id = 0;
        id_num++;
    }
    void getdata() {
        Person::getdata();
        for (int x = 0; x < MAX_MARKS; x++)
            std::cin >> marks[x];
        cur_id = id_num;
    }
    void putdata() {
        Person::putdata();
        int total = 0;
        for (int x = 0; x < MAX_MARKS; x++)
            total += marks[x];
        std::cout << total << " " << cur_id << std::endl;;
    }
};
int Professor::id_num = 0;
int Student::id_num = 0;
int main() {
	Person* p = new Professor;
	p->getdata();
/*	int n, val;
	cin >> n; //The number of objects that is going to be created.
	Person* per[n];

	for (int i = 0; i < n; i++) {

		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.

	}

	for (int i = 0; i < n; i++)
		per[i]->putdata(); // Print the required output for each object.
*/
	return 0;

}
