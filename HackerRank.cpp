// HackerRank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

struct Workshop {
	int start;
	int end;
	int duration;
};

struct Available_Workshops {
	int n=0;
	std::vector<Workshop> myWorkshops;
};
struct compare_start_time
{
	inline bool operator() (const Workshop&  lhs, const Workshop&  rhs)
	{
		return (lhs.start < rhs.start);
	}
};


Available_Workshops* initialize(int start_time[], int duration[], int n) {
	//   Creates an Available_Workshops object and initializes its elements using the 
	//   elements in the  and  parameters (both are of size ). Here,  and  are the 
	//   respective start time and duration for the  workshop. This function must 
	//   return a pointer to an Available_Workshops object.
	Available_Workshops* arrAvailableWorkshops = new Available_Workshops;
	arrAvailableWorkshops->n = n;
	for (int i = 0; i < n; i++) {
		Workshop tempWrkShp;
		tempWrkShp.start = start_time[i];
		tempWrkShp.end = start_time[i] + duration[i];
		tempWrkShp.duration = duration[i];
		arrAvailableWorkshops->myWorkshops.push_back(tempWrkShp);
	}
	std::sort(arrAvailableWorkshops->myWorkshops.begin(), arrAvailableWorkshops->myWorkshops.end(), compare_start_time());
	return arrAvailableWorkshops;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
	//   Returns the maximum number of workshops the student can attend—without 
	//   overlap. The next workshop cannot be attended until the previous workshop ends.
	int retval = 1; //  the number of workshops a person can attend

	if (ptr->n <= 0)
		return 0;

	int prevEndTime = ptr->myWorkshops[0].end;

	//loop through the workshops
	//  compare prevTotalTime to current start
	//  if prevTotalTime < current start time, they can attend the workshop
	for (int x = 1; x < ptr->n-1; x++) {
		if (prevEndTime <= ptr->myWorkshops[x].start)
			++retval;
		prevEndTime = ptr->myWorkshops[x].end;
	}

	return retval;
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


