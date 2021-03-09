// HackerRank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

class Student {
private:
	int age = 0;
	std::string first_name = "";
	std::string last_name = "";
	int standard = 0;
public:
	int get_age() { return age; }
	std::string get_first_name() { return first_name; }
	std::string get_last_name() { return last_name; }
	int get_standard() { return standard;  }

	void set_age(const int a) { age = a;  }
	void set_first_name(const std::string fn) { first_name = fn; }
	void set_last_name(const std::string fn) { last_name = fn; }
	void set_standard(const int s) { standard = s; }

	std::string to_string() { return std::to_string(age) + "," + first_name + "," + last_name + "," + std::to_string(standard); }
};
int main()
{
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}


