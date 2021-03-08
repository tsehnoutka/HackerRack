// HackerRank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

struct Workshops {
    //friend std::ostream& operator<<(std::ostream& os, const Workshops& obj);
    int start_time;
    int end_time;
    int duration;

    bool operator<(const Workshops& rhs) {
        return (this->end_time < rhs.end_time);
    }
};
/*
std::ostream& operator<<(std::ostream& os, const Workshops& obj) {
    os << obj.start_time << ": " << obj.end_time << ": "
        << obj.duration << "\n";
    return os;
}
*/
struct Available_Workshops {
    int n;
    std::vector<Workshops> vec;
};

Available_Workshops* initialize(int start_time[], int duration[], int num)
{
    Available_Workshops* avail = new Available_Workshops;
    avail->n = num;
    Workshops test;
    for (int i{ 0 }; i < num; i++) {
        test.start_time = start_time[i];
        test.duration = duration[i];
        test.end_time = start_time[i] + duration[i];
        avail->vec.push_back(test);
    }
    sort(avail->vec.begin(), avail->vec.end());
    return avail;
}

int CalculateMaxWorkshops(Available_Workshops* test) {
    int w_count = 1;
    int test_end_time = test->vec.at(0).end_time;
    for (int i{ 1 }; i < test->n; i++) {
        if (test_end_time <= test->vec.at(i).start_time) {
            w_count++;
            test_end_time = test->vec.at(i).end_time;
        }
    }
    return w_count;
}


int main(int argc, char* argv[]) {
	int n; // number of workshops
	std::cin >> n;
	// create arrays of unknown size n
	int* start_time = new int[n];
	int* duration = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> start_time[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> duration[i];
	}

	Available_Workshops* ptr;
	ptr = initialize(start_time, duration, n);
	int tim = CalculateMaxWorkshops(ptr);
	std::cout << tim << std::endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


