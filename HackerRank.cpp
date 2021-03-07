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
	int n = 0;
	std::vector<Workshop> myWorkshops;
};
struct compare_start_time {
	inline bool operator() (const Workshop& lhs, const Workshop& rhs) {
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
	for (int x = 1; x < ptr->n - 1; x++) {
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